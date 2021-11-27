#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface_globale.h"
#include "../WILLY/modifParametre.c"
//codé par Pauline

// message d'ouverture de l'application 
void ouverture(){
	printf(" \n");
	printf(" \n");
	printf(" Ouverture de l'application \n");
	printf(" Bienvenu sur le moteur de recherche Dora l'exploratrice ! \n");
	printf(" \n");
	//on dirige l'utilisateur vers le menu pricipal
	menuPrincipal();
}



// Menu principal : 2 choix : se connecter ou faire une recherche	
void menuPrincipal(){
	printf(" \n");
	//Variables
	char choixAction[10];
	
	//Fonction
	//On demande une première fois son choix à l'utilisateur : rechercher ou se connecter
	choixAction[0]='0';
	printf(" Menu Principal : Que voulez-vous faire ? \n \r");
	printf(" A- Faire une recherche \n \r");
	printf(" B- Accéder aux droits administrateur \n \r");
	printf(" C- fermer l'application\n \r");
	scanf("%s",&choixAction);
	//on redemande tant que la valeur saisie n'est pas une valeur attendue
	while((choixAction[0]!='A')&&(choixAction[0]!='B')&&(choixAction[0]!='C')){
		printf(" Erreur : caractère invalide. Choisissez A,B ou C\n \r");
		printf(" Menu Principal : Que voulez-vous faire ? \n \r");
		printf(" A- Faire une recherche \n \r");
		printf(" B- Accéder aux droits administrateur \n \r");
		printf(" C- fermer l'application\n \r");
		scanf("%s",&choixAction);
	}
	//Si l'utilisateur a demandé la fonction recherche 
	if (choixAction[0]=='A') {
		printf(" Vous avez choisir d'effectuer une recherche\n");
		printf("Cette fonction est en maintenance\n");	
	}
	//Si l'utilisateur a demandé la fonction connexion
	if (choixAction[0]=='B') {
		printf(" Vous avez choisi d'acceder aux droits administrateur\n");
		seConnecter();	
	}
	//Si l'utilisateur a demandé la fonction fermeture de l'application
	if (choixAction[0]=='C') {
		printf(" Vous avez choisi de fermer l'application\n");
		exit(0);	
	}
}




//connexion pour acceder aux droits administrateurs
void seConnecter(){
	printf(" \n");
	//Variables
	char motDePasse[10]; 
	char choixReconnexion[10];
	choixReconnexion[0]='0';
	
	//fonction
	//on rentre le mot de passe
	printf("Une connexion est requise \n");
    printf("Entrez le mot de passe à 4 chiffres (qui est 1234)\n"); 
    scanf("%s",&motDePasse); 
    //si le mot de passe est correcte, on connecte
    if(strcmp(motDePasse,"1234")==0){ 
		printf("Connexion réussie\n");
		printf(" Vous êtes désormais administrateur  \n \r");
		choixAdmin();	
	} else { //si la connexion a échoué, on propose : reconnexion ou retour au menu
		printf("Mot de passse incorrecte\n");
		printf("Voulez-vous réessayer ?\n");
		printf("A-Oui, je veux me reconnecter\n");
		printf("B-non, je veux retourner au menu principal\n");
		scanf("%s",&choixReconnexion);
		//on redemande tant que la valeur saisie n'est pas une valeur attendue
		 while((choixReconnexion[0]!='A')&&(choixReconnexion[0]!='B')){
			printf(" Erreur : caractère invalide. Choisissez A ou B\n \r");
			printf("Vous n'avez pas réussi à vous connecter\n");
			printf("Voulez-vous réessayer ?\n");
			printf("A-Oui, je veux me reconnecter\n");
			printf("B-non, je veux retourner au menu principal\n");
			scanf("%s",&choixReconnexion);
		}
	   //Si l'utilisateur a demandé la fonction reconnexion
		if(choixReconnexion[0]=='A'){
			seConnecter();
		} else {
			//Si l'utilisateur a demandé la fonction retour au menu principal
			printf("Vous allez être redirigé vers le menu principal\n");
			menuPrincipal();
		}
	}
}




//administrateur : 3 choix : indexer, rechercher ou configurer 	
void choixAdmin(){
	printf(" \n");
	
	//Variables
	char choixAction[10];
	choixAction[0]='0';
	
	//Fonction
	
	//on demande le choix : recherche, configurer, ou indexer
	printf(" Que voulez-vous faire ? \n \r");
	printf(" A- Faire une recherche \n \r");
	printf(" B- Indexer un document \n \r");
	printf(" C- Configurer la méthode d'indexation \n \r");
	printf(" D- Retour au menu principal (attention, vous devrez à nouveau vous reconnecter pour acceder à ce menu) \n \r");
	scanf("%s",&choixAction);
	//on redemande tant que la valeur saisie n'est pas une valeur attendue
	while((choixAction[0]!='A')&&(choixAction[0]!='B')&&(choixAction[0]!='C')&&(choixAction[0]!='D')){
		printf(" Erreur : caractère invalide. Choisissez A, B, C, ou D\n \r");
		printf(" Que voulez-vous faire ? \n \r");
		printf(" A- Faire une recherche \n \r");
		printf(" B- Indexer un document \n \r");
		printf(" C- Configurer la méthode d'indexation \n \r");
		printf(" D- Retourner au menu principal (attention, vous devrez à nouveau vous reconnecter pour acceder à ce menu) \n \r");
		scanf("%s",&choixAction);
		
	}
	//On fait une recherche 
	if (choixAction[0]=='A') {
		printf(" Vous avez choisir d'effectuer une recherche\n");
		printf("Cette fonction est en maintenance\n");	
	}
	
	//On indexe
	if (choixAction[0]=='B') {
		printf(" Vous avez choisi d'indexer un document\n");
		printf("Cette fonction est en maintenance\n");	
	}
	
	//on configure
	if (choixAction[0]=='C') {
		printf(" Vous avez choisi de configurer la méthode d'indexation \n");
		//printf("Cette fonction est en maintenance\n");	
		editConfig();
	}
	
	//retour
	if (choixAction[0]=='D') {
		printf(" Vous avez choisi de retourner au menu principal\n");
		menuPrincipal();

	}


}	
	
