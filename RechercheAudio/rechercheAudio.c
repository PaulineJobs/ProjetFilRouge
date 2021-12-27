#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "rechercheAudio.h"
#include "arbre.h"



float comparaison(char* Nomfichier1 , char* Nomfichier2){
	FILE* fichier1;
	FILE* fichier2;
	fichier1=fopen(Nomfichier1,"r");
	fichier2=fopen(Nomfichier2,"r");
	char identifiant1[50];
	char identifiant2[50];
	int valeur1=0;
	int valeur2=0;
	float pourcentage;
	int pourcentageMin=100;
	int frame=0;

	
	
	if((fichier1!=NULL)&&(fichier2!=NULL)){
		
		//on récupère les identidiants 
		fgets(identifiant1,50,fichier1);
		identifiant1[strlen(identifiant1)-1]='\0';
		//strcat(identifiant1,".wav");
		//printf("l'identifiant 1 est  : %s\n",identifiant1);
		
		fgets(identifiant2,50,fichier2);
		identifiant2[strlen(identifiant2)-1]='\0';
		//strcat(identifiant2,".wav");
		//printf("l'identifiant 2 est  : %s\n",identifiant2);
		
		
		int m;
		int k1;
		
		int k2;
		
		fscanf(fichier1,"%d %d\n",&m,&k1);
		fscanf(fichier2,"%d %d\n",&m,&k2);
		
		
		if (k2>=k1){
	

			for (int p=1; p<=(k2-k1)+1; p++){
				
				int maxH1=0;
				int maxH2=0;
				int difference;
				int differenceTot=0;
				
				
				for (int i=0; i<k1;i++){
					for(int j=0;j<m;j++){
						
						
						
						//valeur1=getc(fichier1);
						fscanf(fichier1,"%d ", &valeur1);
						//valeur2=getc(fichier2);
						fscanf(fichier2,"%d ", &valeur2);

						//printf("la valeur 1 est  : %d\n",valeur1);
						//printf("la valeur 2 est  : %d\n",valeur2);
						
						maxH1+=(int)valeur1;
						maxH2+=(int)valeur2;
						
						difference = abs((int)valeur1-(int)valeur2);
						differenceTot+=difference;
						//printf("La difference est de : %d ",difference);
					}
					
				}
				
				pourcentage = ((float)differenceTot/(float)(maxH1+maxH2))*100;
				
				//printf("La difference totale est de : %d \n",differenceTot);
				//printf("maxh1 : %d \n",maxH1);
				//printf("maxh2 : %d \n",maxH2);
				//printf(" le pourcentage est de difference est de %f \n",pourcentage);
				
				if(pourcentageMin>pourcentage){
					pourcentageMin=pourcentage;
					frame=p;
				}
				
				fseek(fichier1,0,SEEK_SET);
				//printf("ftell fichier 1  %d\n",ftell(fichier1));
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
				
				//printf("ftell fichier 1  %d\n",ftell(fichier1));
				
				//printf("ftell fichier 2  %d\n",ftell(fichier2));
				
				//printf("p=  %d\n",p);
				//printf("m=  %d\n",m);
				//printf("id=  %d\n",strlen(identifiant2));
				

			}
			//printf("pourcentage min  %d  ",pourcentageMin);
			//printf("valeur p  %d  \n",frame);
			
		}
	
	
	else {
		for (int p=1; p<=(k1-k2)+1; p++){
				
				int maxH1=0;
				int maxH2=0;
				int difference;
				int differenceTot=0;
				
				
				for (int i=0; i<k2;i++){
					for(int j=0;j<m;j++){
						
						
						
						//valeur1=getc(fichier1);
						fscanf(fichier1,"%d ", &valeur1);
						//valeur2=getc(fichier2);
						fscanf(fichier2,"%d ", &valeur2);

						//printf("la valeur 1 est  : %d\n",valeur1);
						//printf("la valeur 2 est  : %d\n",valeur2);
						
						maxH1+=(int)valeur1;
						maxH2+=(int)valeur2;
						
						difference = abs((int)valeur1-(int)valeur2);
						differenceTot+=difference;
						//printf("La difference est de : %d ",difference);
					}
					
				}
				
				pourcentage = ((float)differenceTot/(float)(maxH1+maxH2))*100;
				
				//printf("La difference totale est de : %d \n",differenceTot);
				//printf("maxh1 : %d \n",maxH1);
				//printf("maxh2 : %d \n",maxH2);
				//printf(" le pourcentage est de difference est de %f \n",pourcentage);
				
				if(pourcentageMin>pourcentage){
					pourcentageMin=pourcentage;
					frame=p;
				}
				
				fseek(fichier2,0,SEEK_SET);
				//printf("ftell fichier 1  %d\n",ftell(fichier1));
				while (fgetc(fichier2)!='\n'){
				}
				while (fgetc(fichier2)!='\n'){
				}
				
				fseek(fichier1,0,SEEK_SET);
				while (fgetc(fichier1)!='\n'){
				}
				while (fgetc(fichier1)!='\n'){
				}
				fseek(fichier1,p*m,SEEK_CUR);
				
				//printf("ftell fichier 1  %d\n",ftell(fichier1));
				
				//printf("ftell fichier 2  %d\n",ftell(fichier2));
				
				//printf("p=  %d\n",p);
				//printf("m=  %d\n",m);
				//printf("id=  %d\n",strlen(identifiant2));
				

			}
			//printf("pourcentage min  %d  ",pourcentageMin);
			//printf("valeur p  %d  \n",frame);
			
		}
	}
		
		
		
	return pourcentageMin;
	 
}

void comparaisonRepertoire(char * fichierReference){
	
	ARBRE ensembleFichiers=INIT_ARBRE();
	
	//On lance l'indexation audio dans le repertoire contenant les fichiers audio
    struct dirent *dir;
    DIR *d = opendir("../Base_descripteurs/Base_descripteurs_audios/"); 
    if (d) {
        while ((dir = readdir(d)) != NULL){
			if((strlen(dir->d_name)>3)){
				char chemin[strlen("../Base_descripteurs/Base_descripteurs_audios/")+strlen(dir->d_name)+1];
				char nomFichier[strlen(dir->d_name)+1];
				strcpy(chemin,"../Base_descripteurs/Base_descripteurs_audios/");
				strcpy(nomFichier, dir->d_name);
				strcat(chemin,nomFichier);
				float difference=comparaison(fichierReference,chemin);
			
				
				ELEMENT document;
				
				document.nom=dir->d_name;
				document.nom[strlen(document.nom)-strlen("_descripteur.txt")]='\0';
				strcat(document.nom,".wav");
				document.ressemblance=100-difference;
				ajout_dans_arbre(&ensembleFichiers,document);
			}	
        }
        printf("\n");
		printf("Voici les resultats\n");
		printf("\n");
        affiche_Arbre(ensembleFichiers);
        closedir(d);
    }



}


void IHM(){
	char souhait[100];
	printf("Entrez le nom de votre fichier\n");
	scanf("%s",&souhait);
	
	//printf("%s\n",chemin);
	
	printf("\n");
	printf("Veuillez patienter\n");
	printf("\n");
	
	struct dirent *dir;
	int existe=0;
    DIR *d = opendir("../Corpus/AUDIO/"); 
    if (d) {
        while ((dir = readdir(d)) != NULL){
			//printf("%s\n",dir->d_name);
			//printf("%s\n",dir->d_name);
			if(!strcmp(dir->d_name,souhait)){
				souhait[strlen(souhait)-4]='\0';
				strcat(souhait,"_descripteur.txt");
				char chemin[strlen("../Base_descripteurs/Base_descripteurs_audios/")+1+ strlen(souhait)];
				strcpy(chemin,"../Base_descripteurs/Base_descripteurs_audios/");
				strcat(chemin,souhait);
				existe=1;
				comparaisonRepertoire(chemin);
			} else {
				existe=0;
			}
		}
		if (existe==0){
			printf("document inconnu\n");
		}
	}


}
	
