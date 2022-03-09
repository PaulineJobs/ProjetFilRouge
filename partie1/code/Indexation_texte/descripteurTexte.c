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
#include "../Configuration/configuration.h"


void copieTexteTok(void)//Mettre en paramettre d'entré le nom du fichier choisit
{
    FILE *texteTok, *copie;
    char var;
  
    // ouvrir le fichier en lecture
    
    texteTok = fopen("../Indexation_texte/Nettoyer/fichier.tok", "r");

    // ouvrir le fichier en écriture
    copie = fopen("../Indexation_texte/Nettoyer/copieTexteSansStopword.tok", "w");
  
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

void comptage(char* NomFichier) //Mettre en paramettre d'entré le nom du fichier choisit
{

    ///////////////// variables ////////////////////////
    FILE *mot, *descripteur, *texteTokCopie;
    char token[500], synonyme[500], chaine[5];
    char motId[500][500];
    int nbtokens = 0;
    int cpt = 0;
    int cpt2 = 0;
    int termesRetenus = 0;
    int diz = 0;
    int unit =0;
    int cent = 0;
    int sup =1;
    int sup2 =1;
    int nbOcc= 0;
    int verif = 0;
    char nbOccChar, id, nomfile;
    int i, j;


    /////////////// fichiers //////////////////
  
    // ouvrir les fichiers en lecture
    mot = fopen("../Indexation_texte/Nettoyer/fichier.tok", "r");
    texteTokCopie = fopen("../Indexation_texte/Nettoyer/copieTexteSansStopword.tok", "r");

    // ouvrir le fichier en écriture
    char *emplacement=(char *)malloc(strlen("../../Base_descripteurs/Base_descripteurs_textes/")+strlen("_descripteur.txt")+strlen(NomFichier)+1);
    strcpy(emplacement,"../../Base_descripteurs/Base_descripteurs_textes/");
    
    strcat(emplacement,NomFichier);
    strcat(emplacement,"_descripteur.txt");
    descripteur = fopen(emplacement, "w");


    ///////// recup id ////////

    recupId(NomFichier, chaine);
    for(i=0; i < 2;i++) //Copie du mot dans le descripteur
    {
        putc(chaine[i], descripteur);
    }
    putc('\n', descripteur);


    ////////////////////////// recup la valeur de la config ///////////////////

    int n;    
    char param[]="nbrOccurence";

    n=config(param);

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

            if (nbOcc > n) // si le mot apparait plus de 3 fois dans le texte, on le met dans le descripteur
            {
                for(i=0; i < strlen(token);i++) //Copie du mot dans le descripteur
                {
                    putc(token[i], descripteur);
                }
                putc(' ', descripteur);

                if(nbOcc>99)
                {
                    cent = nbOcc/100;
                    putc((cent+'0'), descripteur);
                    diz = (nbOcc/10)-(cent*100);
                    putc((diz+'0'), descripteur);
                    unit = nbOcc-(diz*10);
                    putc((unit+'0'), descripteur);

                } 
                else if(nbOcc>9)
                {
                    diz = nbOcc/10;
                    putc((diz+'0'), descripteur);
                    unit = nbOcc-(diz*10);
                    putc((unit+'0'), descripteur);
                }
                else
                {
                    nbOccChar = nbOcc +'0'; // Convertit int en char
                    putc(nbOccChar, descripteur);
                }

                putc('\n', descripteur);

                termesRetenus++; //Incremente du nombre de termes retenus dans le descripteur

            }

            nbOcc= 0; 
            unit =0;
            diz =0;  
            cent = 0;         
        }

        verif = 0;
        fscanf(mot, "%s", token); //on prend le mot suivant dans le texte
        fseek(texteTokCopie, 0, SEEK_SET);//replace le curseur au début du texte de recherche de synonyme

            

    }

    
    //Ajout du nombre de terme dans le descripteur
    putc('\n', descripteur);
    if(termesRetenus>9)
    {
        diz = termesRetenus/10;
        putc((diz+'0'), descripteur);
        unit = termesRetenus-(diz*10);
        putc((unit+'0'), descripteur);
    }
    else
    {
        putc(termesRetenus +'0', descripteur);
    }
    putc('\n', descripteur);

    unit = diz = 0;

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

    while(sup || sup2)
    {
       sup = remove("../Indexation_texte/Nettoyer/copieTexteSansStopword.tok");
       sup2 = remove ("../Indexation_texte/Nettoyer/fichier.tok");
    }
  
    
}


void miseAJourListeDescripteurstextes(char* nomFichierParam){
	FILE* listeDescripteurs;
	listeDescripteurs=fopen("../../Liste_descripteurs/Liste_descripteurs_textes.txt","a");
	fprintf(listeDescripteurs,"%s \n",nomFichierParam);
	//fprintf(listeDescripteurs,"\n");
	fclose(listeDescripteurs);
	
}

void traitementTexte(char* NomFichier)
{
	
    ///////// fonction bilan de l'indexation texte///////
    
    Nettoyage(NomFichier);
    passageCleanTok();
    copieTexteTok();
    comptage(NomFichier);
    miseAJourListeDescripteurstextes(NomFichier);

}
