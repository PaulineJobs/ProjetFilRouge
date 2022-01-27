#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "RechercheImCrit.h"
#include <math.h>
#include "../RechercheAudio/arbre.h"
#include "../Configuration/configuration.h"


//Recherche par critère
float critere(char* nomFichier, char choix){
   //Declarations locales
   FILE * fichierT;
  
   int cptLig;
   int cptCol;
   int nbL;
   int nbC;
   int nbCoul;
   
   int valR;
   int valV;
   int valB;
   
   int difference=0;
   int differenceTot=0;
   
   int maxH2=0;
   
   float pourcentage;
   char ext[10]="";
   char chemin[strlen("../Corpus/IMAGE/RGB/")+strlen(nomFichier)+1];
        
   int j;
   //fin declarations locales
                
		    if (strlen(nomFichier) > 4) {
		       for (j = 2; j<6; j++) { 
		        ext[j-2]=nomFichier[j];
		       }        
			  if (!strcmp(ext, ".txt")){
			  	   strcpy(chemin,"../../Corpus/IMAGE/RGB/");
				   strcat(chemin,nomFichier);
			  	   fichierT=fopen(chemin,"r");
				   
				   fscanf(fichierT,"%d", &nbL);
				   fscanf(fichierT,"%d", &nbC);
				   fscanf(fichierT,"%d", &nbCoul);
					/*---------------------------Actions----------------------------*/
					/*-------------------Traitement matrice Rouge-------------------*/
					/*--------------------------------------------------------------*/	
											
				      for(cptLig=2;cptLig<nbL+2;cptLig++){
					 for(cptCol=1; cptCol<=nbC;cptCol++){
					       fscanf(fichierT,"%d",&valR);	//Lecture de la composante Rouge
					    if(choix=='R'){
					       difference = abs(255-valR);
					       differenceTot+=difference;  
					       maxH2+=(int)valR;
					    }         		
					 }	
				      }				      
				      if(choix =='R'){
				      fclose(fichierT);
					 //on calcule le poucentage
					 pourcentage = (((float)differenceTot/(255*nbC*nbL+maxH2))*100);
					 return 100 - pourcentage;
				      }
					/*---------------------------Actions----------------------------*/
					/*-------------------Traitement matrice Verte-------------------*/
					/*--------------------------------------------------------------*/	
											
				      for(cptLig=nbL+2;cptLig<(2*nbL)+2;cptLig++){
					 for(cptCol=1; cptCol<=nbC;cptCol++){					    
					       fscanf(fichierT,"%d",&valV);		//Lecture de la composante Rouge
					       if(choix=='V'){
					          difference = abs(255-valV);
					          differenceTot+=difference;  
					          maxH2+=(int)valV;
					    }         		
					 }	
				      }				      
				      if(choix =='V'){
				      fclose(fichierT);
					 //on calcule le poucentage
					 pourcentage = (((float)differenceTot/(255*nbC*nbL+maxH2))*100);
					 return 100 - pourcentage;
				      }				 
					/*---------------------------Actions----------------------------*/
					/*-------------------Traitement matrice Bleu-------------------*/
					/*--------------------------------------------------------------*/	
											
				      for(cptLig=(2*nbL)+2;cptLig<(3*nbL)+2;cptLig++){
					 for(cptCol=1; cptCol<=nbC;cptCol++){
					       fscanf(fichierT,"%d",&valB);	//Lecture de la composante Rouge			       
					       if(choix=='B'){
					          difference = abs(255-valB);
					          differenceTot+=difference;  
					          maxH2+=(int)valB;
					    }         		
					 }	
				      }				  
				      if(choix =='B'){
				      fclose(fichierT);
					 //on calcule le poucentage
					 pourcentage = (((float)differenceTot/(255*nbC*nbL+maxH2))*100); 
					 return 100 - pourcentage;
				      }				      
				 } 
				 else return -1 ; 
		    }    
}

void IHMCrit(){
   //Declarations locales
   char choix[100];
   
   //fin declarations locales
   
   ARBRE ensembleFichiers=INIT_ARBRE();
   while ((choix[0]!='R') && (choix[0]!='V') && (choix[0]!='B') ){
       printf(" ------------------------------------------------------------------------------ \n");
	   printf("|  selon quel critère souhaitez vous faire la recherche :                      |\n");
	   printf("|   - Rouge (R)                                                                |\n");
	   printf("|   - Vert  (V)                                                                |\n");
	   printf("|   - Bleu  (B)                                                                 |\n");
	   printf(" ------------------------------------------------------------------------------ \n");
	   scanf("%s",choix);
	   
	}
	printf(" Veuillez patienter...\n");
    struct dirent *dir;
    DIR *dImageRGB = opendir("../../Corpus/IMAGE/RGB");
    if (dImageRGB) {
        while ((dir = readdir(dImageRGB)) != NULL){
		float pourcentage = critere(dir->d_name,choix[0]);
	       ELEMENT document;
               if(pourcentage != -1){
                  document.nom=dir->d_name;
                  document.nom[strlen(document.nom)-strlen(".dsc")]='\0';
                  strcat(document.nom,".jpg");
                  document.ressemblance=pourcentage;
                  ajout_dans_arbre(&ensembleFichiers,document);
               }
	 }
	 printf("\n");
	 printf(" ---------------------  \n");
         printf("| Voici les resultats |\n");
         printf(" ---------------------  \n");
         printf("\n");
         affiche_Arbre(ensembleFichiers);
        closedir(dImageRGB);
    }

}
