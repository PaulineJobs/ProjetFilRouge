/*
Fichier réalisé par : Manon COUFFIN
Derniere modif le : 04/12/2021
Lier aux fichiers : tstNettoyageTexte.c et nettoyageTexte.h
*/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "nettoyageTexte.h"


//Definir un programme permettant de verifier le nom du fichier
void passageXmlClean(char * NomTexteXML)//Mettre en paramettre d'entré le nom du fichier choisit
{	
    FILE *texteXml, *texteClean;
    char var;
  
    // ouvrir le fichier en lecture
    
    
    char *emplacement;
    emplacement =(char*)malloc(strlen("../../../../partie1/Corpus/TEXTE/")+strlen(NomTexteXML)+1);
  
    strcpy(emplacement,"../../../../partie1/Corpus/TEXTE/");
    strcat(emplacement,NomTexteXML);
    
    
    texteXml = fopen(emplacement, "r");

    // ouvrir le fichier en écriture
    texteClean = fopen("../../../../partie1/code/Indexation_texte/Nettoyer/texteConvertit.clean", "w");
	if (texteClean !=NULL)
    {
		// Lire le contenu du fichier
		while((var = getc(texteXml)) != EOF)
			putc(var, texteClean);
	  
		//Fermer les 2 textes
		fclose(texteXml);
		fclose(texteClean);
	} 
    else 
    {
		printf("malloc non effectué");
	}
	
}

void majMin()
{
    FILE *maj, *min;
    char lettre;
    int sup=1;
  
    // ouvrir le fichier en lecture
    maj = fopen("../../../../partie1/code/Indexation_texte/Nettoyer/texteConvertit.clean", "r");

    // ouvrir le fichier en écriture
    min = fopen("../../../../partie1/code/Indexation_texte/Nettoyer/plusDeMaj.clean", "w");

  
    // Lire le contenu du fichier
    while((lettre = getc(maj)) != EOF){
        if(lettre < 129)
        { //Verifit que la lettre n'est pas un accent (code ASCII)
           lettre = tolower(lettre); //Transforme les Maj en min
        }
        putc(lettre, min); //ecriture de la nouvelle lettre dans le fichier
    }
  
    //Fermer les 2 textes
    fclose(maj);
    fclose(min);

    while(sup)
    {
       sup = remove("../../../../partie1/code/Indexation_texte/Nettoyer/texteConvertit.clean"); 
    }
    
}

void suppressionBalise(){
    FILE *init, *clean;
    char lettre;
    int balise;
    int sup = 1;

    balise = 0;
  
    // ouvrir le fichier en lecture
    init = fopen("../../../../partie1/code/Indexation_texte/Nettoyer/plusDeMaj.clean", "r");

    // ouvrir le fichier en écriture
    clean = fopen("../../../../partie1/code/Indexation_texte/Nettoyer/plusDeBalise.clean", "w");

    while((lettre = fgetc(init)) != EOF){
        if(lettre == '<'){ 
            balise = 1;
        }
        if(balise==0){
            putc(lettre, clean); //ecriture de la nouvelle lettre dans le fichier
        }  
        if(lettre == '>'){
            balise = 0;
        }
        
        
    }
  
    //Fermer les 2 textes
    fclose(init);
    fclose(clean);

    while(sup)
    {
       sup = remove("../../../../partie1/code/Indexation_texte/Nettoyer/plusDeMaj.clean"); 
    }
  
}

void espaceApostrophe(){
    FILE *texte, *apostrophe;
    char lettre;
    int sup = 1;
  
    // ouvrir le fichier en lecture 
    texte = fopen("../../../../partie1/code/Indexation_texte/Nettoyer/plusDeBalise.clean", "r");

    // ouvrir le fichier en écriture
    apostrophe = fopen("../../../../partie1/code/Indexation_texte/Nettoyer/apostrophe.clean", "w");

    while((lettre = getc(texte)) != EOF){
        putc(lettre, apostrophe);
        
        if(lettre == 39){ 
            putc(' ', apostrophe);
        }

    }
  
    //Fermer le texte
    fclose(texte);
    fclose(apostrophe);

    
  while(sup)
    {
       sup = remove("../../../../partie1/code/Indexation_texte/Nettoyer/plusDeBalise.clean"); 
    }
}

void retirePonctuation(){
    FILE *texte, *ponctuation;
    char lettre;
    int sup =1;
  
    // ouvrir le fichier en lecture 
    texte = fopen("../../../../partie1/code/Indexation_texte/Nettoyer/apostrophe.clean", "r");

    // ouvrir le fichier en écriture
    ponctuation = fopen("../../../../partie1/code/Indexation_texte/Nettoyer/fichier.clean", "w");

    while((lettre = getc(texte)) != EOF){
        if(lettre == '.'){ 
            putc(' ', ponctuation);
        }
        else if((lettre == ';') || (lettre == '?') || (lettre == ',') || (lettre == ':') || (lettre == '/') || (lettre == '!')|| (lettre == '(')|| (lettre == ')')){

        }
        else{
            putc(lettre, ponctuation);
        }

    }
  
    //Fermer le texte
    fclose(texte);
    fclose(ponctuation);


    while(sup)
    {
        sup = remove("../../../../partie1/code/Indexation_texte/Nettoyer/apostrophe.clean"); 
    }
  
}

void Nettoyage(char *NomFichier)
{
	

    passageXmlClean(NomFichier);
    majMin();
    suppressionBalise();
    espaceApostrophe();
    retirePonctuation();
    
}
