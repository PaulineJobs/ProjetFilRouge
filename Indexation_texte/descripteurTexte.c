/*
Fichier réalisé par : Manon COUFFIN
Derniere modif le : 19/01/2022
Lier aux fichiers : nettoyageTexte.c et nettoyageTexte.c, filtrageTexte.c, filtrageTexte.h, tstDescripteurTexte.c et descripteurTexte.h
*/

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "descripteurTexte.h"
#include "nettoyageTexte.h"
#include "filtrageTexte.h"


void copieTexteTok(void)//Mettre en paramettre d'entré le nom du fichier choisit
{
    FILE *texteTok, *copie;
    char var;
  
    // ouvrir le fichier en lecture
    texteTok = fopen("Nettoyer/03-Des_chercheurs_parviennent_a_regenerer.tok", "r");

    // ouvrir le fichier en écriture
    copie = fopen("Nettoyer/copieTexteSansStopword.tok", "w");
  
    // Lire le contenu du fichier et le recopier dans un nouveau
    while((var = getc(texteTok)) != EOF)
        putc(var, copie);
  
    //Fermer les 2 textes
    fclose(texteTok);
    fclose(copie);
}

void recupId(char* fileName, char* theFileName){
   //déclarations locales
   int quitter = 0;
   int cpt =0; //strlen(fileName);
   char caractere;
   int cpt1 = 0;
   //fin déclarations locales

   while(!quitter) {
        caractere = fileName[cpt];
        cpt++;
        if(caractere != '-') 
        {
            theFileName[cpt1] = caractere;
            cpt1++;
        }
        else
            quitter = 1;
   }
}

void comptage(void) //Mettre en paramettre d'entré le nom du fichier choisit
{

    ///////////////// variables ////////////////////////
    FILE *mot, *descripteur, *texteTokCopie;
    char token[500], synonyme[500], chaine[5];
    int nbtokens = 0;
    char motId[500][500];
    int cpt = 0;
    int cpt2 = 0;
    int i, j;
    int nbOcc= 0;
    int verif = 0;
    char nbOccChar;
    char id, nomfile;
    int termesRetenus = 0;


    /////////////// fichiers //////////////////
  
    // ouvrir les fichiers en lecture
    mot = fopen("Nettoyer/03-Des_chercheurs_parviennent_a_regenerer.tok", "r");
    texteTokCopie = fopen("Nettoyer/copieTexteSansStopword.tok", "r");

    // ouvrir le fichier en écriture
    descripteur = fopen("Nettoyer/descripteur.txt", "w");


    ///////// recup id ////////

    recupId("03-Des_chercheurs_parviennent_a_regenerer.tok", chaine);
    for(i=0; i < 2;i++) //Copie du mot dans le descripteur
    {
        putc(chaine[i], descripteur);
    }
    putc('\n', descripteur);

    /////////////// fonctions /////////////////

   
   fscanf(mot, "%s", token); //affecte à token le premier mot du texte.clean

   while ( !feof(mot)) //lecture jusqu'à la fin du fichier
   {
       j = 0; // init du compteur;
       while (j <= nbtokens)
       {
            for(i=0; i < strlen(token);i++)
            {
                if(token[i] == motId[j][i])//Compare les lettres une à une
                {
                    cpt ++; 
                }
            }
            if(cpt==strlen(token))//si toutes les lettres sont egales verif prend 1
            {
                verif = 1; 
            }
            cpt = 0;
            if(verif==1)//si le mot a déja été traité
            {
                break;//on quitte la boucle de comparaison
            }

            j++;
       }

        if(verif != 1)
        {
            //affectation du nouveau mot au tableau motID
            for(i=0;i<strlen(token);i++)
            {
                motId[nbtokens][i] = token[i];
            }
            nbtokens++; //on rajoute une ligne a notre tableau modId
            
            fscanf(texteTokCopie, "%s", synonyme); //affecte à token le premier mot du texte copier

            while ( !feof(texteTokCopie)) //lecture jusqu'à la fin du fichier
            {

                if(strlen(synonyme) == strlen(token))//On compare la taille des 2 mots afin de savoir si ils sont identiques
                {
                    for(i=0; i < strlen(synonyme);i++)
                    {
                        if(synonyme[i] == token[i])//on compare les lettres une à une
                        {
                            cpt2 ++; 
                        }
                    }

                    if(cpt2==strlen(synonyme))//si toutes les lettres sont egales verif prend 1
                    {
                        nbOcc++;
                    }
                    cpt2 = 0;

                }
                fscanf(texteTokCopie, "%s", synonyme); //on prend le mot suivant dans le texte de copie

            }   


            ////////////// recopie dans le descripteur /////////////

            if (nbOcc>= 3) // si le mot apparait plus de 3 fois dans le texte, on le met dans le descripteur
            {
                for(i=0; i < strlen(token);i++) //Copie du mot dans le descripteur
                {
                    putc(token[i], descripteur);
                }
                putc(' ', descripteur);
                nbOccChar = nbOcc +'0'; // Convertit int en char
                putc(nbOccChar, descripteur);
                putc('\n', descripteur);

                termesRetenus++; //Incremente du nombre de termes retenus dans le descripteur

            }

            nbOcc= 0;            
        }

        verif = 0;
        fscanf(mot, "%s", token); //on prend le mot suivant dans le texte
        fseek(texteTokCopie, 0, SEEK_SET);//replace le curseur au début du texte de recherche de synonyme

            

    }

    
    //Ajout du nombre de terme dans le descripteur
    putc('\n', descripteur);
    sprintf(chaine, "%d", termesRetenus);
    for(i=0; i < 2;i++) //Copie du mot dans le descripteur
    {
        putc(chaine[i], descripteur);
    }
    putc('\n', descripteur);

    //Ajout du nombre total de token dans le descripteur
    putc('\n', descripteur);
    sprintf(chaine, "%d", nbtokens);
    for(i=0; i < 3;i++) //Copie du mot dans le descripteur
    {
        putc(chaine[i], descripteur);
    }
    putc('\n', descripteur);

  
    //Fermer les 2 textes
    fclose(descripteur);
    fclose(texteTokCopie);
    fclose(mot);

    // supression du fichier copier
    int sup = remove("Nettoyer/copieTexteSansStopword.tok");
}

void traitementTexte()
{

    ///////// fonction bilan de l'indexation texte///////
    
    Nettoyage();
    passageCleanTok();
    copieTexteTok();
    comptage();

}