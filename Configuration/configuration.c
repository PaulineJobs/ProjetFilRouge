//lecture et ecriture du fichier de configuration!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "configuration.h"

int editConfig(){
    //creation de pointeur pour acceder au fichier
    FILE *ptrFichier1, *ptrFichier2;
    //nom du fichier
    char fichierTeste[] = "../Configuration/.config";//nom du fichier (ou bien chemin d'acces

    ptrFichier1 = fopen(fichierTeste, "r");//on ouvre le fichier en lecture seul

    if(ptrFichier1 == NULL){// si le fichier n'est pas ouvert on arret tout!
        exit(1);
    }

    int numLigne = 0;//numero de la ligne de lecture
    char texte[256];//nom du parametre rechercher
    int valeur = 0;// valeur du parametre
    int nouvelleValeur = 0;
    int nbrLigne = 0;


    fscanf(ptrFichier1, "%d %s %d", &numLigne, texte, &nbrLigne);

    for(int i=0; i<(nbrLigne - 1); i++){//on affiche le fichier tant que EndOfFile est faux
        fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &valeur);// on lie le nom et la valeur
        printf("\n%d %s %d\n",numLigne, texte, valeur);// on affiche dans le terminal
    }

    //vérification de la saisie
    do{
        rewind(ptrFichier1);
        printf("\n\nEntrer le numero du parametre qui doit etre modifié : ");
        scanf("%d", &numLigne);
        
    }   while(numLigne<0 || numLigne>=nbrLigne);
    int newNumLigne = numLigne;


    ptrFichier2 = fopen("../Configuration/.config~", "w");//on ouvre le fichier de copie 


    for(int i=0; i<(nbrLigne-1); i++){
        fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &valeur);// on lie dans le fichier d'origine

        if(newNumLigne == numLigne){
            printf("Entrer la nouvelle valeur:");
            scanf("%d", &nouvelleValeur);
            fprintf(ptrFichier2, "%d %s %d\n",numLigne, texte, nouvelleValeur);// on ecrit dan le fichier 2 le nom du parametre + ça new value
            fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &valeur);//on passe l'ancienne valeur du parametre
        }

        fprintf(ptrFichier2, "%d %s %d\n",numLigne, texte, valeur);// on ecrit dan le fichier 2 le nom du parametre + ça new value
    }

    fclose(ptrFichier1);//on ferme les fichiers
    fclose(ptrFichier2);
    
    //on supprime le fichier 1
    //on renome le fichier 2 en fichier 1!

   remove("../Configuration/.config");
   rename("../Configuration/.config~", "../Configuration/.config");
    // on affiche le nouveau test_V2.txt dans le terminal (pour les tests)
    ptrFichier1 = fopen("../Configuration/.config", "r");//on ouvre le fichier de copy
    

    //juste pour l'affichage :
    nbrLigne++;
    for(int i=0; i<(nbrLigne - 1); i++){  //on affiche le fichier tant que EndOfFile est faux
       fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &valeur);
       printf("\n%d %s %d\n",numLigne, texte, valeur);
    }

    fclose(ptrFichier1);//on ferme le fichier

    return 0;
}

//------------------------------------------------------------------------------------


int config(char nom[]){
    int valeur, numLigne, nbrLigne = 0;
    char nomFichier[] = "../Configuration/.config";
    char texte[256];

    FILE *ptrFichier1;
    ptrFichier1 = fopen(nomFichier, "r");//ouverture du fichier en lecture seul

    if(ptrFichier1 == NULL){// si le fichier n'est pas ouvert on arret tout!
        exit(1);//
    }
    fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &nbrLigne);
    for(int i=0; i<(nbrLigne - 1); i++){
        fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &valeur);// on lie le nom et la valeur
        if((strcmp(texte, nom)) == 0){
            fclose(ptrFichier1);
            return valeur;
        }
    }
    fclose(ptrFichier1);
    return -1;
}


int main(){
    //editConfig();
    int parametre = config("max");
    printf("la valeur est: %d\n", parametre);
    return 0;
}

//si changement ds .config -> supprimer ts les fichiers ds les dossiers
//eventuellement faire un fichier par defaut si le .config est erroné