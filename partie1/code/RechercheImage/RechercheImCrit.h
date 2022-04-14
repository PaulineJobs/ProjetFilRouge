#ifndef RECHERCHE_IMAGE_CRIT_H
#define RECHERCHE_IMAGE_CRIT_H

#include "../RechercheAudio/arbre.h"

float critere(char* nomFichier,char choix);
void IHMCrit();





//Pour la JNI
//prends en parametre R, V ou B et renvoie la recherche par critères
char*recherchCritere(char choix);

#endif
