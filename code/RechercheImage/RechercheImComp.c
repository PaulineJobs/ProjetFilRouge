#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "RechercheImComp.h"
#include <math.h>
#include "../RechercheAudio/arbre.h"
#include "../Configuration/configuration.h"

//Compare le fichier 1 avec le fichier 2
float comparaison(char* Nomfichier1 , char* Nomfichier2, int type){
   //declarations locales
   FILE* fichier1;
   FILE* fichier2;
   fichier1=fopen(Nomfichier1,"r");
   fichier2=fopen(Nomfichier2,"r");
   char identifiant1[50];
   char identifiant2[50];
   int valeur1=0;
   int valeur2=0;
   float pourcentage;
   int n;
   char param[]="nbrbit";
   //fin déclarations locales
   
   n=config(param);

   //on verifie l'ouverture des descripteurs
   if((fichier1!=NULL)&&(fichier2!=NULL)){

      //on récupère les identidiants 

      fgets(identifiant1,50,fichier1);
      identifiant1[strlen(identifiant1)-1]='\0';

      fgets(identifiant2,50,fichier2);
      identifiant2[strlen(identifiant2)-1]='\0';

      int maxH1=0;
      int maxH2=0;
      int difference;
      int differenceTot=0;
      int nbBoucle;
      
      if(type==1){
         nbBoucle=pow(2,n*3);
      }
      else{
         nbBoucle=pow(2,n);
      }

      //Pour chaque parcelle du fichier 2 qui va etre comparée au fichier 1 
      for (int p=1; p<=nbBoucle; p++){						

      //On recupère les valeurs 

         fscanf(fichier1,"%d ", &valeur1);
         fscanf(fichier2,"%d ", &valeur2);

         //On fait la somme de ces valeurs pour chaque histogramme
         maxH1+=(int)valeur1;
         maxH2+=(int)valeur2;

         //On calcule la difference des deux valeurs 

         difference = abs((int)valeur1-(int)valeur2);
         differenceTot+=difference;

      }

      //on calcule le poucentage
      pourcentage = (((float)differenceTot/(maxH1+maxH2))*100);
}
return pourcentage;
}

void comparaisonRepertoireIm(char * fichierReference, char type){
   ARBRE ensembleFichiers=INIT_ARBRE();
   if(type=='1'){
      //On lance l'indexation audio dans le repertoire contenant les fichiers audio
      struct dirent *dir;
      DIR *d = opendir("../../Base_descripteurs/Base_descripteurs_images_RGB/"); 
      if (d) {
         while ((dir = readdir(d)) != NULL){
            if((strlen(dir->d_name)>3)){
               char chemin[strlen("../../Base_descripteurs/Base_descripteurs_images_RGB/")+strlen(dir->d_name)+1];
               char nomFichier[strlen(dir->d_name)+1];
               strcpy(chemin,"../../Base_descripteurs/Base_descripteurs_images_RGB/");
               strcpy(nomFichier, dir->d_name);
               strcat(chemin,nomFichier);
               
               if (strcmp(chemin,fichierReference)!=0 && strcmp(".",fichierReference)!=0 && strcmp("..",fichierReference)!=0){
				   float difference=comparaison(fichierReference,chemin,type);

	//on met tout cela dans un arbre GRD
				   ELEMENT document;

				   document.nom=dir->d_name;
				   document.nom[strlen(document.nom)-strlen(".dsc")]='\0';
				   strcat(document.nom,".jpg");
				   document.ressemblance=100-difference;
				   ajout_dans_arbre(&ensembleFichiers,document);
			   }
            }	
         }
         printf("\n");
         printf(" --------------------- \n");
         printf("| Voici les resultats |\n");
         printf(" --------------------- \n");
         printf("\n");
         affiche_Arbre(ensembleFichiers);
         closedir(d);
      }
   }
   else
   {
      struct dirent *dir;
      DIR *d = opendir("../../Base_descripteurs/Base_descripteurs_images_NB/"); 
         if (d) {
            while ((dir = readdir(d)) != NULL){
               if((strlen(dir->d_name)>3)){
                  char chemin[strlen("../../Base_descripteurs/Base_descripteurs_images_NB/")+strlen(dir->d_name)+1];
                  char nomFichier[strlen(dir->d_name)+1];
                  strcpy(chemin,"../../Base_descripteurs/Base_descripteurs_images_NB/");
                  strcpy(nomFichier, dir->d_name);
                  strcat(chemin,nomFichier);
                  if (strcmp(chemin,fichierReference)!=0 && strcmp(".",fichierReference)!=0 && strcmp("..",fichierReference)!=0){
			  float difference=comparaison(fichierReference,chemin,type);

			  //on met tout cela dans un arbre GRD
			  ELEMENT document;

			  document.nom=dir->d_name;
			  document.nom[strlen(document.nom)-strlen(".dsc")]='\0';
			  strcat(document.nom,".jpg");
			  document.ressemblance=100-difference;
			  ajout_dans_arbre(&ensembleFichiers,document);
                  }
               }	
            }
            printf("\n");
            printf(" ------------------- \n");
            printf("|Voici les resultats|\n");
            printf(" ------------------- \n");
            printf("\n");
            affiche_Arbre(ensembleFichiers);
            closedir(d);
         }
   }
   
}


void IHMComp(){
   //déclarations locales
   char souhait[100];
   char typeIm[100];
   //fin déclarations locales
   
   do{

      printf("| Quel type d'image souhaitez vous traiter : Couleurs (1) ou noir et blanc (2) | \n");
      printf(" ------------------------------------------------------------------------------ \n");
      scanf("%s",typeIm);
      if(typeIm[0]!='1' && typeIm[0]!='2'){
         printf("Valeur érronée, saisir 1 ou 2"); 
      }
   }while(typeIm[0]!='1' && typeIm[0]!='2');

   printf(" ---------------------------------- \n");
   printf("| Entrez le nom de votre fichier : |\n");
   printf(" ---------------------------------- \n");	
   scanf("%s",souhait);
   printf("\n");
   printf("Veuillez patienter\n");
   printf("\n");

   if(typeIm[0]=='1'){
   struct dirent *dir;
   int existe=0;
   DIR *d = opendir("../../Corpus/IMAGE/RGB"); 
   if (d) {
      while ((dir = readdir(d)) != NULL){
         if(!strcmp(dir->d_name,souhait)){
            souhait[strlen(souhait)-4]='\0';
            strcat(souhait,".dsc");
            char chemin[strlen("../../Base_descripteurs/Base_descripteurs_images_RGB/")+1+ strlen(souhait)];
            strcpy(chemin,"../../Base_descripteurs/Base_descripteurs_images_RGB/");
            strcat(chemin,souhait);
            existe=1;
            comparaisonRepertoireIm(chemin,typeIm[0]);
         } 
      }
      if (existe==0){
         printf("document inconnu\n");
      }
      printf("\n");
      printf("\n");
   }
}
else
{
   struct dirent *dir;
   int existe=0;
   DIR *d = opendir("../../Corpus/IMAGE/NB"); 
   if (d) {
      while ((dir = readdir(d)) != NULL){
         if(!strcmp(dir->d_name,souhait)){
            souhait[strlen(souhait)-4]='\0';
            strcat(souhait,".dsc");
            char chemin[strlen("../../Base_descripteurs/Base_descripteurs_images_NB/")+1+ strlen(souhait)];
            strcpy(chemin,"../../Base_descripteurs/Base_descripteurs_images_NB/");
            strcat(chemin,souhait);
            existe=1;
            comparaisonRepertoireIm(chemin,typeIm[0]);
         } 
      }
      if (existe==0){
         printf("document inconnu\n");
      }
      printf("\n");
      printf("\n");
   }	
}	

}
	
