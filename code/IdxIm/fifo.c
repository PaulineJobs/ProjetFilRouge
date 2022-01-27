#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "fifo.h"
#include "element.h"

MA_FILE INIT_FILE (MA_FILE file){
//déclarations locales

//fin déclarations

file.tete=NULL;
file.queue=NULL;

return file;

}

void AFFICHE_FILE (MA_FILE file){
//Déclarations locales

//fin déclarations

if(file.tete==NULL){
	printf ("file vide \n");
}
else{
	do{
		affiche_ELEMENTIm(file.tete->element);
		printf("\n");
		file.tete=file.tete->suiv;				
	}while(file.tete!=NULL);

}

}

int FILE_EST_VIDE(MA_FILE file){
//déclarations locales

//fin déclarations

if(file.tete==NULL){
	return 1;
}else{
	return 0;
}

}

MA_FILE ENFILER(ELEMENTIm elem, MA_FILE file){
//déclarations locales
int estVide;
//fin déclarations
	estVide=FILE_EST_VIDE(file);
	CELLULEIm* cel = (CELLULEIm*)malloc(sizeof(CELLULEIm));
	if(cel!=NULL){
		cel->element=elem;
		cel->suiv=NULL;

		
		if(estVide==1){
			file.tete=cel;
			file.queue= cel;
		}
		else{	
			file.queue->suiv = cel;
			file.queue=cel;
		}
	}
	else{
		printf("erreur malloc");
	}	

	return file;

}

MA_FILE DEFILER(ELEMENTIm* elem, MA_FILE file){
//déclarations locales
int estVide;
CELLULEIm* ptrCel;
//fin déclarations

estVide=FILE_EST_VIDE(file);
if(estVide==0){
	ptrCel=file.tete;
	*elem=file.tete->element;

	file.tete=file.tete->suiv;
	free(ptrCel);
}
else{
	printf("file vide \n \r");
}

return file;

}


/*

MA_FILE SAISIR_FILE(){
//déclarations locales
ELEMENT elem;
int taille;
int cpt;
MA_FILE file;
//fin déclarations
file=INIT_FILE(file);

printf("choisir la taille de votre file : ");
scanf("%d",&taille);
for(cpt=0;cpt<taille;cpt++){
	printf(" valeur %d : ", cpt+1);
	elem=saisir_ELEMENT();
	file=ENFILER(elem, file);
}

return file;
}
*/
































