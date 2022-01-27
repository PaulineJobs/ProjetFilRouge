
					/*-------------------------------------------/
					/        AUTEUR : JOBERT Pauline             /
                    /-------------------------------------------/
/ROLE : Construire une structure contenant le nom d'un fichier audio avec sa ressemblance avec un fichier de refence/
/Construire un système de classer des fichier  et de les afficher par ordre decroissant de ressemblance */


#ifndef MODULE_ARBRE  
#define MODULE_ARBRE

//Structure : fichier audio avec sa ressemblance avec un fichier de reference 
typedef struct fichier{
	char * nom;
	int ressemblance;
} ELEMENT	;

//fonction associees:
//Affiche une structure
void  affiche_ELEMENT(ELEMENT);
//affecte une structure à une autre
void affect_ELEMENT(ELEMENT*, ELEMENT);
//compare deux structures
int compare_ELEMENT(ELEMENT, ELEMENT);


//Arbre GRD contenant toutes les structures classees par ordre de ressemblance croissant 
typedef struct cellule{
	ELEMENT document;
	struct cellule* sousArbreDroit;
	struct cellule* sousArbreGauche;
} CELLULE;

typedef CELLULE* ARBRE;

//initialisation de l'arbre 
ARBRE INIT_ARBRE();
//Affiche  l'arbre dans l'odre décroissant de ressemblance
void affiche_Arbre(ARBRE);
//Renvoie 1 si l'arbre est vide
int EST_VIDE(ARBRE);
//Permet de placer une structure dans un arbre
void ajout_dans_arbre(ARBRE*,ELEMENT);



#endif
