//COUFFIN Manon BELLER Willy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "rechercheTexte.h"

//Permet de trouver les descripteurs contenant un mot donné par l'utilisateur
void rechercheCritereTxt()
{
	char * chemin = " ../../Base_descripteurs/Base_descripteurs_textes/ > ./~"; //indication de l'emplacement du fichier qui sera créé avec le résultat de la commande grep
	char * grep = "grep -r -w "; //commande grep permettant de faire une recherche de caractères dans des fichiers; -r permet la recursivitée dans les répertoires, -w permet de ne prendre en compte que les mots complets
	char * commande;
	char crit[20];

	printf("| Entrez un critère (un mot) :                         |\n");
	printf("  ----------------------------------------------------- \n");
	scanf("%s",crit);

	//création de la commande bash en concaténant les différents éléments nécessaire à la commande grep désirée
	commande=(char *)malloc(strlen(grep)+strlen(crit)+strlen(chemin)+1);
	if (commande !=NULL)
	{
		strcpy(commande,grep);
		strcat(commande,crit);
		strcat(commande,chemin);
		system(commande);
		free(commande);
	}
}

//Affichage du résultat donné par la commande grep exécuté avec la fonction rechercheCritereTxt()
int gestionResultGrep()
{
	char * infoParLigne = (char*)malloc(100);
	int flag=0; //booléen permettant d'indiquer s'il faut écrire le caractère dans le terminal ou non
	int rechercheInfructeuse = 1;//booléen indiquant si des fichiers correspondant au critère ont été trouvé ou non
	char lettre;

	FILE *ptrFicTmp;
	ptrFicTmp = fopen("./~", "r");//on ouvre le fichier en lecture seul

    if(ptrFicTmp == NULL)// si le fichier n'est pas ouvert on arrete tout!
    {
        fprintf(stderr, "Erreur lors de la lecture du fichier\n");
    	return 0;
    }
    while ((lettre=getc(ptrFicTmp)) != EOF) //lecture jusqu'à la fin du fichier
    {
    	if(lettre >= 48 && lettre <=57)
    		flag = 1;

    	if(lettre == 46 || lettre == 10)
    		flag = 0;

    	if(flag==1)
    		printf("%c", lettre);
    		rechercheInfructeuse = 0;

    	if(lettre == 10)
    		printf("\n");

    	if(lettre == 32)
    		printf(" ");
	}
	fclose(ptrFicTmp);

	if(rechercheInfructeuse)
		printf("Aucun fichier ne correspond à ce critère");

	system("rm ./~");
	return 1;
}

void rechCritTexte()
{
	rechercheCritereTxt();
	printf("\n --------------- \n");
	printf("|  Résultats :  |\n ");
	printf("--------------- \n");
	gestionResultGrep();
	printf("\n\n");
}