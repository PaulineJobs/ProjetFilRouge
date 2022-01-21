
					/*-------------------------------------------/
					/        AUTEUR : JOBERT Pauline             /
                    /-------------------------------------------*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "rechercheAudio.h"
#include "arbre.h"



//Compare le fichier 1 avec le fichier 2
float comparaisonDeuxFichiers(char* Nomfichier1 , char* Nomfichier2){
	//variables
	FILE* fichier1;
	FILE* fichier2;
	char identifiant1[50];
	char identifiant2[50];
	int valeur1=0;
	int valeur2=0;
	float *pourcentage=malloc(sizeof(float));
	*pourcentage=0;
	float *pourcentageMin=malloc(sizeof(float));
	*pourcentageMin=100;
	int *frame=malloc(sizeof(int));
	*frame=0;

	//on verifie l'ouverture des descripteurs
	fichier1=fopen(Nomfichier1,"r");
	fichier2=fopen(Nomfichier2,"r");
	if((fichier1!=NULL)&&(fichier2!=NULL)){
		
		//on récupère les identidiants 
		fgets(identifiant1,50,fichier1);
		identifiant1[strlen(identifiant1)-1]='\0';
		fgets(identifiant2,50,fichier2);
		identifiant2[strlen(identifiant2)-1]='\0';
		
		//on reucupère les dimensions de l'histogramme
		int m;
		int k1;
		int k2;
	
		fscanf(fichier1,"%d %d\n",&m,&k1);
		fscanf(fichier2,"%d %d\n",&m,&k2);
		
		fclose(fichier1);
		fclose(fichier2);

		//Si le fichier 1 est plus petit que le fichier 2
		if (k2>=k1){

			comparaisonDeuxHistogrammes(k1,k2,m,Nomfichier1,Nomfichier2,frame,pourcentage,pourcentageMin);
		} else {
			comparaisonDeuxHistogrammes(k2, k1,m, Nomfichier2 , Nomfichier1,frame,pourcentage, pourcentageMin);
		}
			
	
			
	return *pourcentageMin;
	}
	 
}













void comparaisonDeuxHistogrammes(int k1, int k2, int m, char* Nomfichier1 , char* Nomfichier2, int* frame, float* pourcentage, float* pourcentageMin){
			//Pour chaque parcelle du fichier 2 qui va etre comparée au fichier 1
			
			FILE *fichier1=fopen(Nomfichier1,"r");
			FILE *fichier2=fopen(Nomfichier2,"r");
			int valeur1=0;
			int valeur2=0;
			
			for (int p=1; p<=(k2-k1)+1; p++){
				
				//variables

				int maxH1=0;
				int maxH2=0;
				int difference;
				int differenceTot=0;
				
				
				//on accède aux histogrammes
				while (fgetc(fichier2)!='\n'){
				}
				while (fgetc(fichier2)!='\n'){
				}
				while (fgetc(fichier1)!='\n'){
				}
				while (fgetc(fichier1)!='\n'){
				}
				
				//Pour chaque valeur des deux histogrammes
				for (int i=0; i<k1;i++){
					for(int j=0;j<m;j++){
						
						//On recupère les valeurs 
						fscanf(fichier1,"%d ", &valeur1);
						fscanf(fichier2,"%d ", &valeur2);
						
						//On fait la somme de ces valeurs pour chaque histogramme
						maxH1+=(int)valeur1;
						maxH2+=(int)valeur2;
						
						//On calcule la difference des deux valeurs 
						difference = abs((int)valeur1-(int)valeur2);
						
						//on ajoute a la difference totale 
						differenceTot+=difference;
					}
					
				}
				
				//on calcule le poucentage de difference 
				*pourcentage = ((float)differenceTot/(float)(maxH1+maxH2))*100;
				
				//on prends le pourcentage min
				if(*pourcentageMin>*pourcentage){
					*pourcentageMin=*pourcentage;
					*frame=p;
				}
				
				//on replace le curseur des fichiers 1 et 2 aux bons endroits pour refaire une comparaison
				fseek(fichier1,0,SEEK_SET);
				while (fgetc(fichier1)!='\n'){
				}
				while (fgetc(fichier1)!='\n'){
				}
				fseek(fichier2,0,SEEK_SET);
				while (fgetc(fichier2)!='\n'){
				}
				while (fgetc(fichier2)!='\n'){
				}
				fseek(fichier2,p*m,SEEK_CUR);
			}
			
		fclose(fichier1);
		fclose(fichier2);
			
}
	

void comparaisonRepertoire(char * fichierReference){
	ARBRE ensembleFichiers=INIT_ARBRE();
	
	//On lance l'indexation audio dans le repertoire contenant les fichiers audio
    struct dirent *dir;
 
    DIR *d = opendir("../../Base_descripteurs/Base_descripteurs_audios/"); 
  
    if (d) {
        while ((dir = readdir(d)) != NULL){
			if((strlen(dir->d_name)>3)){
			
				char chemin[strlen("../../Base_descripteurs/Base_descripteurs_audios/")+strlen(dir->d_name)+1];
				char nomFichier[strlen(dir->d_name)+1];
				strcpy(chemin,"../../Base_descripteurs/Base_descripteurs_audios/");
				strcpy(nomFichier, dir->d_name);
				
				strcat(chemin,nomFichier);
				
				float difference=comparaisonDeuxFichiers(fichierReference,chemin);
			
				//on met tout cela dans un arbre GRD
				ELEMENT document;
				
				document.nom=dir->d_name;
				document.nom[strlen(document.nom)-strlen("_descripteur.txt")]='\0';
				strcat(document.nom,".wav");
				document.ressemblance=100-difference;
				ajout_dans_arbre(&ensembleFichiers,document);
			}	
        }
        printf("\n");
        printf(" --------------------  \n");
	printf("|Voici les resultats | \n");
	printf(" --------------------  \n");
	printf("\n");
        affiche_Arbre(ensembleFichiers);
        closedir(d);
    }



}


void IHM(){
	char souhait[100];
	printf("| Entrez le nom de votre fichier                                               |\n");
	printf(" ------------------------------------------------------------------------------ \n");
	scanf("%s",souhait);
	

	printf("\n");
	printf(" -------------------- \n");
	printf("| Veuillez patienter | \n");
	printf(" -------------------- \n");
	printf("\n");
	
	struct dirent *dir;
	int existe=0;
 
    DIR *d = opendir("../../Corpus/AUDIO/");
  
    if (d) {
        while ((dir = readdir(d)) != NULL){
			if(!strcmp(dir->d_name,souhait)){
				souhait[strlen(souhait)-4]='\0';
				strcat(souhait,"_descripteur.txt");
				
				char chemin[strlen("../../Base_descripteurs/Base_descripteurs_audios/")+1+ strlen(souhait)];
				strcpy(chemin,"../../Base_descripteurs/Base_descripteurs_audios/");
				strcat(chemin,souhait);
				existe=1;
				
				comparaisonRepertoire(chemin);
				
			} 
		}
		if (existe==0){
			printf("document inconnu\n");
		}
		printf("\n");
		printf("\n");
	}


}











void lanceFichierAudio(char *fichierAudio) {
	char *lecteurAudio="vlc";
	char *commande;

    // Allocation lecteurAudion + espace+ fichierAudio + &
	commande=(char *)malloc(strlen(fichierAudio)+strlen(lecteurAudio)+1+1+1);
	//printf("Malloc %d \n",strlen(fichierAudio)+strlen(lecteurAudio)+1+1);
	if (commande !=NULL){
		strcpy(commande,lecteurAudio);
		strcat(commande," ");
		strcat(commande,fichierAudio);
		strcat(commande,"&");
		//printf("Lancement de la commande %s\n",commande);
		system(commande);
		free(commande);
	}
}



	
