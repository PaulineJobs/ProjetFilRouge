#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include "interface_globale.h"
#include "../Configuration/modifParametre.c"
#include "../IndexationAudio/histogramme_audio.c"
#include "../RechercheAudio/rechercheAudio.c"
#include "../RechercheAudio/arbre.c"
//codé par Pauline




// message d'ouverture de l'application 
void ouverture(){
	printf(" \n");
	printf(" \n");
	printf(" Ouverture de l'application \n");
	rmDescripteurs("../Base_descripteurs/Base_descripteurs_audios");
	rmDescripteurs("../Base_descripteurs/Base_descripteurs_textes");
	rmDescripteurs("../Base_descripteurs/Base_descripteurs_images");
	rmListeDescripteurs();
	automatisationAudio(); //indexation des fichiers audio
	printf(" Bienvenu sur le moteur de recherche AnimaSearch ! \n");
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
			IHM();	
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
	while((choixAction[0]!='C')){
		//on demande le choix de l'administrateur
		printf(" Que voulez-vous faire ? \n \r");
		printf(" A- Faire une recherche \n \r");
		printf(" B- Configurer la méthode d'indexation \n \r");
		printf(" C- Retourner au menu principal (attention, vous devrez à nouveau vous reconnecter pour acceder à ce menu) \n \r");
		scanf("%s",choixAction);
		//on etudie le choix
		switch (choixAction[0]){
		//On fait une recherche 
		case 'A': 
			printf(" Vous avez choisir d'effectuer une recherche\n");	
			IHM();
			break;
		//On indexe
		//on configure
		case 'B' :
			printf(" Vous avez choisi de configurer la méthode d'indexation \n");
			//printf("Cette fonction est en maintenance\n");
			editConfig();
				
			break;	
		//on retourne au Menu principal
		case 'C' :
			printf(" Vous avez choisi de retourner au menu principal\n");
			break;
		//Si le caractère est invalide, on redemande le choix
		default :
			printf(" Erreur : caractère invalide. Choisissez A, B ou C\n \r");

		}
	}
}






//On supprime la liste des descripteurs
void rmListeDescripteurs(){
	remove("../Liste_descripteurs/Liste_descripteurs_textes.txt");
	remove("../Liste_descripteurs/Liste_descripteurs_audios.txt");
	remove("../Liste_descripteurs/Liste_descripteurs_images.txt");
		
}	






//On supprime les descripteurs crees precedement
void rmDescripteurs(char *repertoireParam){
	
	//on ouvre le repertoire choisi en paramètre
	char repertoire[strlen(repertoireParam)];
	strcpy(repertoire,repertoireParam);
    DIR *dir = opendir(repertoire); 
    struct dirent *fichier;
    char *emplacement;
    size_t repertoire_len;
    repertoire_len = strlen(repertoire);
    
    
    //on verifie l'ouverture et on le parcourt
    if (dir) {
        while ((fichier = readdir(dir)) != NULL){
			//On ne traite pas les fichiers "." et ".."
			if (!strcmp(fichier->d_name, ".") || !strcmp(fichier->d_name, ".."))
				continue;

			//On supprime les autres fichiers
			emplacement = calloc(repertoire_len + strlen(fichier->d_name) + 1, sizeof(char));
			strcpy(emplacement, repertoire);
			strcat(emplacement, "/");
			strcat(emplacement, fichier->d_name);
			(unlink(emplacement));
			free(emplacement);
		}

		closedir(dir);
	}
}












//On parcours le corpus et on indexe les documents
void automatisationAudio(){
	
	//On lance l'indexation audio dans le repertoire contenant les fichiers audio
    struct dirent *dir;
    DIR *d = opendir("../Corpus/AUDIO/"); 
    if (d) {
        while ((dir = readdir(d)) != NULL){
			typeFichierAudio(dir->d_name);
        }
        closedir(d);
    }
   
	//On lance l'indexation texte dans le repertoire contenant les fichiers textes
    DIR *dTexte= opendir("../Corpus/TEXTE/"); 
    if (dTexte) {
        while ((dir = readdir(dTexte)) != NULL){
			//Indexation texte MANON
        }
        closedir(dTexte);
    }
    
	//On lance l'indexation image dans le repertoire contenant les fichiers images
    DIR *dImage = opendir("../Corpus/IMAGE/"); 
    if (dImage) {
        while ((dir = readdir(dImage)) != NULL){
			//IndexationImage LUCAS
        }
        closedir(dImage);
    }
  
}




