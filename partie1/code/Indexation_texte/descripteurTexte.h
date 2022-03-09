/*
Fichier réalisé par : Manon COUFFIN
Derniere modif le : 19/01/2022
Lier aux fichiers : tstDescripteurTexte.c et descripteurTexte.c
*/

#ifndef DESCRIPTEURTEXTE_H 
#define DESCRIPTEURTEXTE_H

#include <stdio.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

//variables globales

void copieTexteTok(void);
void comptage(char* NomFichier);
void traitementTexte();
void recupId(char* fileName, char* theFileName);
void miseAJourListeDescripteurstextes(char* nomFichierParam);

#endif
