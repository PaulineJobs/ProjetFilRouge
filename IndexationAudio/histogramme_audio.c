#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include "histogramme_audio.h"
//Pauline

//on cree l'histogramme du fichier audio
void histogrammeAudio(int m, int n,char* NomFichierParam){
	
	//variables
    FILE *fichierbin=NULL;
    long nbrValeurs;
    int **histogramme;
    double intervalleFrequence;
    int k;
    double valeurLue;
	char emplacement []="../Corpus/AUDIO/";
	char nomFichier[strlen(NomFichierParam)];
	
	
    // ouvrir le fichier en lecture et avoir le nombre de valeurs
    fichierbin = fopen(strcat(emplacement,NomFichierParam),"rb");
  
    //on verifie l'existance et l'ouverture du fichier
     if (fichierbin!=NULL){
         
		//on va chercher le nombre de valeurs dans le fichier.bin
		//on divise le resultat par 8 car un double fait 8 octets
		fseek(fichierbin, 0, SEEK_END);	
		nbrValeurs=ftell(fichierbin)/8;
		fseek(fichierbin, 0,SEEK_SET);

		//on determine le nombre d'intervalles k de n echantillons (on découpe l'axe des abscisses)
		k=(nbrValeurs/n)+1;
		
		//on calcule l'intevralle de frequence (on découpe l'axe des ordonnées)
		intervalleFrequence=(float)2/(float)m;
		
		//on alloue la matrice qui représente l' histogramme 
		histogramme=(int**)malloc(k*sizeof(int*));
		for (int i=0; i<k;i++){
			histogramme[i]=(int*)malloc(m*sizeof(int));
		}	
		//on verifie l'allocation
		if(histogramme==NULL){
			printf("ERREUR: Impossible d'indexer ce fichier\n");
			exit(0);
		}
		
		//on initialise l'histogramme à zero
		for (int i=0; i<k;i++){
			for(int j=0;j<m;j++){
				histogramme[i][j]=0;
			}
		}
		

		//on remplit l'histogramme
		while (ftell(fichierbin)/8!=nbrValeurs){
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
		
	} else {
		printf("ERREUR : impossible d'indexer le document\n Le fichier n'as pas pu ếtre ouvert ou n'existe pas \n");
	}
}



//on cree le descripteur du fichier audio
void descripteurAudio(int **histogramme,char* NomFichierParam, int m, int k){
	
	//variables
    FILE* descripteur=NULL;
	char suffixeDescripteur[]="_descripteur.txt";
	char identifiant[strlen(NomFichierParam)];
	char nomDescripteur[strlen(NomFichierParam)+strlen(suffixeDescripteur)];
	char emplacement[]="../Base_descripteurs/Base_descripteurs_audios/";
	
	//on cree les chaines de caractères correspondants à :
	//L'identifiant qui sera écrit au debut du descripteur
	strcpy(identifiant,NomFichierParam);
	//Le nom du descripteur de la forme  nomDuFichier_descripteur.txt
	strcpy(nomDescripteur,NomFichierParam);
	strcat(nomDescripteur,suffixeDescripteur);
	//L'emplacement du descripteur et son nom
	strcat(emplacement,nomDescripteur);
	
	//on cree le descripteur 
	descripteur = fopen(emplacement,"w");
	if (descripteur != NULL){
		//on ecrit l'identifiant
		fprintf(descripteur,identifiant);
		fprintf(descripteur,"\n");
		//on écrit l'histogramme
		for (int i=0; i<k;i++){
			for(int j=0;j<m;j++){
				fprintf(descripteur,"%d ",histogramme[i][j]);
			}
		fprintf(descripteur,"\n");	
		}
	
	fclose(descripteur);
	
	} else {
		printf("ERREUR : impossible d'indexer le document\n Le descripteur n'a pas pu etre cree\n");
	}
}

void fichierIndexe(){
	
	char nomFichier[50];
	printf("Saisissez le nom de votre fichier\n");
	scanf("%s",nomFichier);
	
	int m=100;
	//n ne peux pas etre superieur au nombre de valeur dans le fichier 
	int n=1024;
	histogrammeAudio(m,n,nomFichier);

}
