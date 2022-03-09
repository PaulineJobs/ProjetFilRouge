/*
Fichier réalisé par : Manon COUFFIN
Derniere modif le : 04/12/2021
Lier aux fichiers : tstNettoyageTexte.c et nettoyageTexte.c
*/

#ifndef NETTOYAGETEXTE_H 
#define NETTOYAGETEXTE_H

#include <stdio.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void passageXmlClean(char *);

void majMin();

void suppressionBalise();

void espaceApostrophe();

void Nettoyage();

#endif
