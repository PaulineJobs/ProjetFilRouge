//lecture et ecriture du fichier de configuration!
//BELLER Willy LEVANEN Antoine

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include "configuration.h"

/*
editConfig() permet de modifier un parameter dans le .config
la fonction demande le numéro de la ligne où se trouve le paramètre choisi
puis la nouvelle valeur
*/
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
    char nouvelleValeur[10];//récupère la saisi utilisateur
    int nbrLigne = 0;//nombre de ligne dans le .config (pour l'affichage)


    fscanf(ptrFichier1, "%d %s %d", &numLigne, texte, &nbrLigne);

    for(int i=0; i<(nbrLigne - 1); i++){//on affiche le fichier
        fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &valeur);// // on lie le nom du paramètre et sa valeur
        printf("\n%d %s %d\n",numLigne, texte, valeur);// on affiche dans le terminal
    }

    //vérification de la saisie  //(ne prend en compte que le 1er char saisie, exemple, si "45" est saisie, le parametre 4 sera modifié) //(élimine cependant toute saisie de char autre que des chiffre)
    char testNumLigne[2];
    do{
        rewind(ptrFichier1);
        __fpurge(stdin);
        printf("\n\nEntrez le numéro du paramètre qui doit être modifié : ");
        fgets(testNumLigne, sizeof testNumLigne, stdin);

        __fpurge(stdin);//On purge le stdin si la saisie est trop longue

    }   while(atoi(testNumLigne)<2 || atoi(testNumLigne)>nbrLigne);

    int newNumLigne = atoi(testNumLigne);

    ptrFichier2 = fopen("../Configuration/.config~", "w");//on ouvre le fichier de copie 

    while(fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &valeur)!=EOF){ // on lit dans le fichier d'origine

        if(newNumLigne == numLigne){
            do{
                printf("Entrez la nouvelle valeur pour le paramètre n° %d : ",newNumLigne);
                fgets(nouvelleValeur, sizeof nouvelleValeur, stdin);
            }   while(atoi(nouvelleValeur) == atoi("n"));
            fprintf(ptrFichier2, "%d %s %d\n",numLigne, texte, atoi(nouvelleValeur));// on ecrit dans le fichier 2 le nom du parametre + ça new value
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
    for(int i=0; i<(nbrLigne - 1); i++){  //on affiche le fichier
       fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &valeur);
       printf("\n%d %s %d\n",numLigne, texte, valeur);
    }

    fclose(ptrFichier1);//on ferme le fichier

    return 0;
}

//------------------------------------------------------------------------------------

/*
config(char nom[]) prend en paramètre le nom du paramètre au quel on veut récupérer la valeur
la fonction renvoie un entier
*/
int config(char nom[]){
    int valeur, numLigne, nbrLigne = 0;
    char nomFichier[] = "../Configuration/.config";//chemin d'accès au .config
    char texte[256];

    FILE *ptrFichier1;
    ptrFichier1 = fopen(nomFichier, "r");//ouverture du fichier en lecture seul

    if(ptrFichier1 == NULL){// si le fichier n'est pas ouvert on sort de la fonction
        printf("Erreur, ouverture du fichier de configuration imposible");
        return -1;
    }
    fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &nbrLigne);
    for(int i=0; i<(nbrLigne - 1); i++){
        fscanf(ptrFichier1, "%d %s %d",&numLigne, texte, &valeur);// on lie le nom du paramètre et sa valeur
        if((strcmp(texte, nom)) == 0){//si on trouve un correspondance
            fclose(ptrFichier1);
            return valeur;//on retourne la valeur
        }
    }
    fclose(ptrFichier1);
    return -1;
}

//test unitaire
/*
int main(){
    editConfig();
    int parametre = config("max");
    printf("la valeur est: %d\n", parametre);
    return 0;
}
*/
