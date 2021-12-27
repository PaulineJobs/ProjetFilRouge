#ifndef MODULE_ARBRE  
#define MODULE_ARBRE


typedef struct fichier{
	char * nom;
	int ressemblance;
} ELEMENT	;


void  affiche_ELEMENT(ELEMENT);
void affect_ELEMENT(ELEMENT*, ELEMENT);
int compare_ELEMENT(ELEMENT, ELEMENT);


typedef struct cellule{
	ELEMENT document;
	struct cellule* sousArbreDroit;
	struct cellule* sousArbreGauche;
} CELLULE;

typedef CELLULE* ARBRE;

ARBRE INIT_ARBRE();
void affiche_Arbre(ARBRE);
int EST_VIDE(ARBRE);
void ajout_dans_arbre(ARBRE*,ELEMENT);



#endif
