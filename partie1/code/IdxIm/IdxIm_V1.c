					/*----------------------------------------------------*/
					/*		AUTEUR : AMBLARD Lucas			*/
					/*		DATE CREATION : 25/11/2021		*/
					/*----------------------------------------------------*/
					


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "IdxIm_V1.h"
#include "fifo.h"
//#include "element.h"

#include "../Configuration/configuration.h"
	
//---------------------------------------------------------
// Nom : initTab
// Description : //Verifie que le fichier est bien un fichier Image avant indexation
//---------------------------------------------------------	

void VerifTypeFichierImage(char *nomFichier, int type){
    int j;
    if (strlen(nomFichier) > 4) {
       for (j = 0; nomFichier[j + 3]; j++) {         
          if (!strcmp(&nomFichier[j], ".txt")){
			 INDEXIMAGE(nomFichier, type);
		 } 
       }
    }
}
	
//---------------------------------------------------------
// Nom : initTab
// Description :Initialisation du tableau
//---------------------------------------------------------
void initTab(int* tab, int nbVal){
   //Déclarations locales
   int cpt;
   //fin déclarations locales
   
   for(cpt=0; cpt<nbVal; cpt++){
   	*(tab+cpt)=0;
   }
}

//---------------------------------------------------------
// Nom : Histogramme
// Description : Incrémentation case tableau correspondant à la valeur
//---------------------------------------------------------
void Histogramme(int* tabValPix,int valPix){
   //Déclarations locales

   //fin déclarations locales
   
   tabValPix[valPix]+=1;
}

//---------------------------------------------------------
// Nom : DecompoMSB
// Description : Récupération des n MSB qui nous intéressent
//---------------------------------------------------------
int DecompoMSB(int valC, int n){
   //déclarations locales
   int tab[16];
   int i;  
   int msk;
   int valRes;
   //fin déclarations locales  
 
   msk=0xFF<<(8-n);		
   valRes=valC & msk;	//Récup des n MSB qui nous intéressent
   valRes=valRes>>(8-n); //On positionne les n MSB en LSB
   return valRes;
}

//---------------------------------------------------------
// Nom : calculValPixRVB
// Description : Calcul de la valeur final à partir des n bits pris dans chaque composant
//---------------------------------------------------------
int  calculValPixRVB(int compR, int compV, int compB, int n){
   //Déclarations locales
   int newVal;
   //fin déclarations locales
   
   newVal=0x0000|compR;		//Recopie de compR (n LSB obtenu avec fonction au dessus)
   newVal=newVal<<n;			//Décalage de n vers la gauche
   newVal=newVal|compV;		//recopie de compV (n LSB obtenu avec fonction au dessus)
   newVal=newVal<<n;			//Décalage de n vers la gauche
   newVal=newVal|compB;		//recopie de compB (n LSB obtenu avec fonction au dessus)

   return newVal;
}

//---------------------------------------------------------
// Nom : recupId
// Description : Récupération du nom fichier .txt pour utiliser en tant qu'identifiant descripteur associé
//---------------------------------------------------------
void recupIdIm(char* fileName, char* theFileName){
   //déclarations locales
   int quitter = 0;
   int cpt2 = 0; /* strlen(fileName);*/
   char caractere;
   int cpt3 = 0;  
   //fin déclarations locales
   while(!quitter) {
      caractere = fileName[cpt2];
      cpt2++;
      if(caractere != '.') {
         theFileName[cpt3] = caractere;
         cpt3++;
	}
      else
      quitter = 1;	
   }
}

//---------------------------------------------------------
// Nom : creaDescripteur
// Description : Création descripteur (ajout ID et histogramme)
//---------------------------------------------------------
void creaDescripteur(char* theFileName, int nbVal, int* tabValPix, int type){
   //Déclarations locales
    char theTargetFileName[100] = "../../Base_descripteurs/";	
    FILE * fichierT;	
    int cpt;  
   //fin déclarations locales
   if(type==0){
      strcat(theTargetFileName,"Base_descripteurs_images_RGB/");
      miseAJourListeDescripteursImageRVB(theFileName);
   }
   else{
      strcat(theTargetFileName,"Base_descripteurs_images_NB/");
      miseAJourListeDescripteursImageNB(theFileName);
   }
   strcat(theTargetFileName,theFileName);	
   strcat(theTargetFileName,".dsc");
			
   fichierT=fopen(theTargetFileName,"w");				//Création et ouverture du fichier descripteur
   if( fichierT == NULL ){
      printf( "Cannot open file %s\n", theTargetFileName );
    }
  // printf(" \n ");


   fprintf(fichierT," identifiant : %s \n", theFileName);		//Première ligne étant Identifiant du descripteur
   for(cpt=0; cpt<nbVal; cpt++){
      fprintf(fichierT,"%d \n",tabValPix[cpt]);			//Copie de l'histogramme dans la suite du descripteur
   }
   //printf(" \n ");
   fclose(fichierT);							//fermeture du descripteur

	
}

//---------------------------------------------------------
// Nom : IdxImage
// Description : Utilisation des fonctions pour éffectuer l'indexation de l'image
//---------------------------------------------------------
void IdxImage(char* fileName, int n, int type){

   //déclarations locales
   FILE * fileN;

   int nbLig;		//nombre de lignes dans .txt de l'image
   int nbCol;		//nombre de colonnes dans .txt de l'image
   int nbCoul;		//nombre de couleurs dans .txt de l'image

   int cptLig; 	//compteur pour les lignes
   int cptCol; 	//compteur pour les colonnes
   int cpt;		//test

   int valR;		//récupère la valeur de la composante ROUGE du pixel
   int valV;		//récupère la valeur de la composante VERTE du pixel
   int valB;		//récupère la valeur de la composante BLEU du pixel
   int valG;		//récupère la valeur du niveau de gris du pixel

   int valPix;		//Va recevoir la valeur finale du pixel apres toutes étapes

   int nbVal ;
   int* tabValPix;


   int elValR; 	//recupère 3 MSB de decomposition de valR 
   int elValV; 	//recupère 3 MSB de decomposition de valV 
   int elValB; 	//recupère 3 MSB de decomposition de valB 
   int elValG; 	//recupère 3 MSB de decomposition de valG

   int cptTest=0;

   MA_FILE filR;	//file dyna qui va stocker mes MSB R pour plus tard
   MA_FILE filV;	//file dyna qui va stocker mes MSB V pour plus tard
   MA_FILE filB;	//file dyna qui va stocker mes MSB B pour plus tard
   MA_FILE filG;	//file dyna qui va stocker mes MSB G pour plus tard
   
   char chemin[100] ="";
   char theFileName[3] = "";
   //fin déclarations

			/*---------------------------Actions----------------------------*/
			/*--------------------Initialisation des files------------------*/
			/*--------------------------------------------------------------*/

   filR=INIT_FILE(filR);
   filV=INIT_FILE(filV);
   filB=INIT_FILE(filB);
   filG=INIT_FILE(filG);

   if(type==0){
      strcat(chemin,"../../Corpus/IMAGE/RGB/");
   }
   else{
      strcat(chemin,"../../Corpus/IMAGE/NB/");
   }
   strcat(chemin,fileName);
   
   fileN=fopen(chemin,"r");

   fscanf(fileN,"%d", &nbLig);
   fscanf(fileN,"%d", &nbCol);
   fscanf(fileN,"%d", &nbCoul);	
	
   nbVal= pow(2,nbCoul*n)	;
   tabValPix=(int*)malloc(sizeof(int)*nbVal);
   initTab(tabValPix,nbVal);			

   switch(nbCoul){

   case 3:

			/*---------------------------Actions----------------------------*/
			/*-------------------Traitement matrice Rouge-------------------*/
			/*--------------------------------------------------------------*/					
							
      for(cptLig=2;cptLig<nbLig+2;cptLig++){
         for(cptCol=1; cptCol<=nbCol;cptCol++){
            fscanf(fileN,"%d",&valR);		//Lecture de la composante Rouge		
            elValR=DecompoMSB(valR,n); 	//Récupération des n MSB	
            filR=ENFILER(elValR, filR);	//Ajout dans la file de la valeur formé par les n MSB		
            }	
         }

			/*---------------------------Actions----------------------------*/
			/*-------------------Traitement matrice Verte-------------------*/
			/*--------------------------------------------------------------*/
							
      for(cptLig=nbLig+2;cptLig<(2*nbLig)+2;cptLig++){
         for(cptCol=1; cptCol<=nbCol;cptCol++){
            fscanf(fileN,"%d",&valV);	//Lecture de la composante Verte
            elValV=DecompoMSB(valV,n);	//Récupération des n MSB
            filV=ENFILER(elValV, filV);	//Ajout dans la file de la valeur formé par les n MSB
         }
      }

			/*---------------------------Actions----------------------------*/
			/*-------------------Traitement matrice Bleu-------------------*/
			/*--------------------------------------------------------------*/
							
      for(cptLig=(2*nbLig)+2;cptLig<(3*nbLig)+2;cptLig++){
         for(cptCol=1; cptCol<=nbCol;cptCol++){
            fscanf(fileN, "%d",&valB);	//Lecture de la composante
            elValB=DecompoMSB(valB,n);	//Récupération des n MSB
            filB=ENFILER(elValB, filB);	//Ajout dans la file de la valeur formé par les n MSB	
         }
      }  		

			/*---------------------------Actions----------------------------*/
			/*---------Calcul valeur finale et création histogramme---------*/
			/*-------------à partir des composantes précedentes-------------*/
	
      for(cptLig=0;cptLig<nbLig;cptLig++){
         for(cptCol=0;cptCol<nbCol;cptCol++){
            filR=DEFILER(&elValR,filR);			//Récupération val R
            filV=DEFILER(&elValV,filV);			//Récupération val V
            filB=DEFILER(&elValB,filB);			//Récupération val B
            valPix=calculValPixRVB(elValR,elValV,elValB, n);	//Obtention valeur finale à partir val R,V,B	
            Histogramme(tabValPix,valPix);			//MAJ Histogramme		
         }
      }		
      break;

   case 1:	
      
			/*---------------------------Actions----------------------------*/
			/*---------Calcul valeur finale et création histogramme---------*/
			/*---------------à partir de la seule matrice NB----------------*/
		
      for(cptLig=2;cptLig<nbLig+2;cptLig++){
         for(cptCol=1; cptCol<=nbCol;cptCol++){
            fscanf(fileN,"%d",&valG);		//Récupération val NB			
            elValG=DecompoMSB(valG,n);		//Récupération des n MSB
            Histogramme(&tabValPix[0],elValG);	//MAJ Histogramme direct, pas besoin de calculValPix car 1 seule composante NB				
         }
      }				
      break;		
}		

   recupIdIm(fileName,theFileName);
   
			/*---------------------------Actions----------------------------*/
			/*------------------création du descripteur---------------------*/
			/*--------------------------------------------------------------*/

   creaDescripteur(theFileName,nbVal,tabValPix,type);
}

void INDEXIMAGE(char* nomFichier,int type){
	//Déclarations locales
	int n;	//correspond au .config
	char param[]="nbrbit";
	//fin decl
	
	n=config(param);
	if(n==1 || n==2 || n==3){
		IdxImage(nomFichier,n,type);
	}
	else
	{
		printf("erreur param\n");
	}
}


void miseAJourListeDescripteursImageNB(char* nomFichierParam){
	FILE* listeDescripteurs;
	listeDescripteurs=fopen("../../Liste_descripteurs/Liste_descripteurs_imageNB.txt","a");
	fprintf(listeDescripteurs,"%s \n",nomFichierParam);
	//fprintf(listeDescripteurs,"\n");
	fclose(listeDescripteurs);
	
}

void miseAJourListeDescripteursImageRVB(char* nomFichierParam){
	FILE* listeDescripteurs;
	listeDescripteurs=fopen("../../Liste_descripteurs/Liste_descripteurs_imageRVB.txt","a");
	fprintf(listeDescripteurs,"%s \n",nomFichierParam);
	//fprintf(listeDescripteurs,"\n");
	fclose(listeDescripteurs);
	
}

