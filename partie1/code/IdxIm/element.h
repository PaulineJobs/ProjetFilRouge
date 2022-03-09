#ifndef element_h
#define element_h


/*
typedef struct ELEMENT{
	int bit8;
	int bit7;
	int bit6;
}ELEMENT;
*/
typedef int ELEMENTIm;

void affiche_ELEMENTIm(ELEMENTIm e);
ELEMENTIm saisir_ELEMENTIm();
ELEMENTIm affect_ELEMENTIm(ELEMENTIm *e, float val);
int compare_ELEMENTIm(ELEMENTIm e, ELEMENTIm e2);

#endif
