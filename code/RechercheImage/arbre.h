#ifndef MODULE_ARBRE  
#define MODULE_ARBRE

typedef struct fichier{
	char * nom;
	int ressemblance;
} ELEMENTR	;


void  affiche_ELEMENTR(ELEMENTR);
void affect_ELEMENTR(ELEMENTR*, ELEMENTR);
int compare_ELEMENTR(ELEMENTR, ELEMENTR);


typedef struct cellule{
	ELEMENTR document;
	struct cellule* sousArbreDroit;
	struct cellule* sousArbreGauche;
} CELLULE;

typedef CELLULE* ARBRE;

ARBRE INIT_ARBRE();
void affiche_Arbre(ARBRE);
int EST_VIDE(ARBRE);
void ajout_dans_arbre(ARBRE*,ELEMENTR);



#endif
