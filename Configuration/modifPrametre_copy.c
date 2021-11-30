//lecture et ecriture du fichier de configuration!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    editConfig();
}

int editConfig(){
        //creation des pointeurs pour acceder aux fichiers
    FILE *ptrFichier1, *ptrFichier2;
    //nom du fichier
    char fichierTeste[] = "../Configuration/.config";//nom du fichier (ou bien chemin d'acces)
    char lettre;
    int del_line, temp = 1;
    

    ptrFichier1 = fopen(fichierTeste, "r");//on ouvre le fichier en lecture seul

    if(ptrFichier1 == NULL){// si le fichier n'est pas ouvert on arret tout!
        exit(1);
    }

    char texte[256];//nom du parametre rechercher
    char nomParam[256];
    int valeur = 0;// valeur du parametre
    int ligneASupprimer, numLigne = 0;
    int nouvelleValeur = 0;
    int nbrLigne = 0;

    fscanf(ptrFichier1, "%s %d", texte, &nbrLigne);

    for(int i=0; i<(nbrLigne - 1); i++){//on affiche le fichier tant que EndOfFile est faux
        fscanf(ptrFichier1, "%s %d", texte, &valeur);// on lie le nom et la valeur
        printf("\n%s %d\n", texte, valeur);// on affiche dans le terminal
    }

    //on demande le nom du parametre qui doit etre modifié
//---------------------------------------------------------------------------------------------------

    int pala = 0;
    do{
        rewind(ptrFichier1);
        printf("\n\nEntrer le parametre qui doit etre modifié : ");
        scanf("%s", nomParam);
        for(int i=0; i<nbrLigne; i++){//faire tant que EndOfFile est faux
            fscanf(ptrFichier1, "%s %d", texte, &valeur);// on lie dans le fichier d'origine
            int test2 = strcmp(texte, nomParam);
            if(test2 == 0){
                pala = 1;
            }else{
                pala = 0;
            }
        }
    }   while(pala==0);


//---------------------------------------------------------------------------------------------------


    printf("\n\nEntrer le parametre qui doit etre modifié : ");
    scanf("%s", nomParam);
    //mettre le "curseur" au debut du fichier 1
    rewind(ptrFichier1);
    while(strcmp(texte, nomParam) != 0){
        printf("Entrer la nouvelle valeur:");
        scanf("%d", &nouvelleValeur);
    }

    ptrFichier2 = fopen("../Configuration/.config~", "w");//on ouvre le fichier de copie 

//faire une boucle while pour tester la saisie
    for(int i=0; i<nbrLigne; i++){//faire tant que EndOfFile est faux
        fscanf(ptrFichier1, "%s %d", texte, &valeur);// on lie dans le fichier d'origine

        int test = strcmp(texte, nomParam);// si le parametre lu est identique au parametre demandé test = 0
        if(test == 0){
            printf("Entrer la nouvelle valeur:");
            scanf("%d", &nouvelleValeur);
            fprintf(ptrFichier2, "%s %d\n", texte, nouvelleValeur);// on ecrit dan le fichier 2 le nom du parametre + ça new value
            fscanf(ptrFichier1, "%s %d", texte, &valeur);//on passe l'ancienne valeur du parametre
        }

        fprintf(ptrFichier2, "%s %d\n", texte, valeur);//on ecrit dans le nouveau fichier les autres parametre
    }

    fclose(ptrFichier1);//on ferme les fichiers
    fclose(ptrFichier2);
    
    /*
    on supprime le fichier 1
    on renome le fichier 2 en fichier 1!
    */

   remove("../Configuration/.config");
   rename("../Configuration/.config~", "../Configuration/.config");
    // on affiche le nouveau test_V2.txt dans le terminal (pour les tests)
    ptrFichier1 = fopen("../Configuration/.config", "r");//on ouvre le fichier de copy
    

    //juste pour l'affichage :
    nbrLigne++;
    for(int i=0; i<(nbrLigne - 1); i++){  //on affiche le fichier tant que EndOfFile est faux
       fscanf(ptrFichier1, "%s %d", texte, &valeur);
       printf("\n%s %d\n", texte, valeur);
    }

    fclose(ptrFichier1);//on ferme le fichier

    return 0;
}