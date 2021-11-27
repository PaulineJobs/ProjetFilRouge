// mix de test.c et reecriture_exemple_V2.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    //creation des pointeurs pour acceder aux fichiers
    FILE *ptrFichier1, *ptrFichier2;
    //nom du fichier
    char fichierTeste[] = "config.txt";//nom du fichier (ou bien chemin d'acces)
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

    while(!feof(ptrFichier1)){//on affiche le fichier tant que EndOfFile est faux
        fscanf(ptrFichier1, "%s %d", texte, &valeur);// on lie le nom et la valeur
        printf("\n%s %d\n", texte, valeur);// on affiche dans le terminal
    }
    
    //on demande le nom du parametre qui doit etre changé
    printf("\n\nEntrer le parametre qui doit etre modifié : ");
    scanf("%s", nomParam);
    //mettre le "curseur" au debut du fichier 1
    rewind(ptrFichier1);

    ptrFichier2 = fopen("config_V2.txt", "w");//on ouvre le fichier de copie 

    while(!feof(ptrFichier1)){//faire tant que EndOfFile est faux
        fscanf(ptrFichier1, "%s %d", texte, &valeur);// on lie dans le fichier d'origine

        int test = strcmp(texte, nomParam);// si le parametre lu est identique au parametre demandé test = 0
        if(test == 0){
            printf("Entrer la nouvelle valeur:");
            scanf("%d", &nouvelleValeur);
            fprintf(ptrFichier2, "%s %d new\n", texte, nouvelleValeur);// on ecrit dan le fichier 2 le nom du parametre + ça new value
            printf("%s %d old\n", texte, valeur);//on passe l'ancienne valeur du parametre
            //fscanf(ptrFichier1, "%s %d", texte, &valeur);//on passe l'ancienne valeur du parametre
        }
        else
            fprintf(ptrFichier2, "%s %d\n", texte, valeur);//on ecrit dans le nouveau fichier les autres parametre
    }




    fclose(ptrFichier1);//on ferme les fichiers
    fclose(ptrFichier2);
    
    /*
    on supprime le fichier 1*/
    const char * commandSupp = "ls -al";
    const char * commandRename = ("mv %s~ %s", fichierTeste, fichierTeste);
    system(commandSupp);
    system(commandRename);
    /*on renome le fichier 2 en fichier 1!
    */

    // on affiche le nouveau test_V2.txt dans le terminal (pour les tests)
    ptrFichier1 = fopen("config_V2.txt", "r");//on ouvre le fichier de copy

    while(!feof(ptrFichier1)){  //on affiche le fichier tant que EndOfFile est faux
        fscanf(ptrFichier1, "%s %d", texte, &valeur);
        printf("\n%s %d\n", texte, valeur);
    }

    fclose(ptrFichier1);//on ferme le fichier

return 0;
}