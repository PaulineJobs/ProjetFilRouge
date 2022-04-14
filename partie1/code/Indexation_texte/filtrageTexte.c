/*
Fichier réalisé par : Manon COUFFIN
Derniere modif le : 16/12/2021
Lier aux fichiers : tstFiltrageTexte.c et filtrageTexte.h
*/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "filtrageTexte.h"



//Definir un programme permettant de verifier le nom du fichier


void passageCleanTok(void) //Mettre en paramettre d'entré le nom du fichier choisit
{
    FILE *texteTok, *texteClean, *stoplist;
    char token[20], stopword[20];
    int cpt = 0;
    int i;
    int sup =1;
    int verif = 0;
    
    // ouvrir les fichiers en lecture
    printf("test");
    texteClean = fopen("../../../../partie1/code/Indexation_texte/Nettoyer/fichier.clean", "r");

    stoplist = fopen("../../../../partie1/code/StopList.txt", "r");



    // ouvrir le fichier en écriture
    texteTok = fopen("../../../../partie1/code/Indexation_texte/Nettoyer/fichier.tok", "w");

    fscanf(texteClean, "%s", token);


   while ( !feof(texteClean)) 
   {

        while (!feof(stoplist))
        {

            fscanf(stoplist, "%s", stopword);
            if(strlen(token) == strlen(stopword))
            {
                for(i=0; i < strlen(token);i++)
                {
                    if(token[i] == stopword[i])
                    {
                        cpt ++; 
                    }
                }
                if(cpt==strlen(token))
                {
                    verif = 1; 
                }
                cpt = 0;

            }
            if(verif==1)
            {
                break;
            }

        }

        fseek(stoplist, 0, SEEK_SET);


        if(verif != 1)
        {
            for(i=0; i < strlen(token);i++)
            {
                putc(token[i], texteTok);
            }
            putc(32, texteTok);
        }
        verif = 0;
        fscanf(texteClean, "%s", token);

    }

    //Fermer les 3 textes
    fclose(texteTok);
    fclose(stoplist);
    fclose(texteClean);
    

    while(sup)
    {
       sup = remove("../../../../partie1/code/Indexation_texte/Nettoyer/fichier.clean");

    }
    
}


