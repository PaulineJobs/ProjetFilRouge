//Antoine LEVANEN
//fonctions pour la lecture du fichier config
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char param = 't'; //t = taille max token


int lecture(char a[256]){
    FILE * monfichier =NULL;
    monfichier=fopen("config.txt","r+");
    
    char texte[256];

    if(monfichier==NULL){
        exit(1);
        }

    while(fgets(texte, 255, monfichier) != NULL){
        printf("%s", texte);
    }
    
    fclose(monfichier);
    
    return 0;
}
