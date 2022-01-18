#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"



void affiche_ELEMENT(ELEMENT e){
	printf("%s ",e.nom);
	printf(" --> ");
	printf("%d \n", e.ressemblance);
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

ARBRE INIT_ARBRE(){
	return NULL;
}


void affiche_Arbre(ARBRE monArbre){
	if (monArbre!=NULL){

		//Affiche le sous arbre droit
		if(monArbre->sousArbreDroit!=NULL){
			affiche_Arbre(monArbre->sousArbreDroit);
		}
		
			
		//affiche la racine
		affiche_ELEMENT(monArbre->document);
		
		//affiche le sous arbre gauche
		if(monArbre->sousArbreGauche!=NULL){
			affiche_Arbre(monArbre->sousArbreGauche);
		
		}
		

	}
	
}


int EST_VIDE(ARBRE monArbre){
	return monArbre==NULL;
}



void ajout_dans_arbre(ARBRE* monArbre, ELEMENT doc){


	//on cherche où le placer dans l'arbre
	//si la valeur est inferieur à la racine du sous arbre, on part à gauche
	if (*monArbre!=NULL){
		if (compare_ELEMENT((*monArbre)->document,doc)){
			ajout_dans_arbre(&((*monArbre)->sousArbreDroit),doc);
		} else {
			ajout_dans_arbre(&((*monArbre)->sousArbreGauche),doc);
		}
	}
	
	//on cree la cellule et on la place 
	if (*monArbre==NULL){
	ARBRE sousArbre =(ARBRE) malloc(sizeof(CELLULE));
		if (sousArbre !=NULL){
			affect_ELEMENT(&(sousArbre->document),doc);
			sousArbre->sousArbreDroit=NULL;
			sousArbre->sousArbreGauche=NULL;
			*monArbre=sousArbre;
		}
	}
	
}











