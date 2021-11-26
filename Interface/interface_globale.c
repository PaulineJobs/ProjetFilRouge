#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface_globale.h"
//codé par Pauline

// message d'ouverture de l'application 
void ouverture(){
	printf(" \n");
	printf(" \n");
	printf(" Ouverture de l'application \n");
	printf(" Bienvenu sur le moteur de recherche Dora l'exploratrice ! \n");
	printf(" \n");
	menuPrincipal();

}



// 2 choix : se connecter ou faire une recherche	
void menuPrincipal(){
	printf(" \n");
	
	//Variables
	char choixAction;
	
	choixAction='0';
	
	//Fonction
	//on demande le choix : recherche, connexion, fermeture de l'application 
/*	do{
		printf(" Menu Principal : Que voulez-vous faire ? \n \r");
		printf(" A- Faire une recherche \n \r");
		printf(" B- Accéder aux droits administrateur \n \r");
		printf(" C- fermer l'application\n \r");
		printf("mon choix avant le scanf est : %c\n",choixAction);
		scanf("%c",&choixAction);
		//printf("mon choix aprés le scanf est : %c\n",choixAction);	
	} while((choixAction!='A')&&(choixAction!='B')&&(choixAction!='C'));*/
	

	
	while((choixAction!='A')&&(choixAction!='B')&&(choixAction!='C')){
		printf(" Menu Principal : Que voulez-vous faire ? \n \r");
		printf(" A- Faire une recherche \n \r");
		printf(" B- Accéder aux droits administrateur \n \r");
		printf(" C- fermer l'application\n \r");
		printf("mon choix avant le scanf est : %c\n",choixAction);
		fflush(stdin);
		fflush(stdout);
		scanf("%c",&choixAction);
		printf("mon choix aprés le scanf est : %c\n",choixAction);	
	}
	
	
	//On fait une recherche 
	if (choixAction=='A') {
		printf(" Vous avez choisir d'effectuer une recherche\n");
		printf("Cette fonction est en maintenance\n");
		
	}
	
	//On se connecte
	if (choixAction=='B') {
		printf(" Vous avez choisi d'acceder aux droits administrateur\n");
		seConnecter();
		
	}
	//on ferme l'application
	if (choixAction=='C') {
		printf(" Vous avez choisi de fermer l'application\n");
		exit(0);	
	}

}




//connexion pour acceder aux droits administrateurs
void seConnecter(){
	printf(" \n");
	
	//Variables
	char motDePasse[4]; 
	char choixReconnexion;
	
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
		
		
	} else { //si la connexion a échoué, on propose :reconnexion ou retour au menu
		
		do{
			printf("Vous n'avez pas réussi à vous connecter\n");
			printf("Voulez-vous réessayer ?\n");
			printf("A-Oui, je veux me reconnecter\n");
			printf("B-non, je veux retourner au menu principal\n");
			scanf("%c",&choixReconnexion);
		} while((choixReconnexion!='A')&&(choixReconnexion!='B'));
	 
	    //On se reconnecte
		if(choixReconnexion=='A'){
			seConnecter();
		} else {
			//on retourne au menu principal
			printf("Vous allez être redirigé vers le menu principal\n");
			printf("Cette fonction est en maintenance\n");
		}
	}

}




//administrateur : 3 choix : indexer, rechercher ou configurer 	
void choixAdmin(){
	printf(" \n");
	
	//Variables
	char choixAction;
	choixAction='0';
	
	//Fonction
	
	//on demande le choix : recherche, configurer, ou indexer
	do{
		printf(" Que voulez-vous faire ? \n \r");
		printf(" A- Faire une recherche \n \r");
		printf(" B- Indexer un document \n \r");
		printf(" C- Configurer la méthode d'indexation \n \r");
		printf(" D- Retour au menu principal (attention, vous devrez à nouveau vous reconnecter pour acceder à ce menu) \n \r");
		scanf("%c",&choixAction);
	} while((choixAction!='A')&&(choixAction!='B')&&(choixAction!='C')&&(choixAction!='D'));
	
	//On fait une recherche 
	if (choixAction=='A') {
		printf(" Vous avez choisir d'effectuer une recherche\n");
		printf("Cette fonction est en maintenance\n");	
	}
	
	//On indexe
	if (choixAction=='B') {
		printf(" Vous avez choisi d'indexer un document\n");
		printf("Cette fonction est en maintenance\n");	
	}
	
	//on configure
	if (choixAction=='C') {
		printf(" Vous avez choisi de configurer la méthode d'indexation \n");
		printf("Cette fonction est en maintenance\n");		
	}
	
	//retour
	if (choixAction=='D') {
		printf(" Vous avez choisi de retourner au menu principal\n");
		menuPrincipal();

	}

}	
	
