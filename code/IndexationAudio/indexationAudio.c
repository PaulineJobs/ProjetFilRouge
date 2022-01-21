#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include <dirent.h>
#include "indexationAudio.h"
#include "../Configuration/configuration.h"



//Verifie que le fichier est bien un fichier audio avant indexation
void VerifTypeFichierAudio(char *nomFichier){
    int j;
    if (strlen(nomFichier) > 4) {
       for (j = 0; nomFichier[j + 3]; j++) {         
          if (!strcmp(&nomFichier[j], ".bin")){
			 histogrammeAudio(nomFichier);
		 } 
       }
    }
}


//on cree l'histogramme du fichier audio
void histogrammeAudio(char* NomFichierParam){
	
	//variables
    FILE *fichierbin=NULL;
    long nbrValeurs;
    int **histogramme;
    double intervalleFrequence;
    int k;
    double valeurLue;
	char emplacement []="../../Corpus/AUDIO/";
	char *nomFichier=(char *)malloc(strlen(NomFichierParam)+1);
	
	//on va lire les paramètres dans la config
	int m = config("indexationAudioM");
	int n = config("indexationAudioN");

	//Vérification des valeurs de n et m dans le .config
	if(n<1 || n>30000 || m<1){ //note : on pourrait peut être faire un renvoi direct vers la methode de modification de la config ? (pas sur de ça, c'est un peu lourd jtrouve)
		fprintf(stderr, "\e[0;31m\n/!\\Attention /!\\\nLes valeurs n et/ou m de l'indexation audio sont mal configurées (<1 ou >30 000).\nMerci de modifier ces paramètres dans la configuration.\n\n\e[0mMise à jour avec des valeurs par défaut : n = 1024 et m = 100.\n\n");
		m = 100;
		n = 1024;
	}

    // ouvrir le fichier en lecture et avoir le nombre de valeurs
    fichierbin = fopen(strcat(emplacement,NomFichierParam),"rb");
  
    //on verifie l'existance et l'ouverture du fichier
     if (fichierbin!=NULL){
         
		//on va chercher le nombre de valeurs dans le fichier.bin
		//on divise le resultat par 8 car un double fait 8 octets
		fseek(fichierbin, 0, SEEK_END);	
		nbrValeurs=ftell(fichierbin)/8;
		fseek(fichierbin, 0,SEEK_SET);
		//printf("Nombre de valeurs du fichier bin : %d\n",nbrValeurs);

		//on determine le nombre d'intervalles k de n echantillons (on découpe l'axe des abscisses)
		k=(nbrValeurs/n)+1;
		//printf("k = : %d\n",k);
		
		//on calcule l'intevralle de frequence (on découpe l'axe des ordonnées)
		intervalleFrequence=(float)2/(float)m;
		//printf("m = : %d\n",m);
		
		//on alloue la matrice qui représente l' histogramme 
		histogramme=(int**)malloc(k*sizeof(int*));
		for (int i=0; i<k;i++){
			histogramme[i]=(int*)malloc(m*sizeof(int));
		}	
		//on verifie l'allocation
		if(histogramme==NULL){
			printf("ERREUR: Impossible d'indexer ce fichier\n");

		
		} else {
				//on initialise l'histogramme à zero
				for (int i=0; i<k;i++){
					for(int j=0;j<m;j++){
						histogramme[i][j]=0;
					}
				}
				

				//on remplit l'histogramme
				while ((ftell(fichierbin)/8)!=nbrValeurs){
					for (int i=0; i<k;i++){
					fread(&valeurLue,sizeof(double),1,fichierbin);
						for(int j=0;j<m;j++){
							if((valeurLue>intervalleFrequence*j-1)&&(valeurLue<=intervalleFrequence*(j+1)-1)){
								histogramme[i][j]+=1;
								
							}
						}
					}
				}
				
				//on ferme le fichier bin
				fclose(fichierbin);
				
				//on cree le descripteur
				descripteurAudio(histogramme,NomFichierParam,m,k);
		} 
				
	} else {
		printf("ERREUR : nom du fichier inconnu \n");
	}

}




//on cree le descripteur du fichier audio
void descripteurAudio(int **histogramme,char* NomFichierParam, int m, int k){
	
	//variables
    FILE* descripteur=NULL;
	char suffixeDescripteur[]="_descripteur.txt";
	//char identifiant[strlen(NomFichierParam)];
	//char nomDescripteur[strlen(NomFichierParam)+strlen(suffixeDescripteur)];
	char emplacement[]="../../Base_descripteurs/Base_descripteurs_audios/";
	
	char *identifiant=(char *)malloc(strlen(NomFichierParam)+1);
	char *nomDescripteur=(char *)malloc(strlen(NomFichierParam)+strlen(suffixeDescripteur)+1);

	//on cree les chaines de caractères correspondants à :
	//L'identifiant qui sera écrit au debut du descripteur
	strcpy(identifiant,NomFichierParam);
	//Le nom du descripteur de la forme  nomDuFichier_descripteur.txt
	strcpy(nomDescripteur,NomFichierParam);
	strncpy(nomDescripteur,NomFichierParam,strlen(NomFichierParam)-4);
	nomDescripteur[strlen(NomFichierParam)-4]='\0';
	
	//nomDescripteur[strlen(nomDescripteur) - 4] = '\0';
	strcat(nomDescripteur,suffixeDescripteur);
	//L'emplacement du descripteur et son nom
	strcat(emplacement,nomDescripteur);
	
	//on cree le descripteur 
	descripteur = fopen(emplacement,"w");
	if (descripteur != NULL){
		//on ecrit l'identifiant
		fprintf(descripteur,"%s",identifiant);
		fprintf(descripteur,"\n");
		//on ecrit les dimensions de la matrice 
		fprintf(descripteur,"%d ",m);
		fprintf(descripteur,"%d ",k);
		fprintf(descripteur,"\n");
		//on écrit l'histogramme
		for (int i=0; i<k;i++){
			for(int j=0;j<m;j++){
				fprintf(descripteur,"%d ",histogramme[i][j]);
			}
		fprintf(descripteur,"\n");	
		}
	
	fclose(descripteur);
	
	//MAJ liste descripteurs
	miseAJourListeDescripteurs(NomFichierParam);

	
	} else {
		printf("ERREUR : impossible d'indexer le document\n");
	}
}





//écrit le nom du fichier dans la liste des descripteurs
void miseAJourListeDescripteurs(char* nomFichierParam){
	FILE* listeDescripteurs;
	listeDescripteurs=fopen("../../Liste_descripteurs/Liste_descripteurs_audios.txt","a");
	fprintf(listeDescripteurs,"%s \n",nomFichierParam);
	//fprintf(listeDescripteurs,"\n");
	fclose(listeDescripteurs);
	
}
