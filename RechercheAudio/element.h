#ifndef MODULE_ELEM
#define MODULE ELEM

typedef struct fichier{
	char * nom;
	int ressemblance;
} ELEMENT	;


void  affiche_ELEMENT(ELEMENT);
void affect_ELEMENT(ELEMENT*, ELEMENT);
int compare_ELEMENT(ELEMENT, ELEMENT);


#endif
