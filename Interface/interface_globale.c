#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface_globale.h"
#include "../Configuration/configuration.h"
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


// Menu principal : 3 choix : se connecter, faire une recherche, ou fermer l'application	
void menuPrincipal(){
	printf(" \n");
	//Variables
	char choixAction[10];
	//Fonction
	//Tant que l'utilisateur ne veut pas fermer l'application on repropose le menu principal
	choixAction[0]='0';
	while((choixAction[0]!='C')){
		//On demande une première fois son choix à l'utilisateur : rechercher, se connecter ou fermer l'application
		printf(" Menu Principal : Que voulez-vous faire ? \n \r");
		printf(" A- Faire une recherche \n \r");
		printf(" B- Accéder aux droits administrateur \n \r");
		printf(" C- fermer l'application\n \r");
		scanf("%s",choixAction);
		switch (choixAction[0]){	
		case 'A' :
			//Si l'utilisateur a demandé la fonction recherche 
			printf(" Vous avez choisir d'effectuer une recherche\n");
			printf("Cette fonction est en maintenance\n");
			exit(0);	
			break;
		case 'B' :
			//Si l'utilisateur a demandé la fonction connexion
			printf(" Vous avez choisi d'acceder aux droits administrateur\n");
			seConnecter();	
			break;
		case 'C' :
			//Si l'utilisateur a demandé la fermeture de l'application
			printf(" Vous avez choisi de fermer l'application\n");
			break;
		default :
			//Si l'utilisateur a demandé un caractère invalide
			printf(" Erreur : caractère invalide. Choisissez A,B ou C\n \r");
		}
	}
	printf("Fermeture de l'application\n");
}




//connexion pour acceder aux droits administrateurs
void seConnecter(){
	printf(" \n");
	//Variables
	char motDePasse[10]; 
	char choixConnexion[10];
	choixConnexion[0]='A';
	
	//fonction
	//Tant que l'utilisateur demande a se connecter, on se connecte
	while((choixConnexion[0]=='A')){
		//on rentre le mot de passe
		printf("Une connexion est requise \n");
		printf("Entrez le mot de passe à 4 chiffres (qui est 1234)\n"); 
		scanf("%s",motDePasse); 
		//si le mot de passe est correcte, on connecte
		if (strcmp(motDePasse,"1234")==0){
			printf("Connexion réussie\n");
			printf(" Vous êtes désormais administrateur  \n \r");
			choixAdmin();
			//On fait en sorte de quitter la boucle de reconnexion une fois qu'elle à été validée 
			//pour retourner directement au menu principal aprés l'execution du choix de l'admin
			choixConnexion[0]='B';
		}else {
			//si le mot de passe est incorrecte, on repropose la connexion ou le retour au menu principal
			printf("Mot de passse incorrecte\n");
			printf("Voulez-vous réessayer ?\n");
			printf("A-Oui, je veux me reconnecter\n");
			printf("Autre caractère-non, je veux retourner au menu principal\n");
			scanf("%s",choixConnexion);
			//reconnexion
			if(choixConnexion[0]=='A'){
				printf("Vous avez choisi de vous reconnecter\n");
			} else {
				//retour au menu principal
				printf("Vous avez choisi de retourner au menu principal\n");
			}
		}
	}
}




//administrateur : 4 choix : indexer, rechercher, configurer ou retour au menu principal
void choixAdmin(){
	printf(" \n");
	
	//Variables
	char choixAction[10];
	choixAction[0]='0';
	//Fonction
	//on demande le choix : recherche, configurer, indexer ou revenir au menu principal
	//Tant que l'administrateur ne veux pas quitter le menu, on repasse par ce menu
	while((choixAction[0]!='D')){
		//on demande le choix de l'administrateur
		printf(" Que voulez-vous faire ? \n \r");
		printf(" A- Faire une recherche \n \r");
		printf(" B- Indexer un document \n \r");
		printf(" C- Configurer la méthode d'indexation \n \r");
		printf(" D- Retourner au menu principal (attention, vous devrez à nouveau vous reconnecter pour acceder à ce menu) \n \r");
		scanf("%s",choixAction);
		//on etudie le choix
		switch (choixAction[0]){
		//On fait une recherche 
		case 'A': 
			printf(" Vous avez choisir d'effectuer une recherche\n");
			printf("Cette fonction est en maintenance\n");	
			exit(0);
			break;
		//On indexe
		case 'B':
			printf(" Vous avez choisi d'indexer un document\n");
			printf("Cette fonction est en maintenance\n");
			exit(0);	
			break;
		//on configure
		case 'C' :
			printf(" Vous avez choisi de configurer la méthode d'indexation \n");
			editConfig();
			printf("\nModification effectuée \n\n");
			//exit(0);	
			break;	
		//on retourne au Menu principal
		case 'D' :
			printf(" Vous avez choisi de retourner au menu principal\n");
			break;
		//Si le caractère est invalide, on redemande le choix
		default :
			printf(" Erreur : caractère invalide. Choisissez A, B, C, ou D\n \r");

		}
	}
}	
	
