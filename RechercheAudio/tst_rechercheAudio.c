#include <stdio.h>
#include <stdlib.h>
#include "rechercheAudio.h"
#include "arbre.h"


int main(){
	//IHM();
	//comparaisonRepertoire("../Base_descripteurs/Base_descripteurs_audios/jingle_fi_descripteur.txt");
	//comparaisonRepertoire("../Base_descripteurs/Base_descripteurs_audios/corpus_fi_descripteur.txt");
	//comparaison("../Base_descripteurs/Base_descripteurs_audios/jingle_fi_descripteur.txt","../Base_descripteurs/Base_descripteurs_audios/jingle_fi_descripteur.txt");
	float valeur=comparaison("../Base_descripteurs/Base_descripteurs_audios/test1_descripteur.txt","../Base_descripteurs/Base_descripteurs_audios/test_descripteur.txt");
	printf("%f",valeur);
	return 0;
}
