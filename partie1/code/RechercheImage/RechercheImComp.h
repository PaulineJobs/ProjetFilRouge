#ifndef RECHERCHE_IMAGE_COMP_H
#define RECHERCHE_IMAGE_COMP_H
#include "../RechercheAudio/arbre.h"

float comparaison(char* , char*,int type );
ARBRE comparaisonRepertoireIm(char * fichierReference, char type);
void saisieRechercheImgComp();
void afficherResultat(ARBRE ensembleFichiers);


//Pour la JNI
//Prends en paramètre le nom du fichier de ref et le type de l'image (1 RVB, 2 NB) et renvoie les resultats
char* RechercheImgComp(char* souhait,char* typeIm);

#endif
