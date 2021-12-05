#include <stdio.h>
#include <stdlib.h>
#include "histogramme_audio.h"
#include "descripteur_audio.h"

int main (){
	int m=50;
	//n ne peux pas etre superieur au nombre de valeur dans le fichier 
	int n=5000;
	descripteurAudio(m,n);
	return 0;
}
