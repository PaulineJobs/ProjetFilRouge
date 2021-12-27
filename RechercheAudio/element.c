#include <stdio.h>
#include <stdlib.h>
#include "element.h"

void affiche_ELEMENT(ELEMENT e){
	printf("%s ",e.nom);
	printf(" --> ");
	printf("%d\n", e.ressemblance);
}


//on affecte la valeur e2 à e1
void affect_ELEMENT(ELEMENT* e1, ELEMENT e2){
	e1->ressemblance=e2.ressemblance;
	e1->nom=e2.nom;
}

//return 1 si e1<e2
int compare_ELEMENT(ELEMENT e1, ELEMENT e2){
	if (e1.ressemblance<=e2.ressemblance){
		return 1;
	}else {
		return 0;
	}
}
