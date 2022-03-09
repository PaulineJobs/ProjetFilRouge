#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <math.h>

#include "element.h"


//STRUCTURES

typedef struct CELLULEIm{
	ELEMENTIm element;
	struct CELLULEIm* suiv;
}CELLULEIm;

typedef struct MA_FILE{
	CELLULEIm* tete;
	CELLULEIm* queue;
}MA_FILE; 

//FOCNTIONS

MA_FILE INIT_FILE (MA_FILE file);
void AFFICHE_FILE (MA_FILE file);
int FILE_EST_VIDE(MA_FILE file);
MA_FILE ENFILER(ELEMENTIm elem, MA_FILE file);
MA_FILE DEFILER(ELEMENTIm* elem, MA_FILE file);
//MA_FILE SAISIR_FILE();
