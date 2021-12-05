#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <wchar.h>
#include "histogramme_audio.h"



void descripteurAudio(int m, int n){
	
	//variables
    FILE *fichierbin=NULL;
    FILE* descripteur=NULL;
    long nbrValeurs;
    int **histogramme;
    double intervalleFrequence;
    int k;
    double valeurLue;

    // ouvrir le fichier en lecture et avoir le nombre de valeurs
    fichierbin = fopen("./TEST_SON/corpus_fi.bin","rb");
    //fichierbin = fopen("./TEST_SON/jingle_fi.bin","rb");
	fseek(fichierbin, 0, SEEK_END);	
	nbrValeurs=ftell(fichierbin)/8;
	fseek(fichierbin, 0,SEEK_SET);

	//on determine le nombre d'intervalles k de n echantillons
	k=nbrValeurs/n;
	
	//on calcule l'intevralle de frequence 
	intervalleFrequence=(float)2/(float)m;
	
	//on alloue l' histogramme 
	histogramme=(int**)malloc(k*sizeof(int*));
	for (int i=0; i<k;i++){
		histogramme[i]=(int*)malloc(m*sizeof(int));
	}	
	//on verifie l'allocation
	if(histogramme==NULL){
		printf("erreur\n");
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
	descripteur = fopen("descripteur.txt", "w");
	if (descripteur != NULL){
		fprintf(descripteur,"identifiant\n");
		for (int i=0; i<k;i++){
			for(int j=0;j<m;j++){
				fprintf(descripteur,"%d ",histogramme[i][j]);
			}
		fprintf(descripteur,"\n");	
		}
	}
	fclose(descripteur);
}



	
	
	
	
	
	

