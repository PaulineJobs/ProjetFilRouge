//COUFFIN Manon BELLER Willy

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "rechercheTexte.h"

//Permet de trouver les descripteurs contenant un mot donné par l'utilisateur
char*rechercheCritereTxt(char* crit)
{	system("touch ../../../../partie1/code/RechercheTexte/grep.txt");
	char * chemin = " ../../../../partie1/Base_descripteurs/Base_descripteurs_textes/ > ../../../../partie1/code/RechercheTexte/grep.txt"; //indication de l'emplacement du fichier qui sera créé avec le résultat de la commande grep
	char * grep = "grep -r -w "; //commande grep permettant de faire une recherche de caractères dans des fichiers; -r permet la recursivitée dans les répertoires, -w permet de ne prendre en compte que les mots complets
	char * commande;
	//printf("le chemin %s\n", chemin);

	//création de la commande bash en concaténant les différents éléments nécessaire à la commande grep désirée
	commande=(char *)malloc(strlen(grep)+strlen(crit)+strlen(chemin)+1);
	if (commande !=NULL)
	{
		strcpy(commande,grep);
		strcat(commande,crit);
		strcat(commande,chemin);
		//printf("la commande %s\n", commande);
		system(commande);
		
		free(commande);
		
	}
	char *  resRecherche = gestionResultGrep();
	return resRecherche;
}

char* resultatRechercheTexte;

//Affichage du résultat donné par la commande grep exécuté avec la fonction rechercheCritereTxt()
char * gestionResultGrep()
{
	char * infoParLigne = (char*)malloc(100);
	int flag=0; //booléen permettant d'indiquer s'il faut écrire le caractère dans le terminal ou non
	int rechercheInfructeuse = 1;//booléen indiquant si des fichiers correspondant au critère ont été trouvé ou non
	char lettre[1];

	FILE *ptrFicTmp;
	ptrFicTmp = fopen("../../../../partie1/code/RechercheTexte/grep.txt", "r");//on ouvre le fichier en lecture seul

    if(ptrFicTmp == NULL)// si le fichier n'est pas ouvert on arrete tout!
    {
        fprintf(stderr, "Erreur lors de la lecture du fichier\n");
    	return 0;
    }
    
    resultatRechercheTexte= (char*)malloc(sizeof(char)*1000);
    resultatRechercheTexte[0]='\0';
    //printf(" -resultat : %s    \n", resultatRechercheTexte);
    int compt=1;
    
		while ((*lettre=getc(ptrFicTmp)) != EOF) { //lecture jusqu'à la fin du fichier
			rechercheInfructeuse = 0;
			compt +=1;
			if (compt > 64){

				strncat(resultatRechercheTexte,lettre,1);
				
				
			}
			if (lettre[0] =='\n'){
				compt=1;
			}
			
			//printf("%c", lettre);

			
		}
    	
	//printf(" compt%d \n", compt);
	fclose(ptrFicTmp);
	system("rm ../../../../partie1/code/RechercheTexte/grep.txt");
	//printf(" resultat %s\n", resultatRechercheTexte);

	return resultatRechercheTexte;;
	
}

void rechCritTexte()
{
	char crit[20];

	printf("| Entrez un critère (un mot) :                         |\n");
	printf("  ----------------------------------------------------- \n");
	scanf("%s",crit);
	
	//printf("le critere %s\n", crit);
	
	

	char* res = rechercheCritereTxt(crit);
	
	if(res==NULL){
		printf("Aucun fichier ne correspond à ce critère");
		printf("\n\n");
	} else {
	printf("\n --------------- \n");
	printf("|  Résultats :  |\n ");
	printf("--------------- \n");
	printf("%s",res);
	}
	
}
