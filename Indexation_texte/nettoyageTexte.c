
#include <stdio.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "nettoyageTexte.h"


//Definir un programme permettant de verifier le nom du fichier
void passageXmlClean()//Mettre en paramettre d'entré le nom du fichier choisit
{
    FILE *texteXml, *texteClean;
    char var;
  
    // ouvrir le fichier en lecture
    texteXml = fopen("Corpus/03-Des_chercheurs_parviennent_α_rΘgΘnΘrer.xml", "r");

    // ouvrir le fichier en écriture
    texteClean = fopen("Nettoyer/03-Des_chercheurs_parviennent_α_rΘgΘnΘrer.clean", "w");
  
    // Lire le contenu du fichier
    while((var = getc(texteXml)) != EOF)
        putc(var, texteClean);
  
    //Fermer les 2 textes
    fclose(texteXml);
    fclose(texteClean);
}

void majMin()
{
    FILE *maj, *min;
    char lettre;
    int sup;
  
    // ouvrir le fichier en lecture
    maj = fopen("Nettoyer/03-Des_chercheurs_parviennent_α_rΘgΘnΘrer.clean", "r");

    // ouvrir le fichier en écriture
    min = fopen("Nettoyer/03-Des_chercheurs_parviennent_α_rΘgΘnΘrerr.clean", "w");

  
    // Lire le contenu du fichier
    while((lettre = getc(maj)) != EOF){
        if(lettre < 129){ //Verifit que la lettre n'est pas un accent (code ASCII)
           lettre = tolower(lettre); //Transforme les Maj en min
        }
        putc(lettre, min); //ecriture de la nouvelle lettre dans le fichier
    }
  
    //Fermer les 2 textes
    fclose(maj);
    fclose(min);

    sup = remove("Nettoyer/03-Des_chercheurs_parviennent_α_rΘgΘnΘrer.clean");
}

void suppressionBalise(){
    FILE *init, *clean;
    char lettre;
    int balise, sup;

    balise = 0;
  
    // ouvrir le fichier en lecture
    init = fopen("Nettoyer/03-Des_chercheurs_parviennent_α_rΘgΘnΘrerr.clean", "r");

    // ouvrir le fichier en écriture
    clean = fopen("Nettoyer/plusDeBalise.clean", "w");

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

    sup = remove("Nettoyer/03-Des_chercheurs_parviennent_α_rΘgΘnΘrerr.clean");
  
}

void espaceApostrophe(){
    FILE *texte, *apostrophe;
    char lettre;
    int sup;
  
    // ouvrir le fichier en lecture 
    texte = fopen("Nettoyer/plusDeBalise.clean", "r");

    // ouvrir le fichier en écriture
    apostrophe = fopen("Nettoyer/apostrophe.clean", "w");

    while((lettre = getc(texte)) != EOF){
        putc(lettre, apostrophe);
        
        if(lettre == 39){ 
            putc(' ', apostrophe);
        }

    }
  
    //Fermer le texte
    fclose(texte);
    fclose(apostrophe);

    sup = remove("Nettoyer/plusDeBalise.clean");
  
}

void retirePonctuation(){
    FILE *texte, *ponctuation;
    char lettre;
    int sup;
  
    // ouvrir le fichier en lecture 
    texte = fopen("Nettoyer/apostrophe.clean", "r");

    // ouvrir le fichier en écriture
    ponctuation = fopen("Nettoyer/03-Des_chercheurs_parviennent_α_rΘgΘnΘrer.clean", "w");

    while((lettre = getc(texte)) != EOF){
        if(lettre == '.'){ 
            putc(' ', ponctuation);
        }
        else if((lettre == ';') || (lettre == '?') || (lettre == ',') || (lettre == ':') || (lettre == '/') || (lettre == '!')){

        }
        else{
            putc(lettre, ponctuation);
        }

    }
  
    //Fermer le texte
    fclose(texte);
    fclose(ponctuation);

    sup = remove("Nettoyer/apostrophe.clean");
  
}

void Nettoyage()
{
    passageXmlClean();
    majMin();
    suppressionBalise();
    espaceApostrophe();
    retirePonctuation();
}