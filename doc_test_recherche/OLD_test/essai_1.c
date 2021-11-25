// mix de test.c et reecriture_exemple_V2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    //creation des pointeurs pour acceder aux fichier
    FILE *ptrFichier1, *ptrFichier2;
    //nom du fichier
    char fichierTeste[] = "test.txt";
    char lettre;
    int del_line, temp = 1;

    ptrFichier1 = fopen(fichierTeste, "r");//on ouvre le fichier en lecture seul

    if(ptrFichier1 == NULL){// si le fichier est ouvert
        exit(1);
    }

    char texte[256];//nom du parametre
    char nomParam[256];
    int valeur = 0;// valeur du parametre
    int ligneASupprimer, numLigne = 0;
    int nouvelleValeur = 0;

    while(!feof(ptrFichier1)){//on affiche le fichier tant que EndOfFile est faux
        fscanf(ptrFichier1, "%s %d", texte, &valeur);
        printf("\n%s %d\n", texte, valeur);
    }
    
    //on demande la ligne ou le parametre doit etre changé
    printf("\n\nEntrer le parametre qui doit etre modifié : ");
    scanf("%s", nomParam);
    //mettre le "curseur" au debut du fichier
    rewind(ptrFichier1);

    ptrFichier2 = fopen("test_V2.txt", "w");//on ouvre le fichier de copy

    while(!feof(ptrFichier1)){//on affiche le fichier tant que EndOfFile est faux
        fscanf(ptrFichier1, "%s %d", texte, &valeur);// on lie dans le fichier d'origine

        int test = strcmp(texte, nomParam);
        if(test == 0){
            printf("Entrer la nouvelle valeur:");
            scanf("%d", &nouvelleValeur);
            fprintf(ptrFichier2, "%s %d", texte, nouvelleValeur);
            fscanf(ptrFichier1, "%s %d", texte, &valeur);
        }

        fprintf(ptrFichier2, "\n%s %d\n", texte, valeur);//on ecrit dans le nouveau fichier
    }




    fclose(ptrFichier1);
    fclose(ptrFichier2);
    


    ptrFichier1 = fopen("test_V2.txt", "r");//on ouvre le fichier de copy

    while(!feof(ptrFichier1)){//on affiche le fichier tant que EndOfFile est faux
        fscanf(ptrFichier1, "%s %d", texte, &valeur);
        printf("\n%s %d\n", texte, valeur);
    }

    fclose(ptrFichier1);

return 0;
}