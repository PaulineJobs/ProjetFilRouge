//Antoine LEVANEN
//test lecture du fichier config
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    FILE * monfichier =NULL;    //ptr pour l'acces au fichier
    monfichier=fopen("config.txt","r+"); //on ouvre le fichier
    
    //variables

    char texte[256];
    char param[] = "stoplist";
    int valeurParam = 0;

    //si le fichier n'a pas ete ouvert, on arrete tous!
    if(monfichier==NULL){
        exit(1);
        }

    //on lie la 1er ligne

    fscanf(monfichier, "%s %d", texte, &valeurParam);
    printf("%s\n",texte);           //on affiche le resutat
    printf("%d\n",valeurParam);
   
    printf("position: %ld \n", ftell(monfichier));
    fseek(monfichier, 29, SEEK_SET);
    printf("position: %ld \n", ftell(monfichier));

    fputs("2", monfichier);

    /*while(fgets(texte, 255, monfichier) != NULL){
        
        fscanf(monfichier, "%s %d", texte, &valeurParam);

        if((strcmp(texte, param)) == 0){
            printf("%s",texte);
        }
        
        //printf("%s", texte);
    }*/
    

    fclose(monfichier);
    

    
    return 0;
}