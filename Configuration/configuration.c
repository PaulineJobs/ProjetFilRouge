//lecture et ecriture du fichier de configuration!

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "configuration.h"

int editConfig(){
    //creation de pointeur pour acceder au fichier
    FILE *ptrFichier1, *ptrFichier2;
    //nom du fichier
    char fichierTeste[] = "../Configuration/.config";//nom du fichier (ou bien chemin d'acces)

    ptrFichier1 = fopen(fichierTeste, "r");//on ouvre le fichier en lecture seul

    if(ptrFichier1 == NULL){// si le fichier n'est pas ouvert on arrete tout!
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

    //vérification de la saisie  //(ne prend en compte que le 1er char saisie, exemple, si "45" est saisie, le parametre 4 sera modifié) //(élimine cependant toute saisie de char autre que des chiffre)
    char testNumLigne[2];
    do{
        rewind(ptrFichier1);
        __fpurge(stdin);
        printf("\n\nEntrez le numéro du paramètre qui doit être modifié : ");
        fgets(testNumLigne, sizeof testNumLigne, stdin);

        if(!atoi(testNumLigne)){
            __fpurge(stdin); //On purge le stdin si la saisie est trop longue
        }
        __fpurge(stdin);

    }   while(atoi(testNumLigne)<2 || atoi(testNumLigne)>nbrLigne);

    int newNumLigne = atoi(testNumLigne);

    ptrFichier2 = fopen("../Configuration/.config~", "w");//on ouvre le fichier de copie 

    while(fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &valeur)!=EOF){ // on lit dans le fichier d'origine

        if(newNumLigne == numLigne){
            printf("Entrez la nouvelle valeur pour le paramètre n° %d : ",newNumLigne);
            scanf("%d", &nouvelleValeur);
            fprintf(ptrFichier2, "%d %s %d\n",numLigne, texte, nouvelleValeur);// on ecrit dans le fichier 2 le nom du parametre + ça new value
            fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &valeur);//on passe l'ancienne valeur du parametre
        }

        fprintf(ptrFichier2, "%d %s %d\n",numLigne, texte, valeur);// on ecrit dans le fichier 2 le nom du parametre + ça new value
    }

    fclose(ptrFichier1);//on ferme les fichiers
    fclose(ptrFichier2);
    
    //on supprime le fichier 1
    //on renomme le fichier 2 en fichier 1!

   remove("../Configuration/.config");
   rename("../Configuration/.config~", "../Configuration/.config");
    // on affiche le nouveau test_V2.txt dans le terminal (pour les tests)
    ptrFichier1 = fopen("../Configuration/.config", "r");//on ouvre le fichier de copie
    

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

    if(ptrFichier1 == NULL){// si le fichier n'est pas ouvert on arrete tout!
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

/*
int main(){
    editConfig();
    int parametre = config("max");
    printf("la valeur est: %d\n", parametre);
    return 0;
}
*/
