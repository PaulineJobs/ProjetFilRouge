					/*-------------------------------------------/
					/       AUTEUR : JOBERT Pauline             /
					/----Completé par Lucas AMBLARD-------------*/
					//ROLE : gestion du menu !

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <unistd.h>
#include "interface.h"
#include "../Configuration/configuration.h"
#include "../IndexationAudio/indexationAudio.c"
#include "../RechercheAudio/rechercheAudio.h"
#include "../RechercheAudio/arbre.c"

#include "../IdxIm/fifo.h"
#include "../IdxIm/element.h"
#include "../IdxIm/IdxIm_V1.h"

#include "../RechercheImage/RechercheImComp.h"
#include "../RechercheImage/RechercheImCrit.h"

#include "../Indexation_texte/descripteurTexte.h"
#include "../RechercheTexte/rechercheTexte.h"



// Ouverture de l'application 
void ouverture(){
	printf(" \n");
	printf(" \n");
	printf(" Ouverture de l'application \n");
	printf(" Indexation des fichiers. Veuillez patienter... \n");
	
	//on supprime les descripteurs fait lors de la précedente ouverture d'application
	rmDescripteurs("../../Base_descripteurs/Base_descripteurs_audios");
	rmDescripteurs("../../Base_descripteurs/Base_descripteurs_textes");
	rmDescripteurs("../../Base_descripteurs/Base_descripteurs_images_RGB");
	rmDescripteurs("../../Base_descripteurs/Base_descripteurs_images_NB");
	
	//on supprime la liste des descripteurs faite lors de la précedente ouverture d'application
	rmListeDescripteurs();
	
	//indexation des fichiers 
	automatisationIndexation();

	printf(" ------------------------------------------ \n");
	printf("|           Indexation terminée            |\n");
	printf("| Bienvenu sur notre moteur de recherche ! |\n");
	printf(" ------------------------------------------ \n");
	printf(" \n");
	printf(" \n");
	//on dirige l'utilisateur vers le menu pricipal
	menuPrincipal();
}


//On supprime les descripteurs crees precedement
void rmDescripteurs(char *repertoireParam){
	
	//Variables
	char repertoire[strlen(repertoireParam)];
    struct dirent *fichier;
    char *emplacement;
    size_t repertoire_len;
    
    //on ouvre le repertoire choisi en paramètre
    strcpy(repertoire,repertoireParam);
    DIR *dir = opendir(repertoire); 
    repertoire_len = strlen(repertoire);
    
    
    //on verifie l'ouverture du repertoire et on le parcourt
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





//On supprime la liste des descripteurs
void rmListeDescripteurs(){
	remove("../../Liste_descripteurs/Liste_descripteurs_textes.txt");
	remove("../../Liste_descripteurs/Liste_descripteurs_audios.txt");
	remove("../../Liste_descripteurs/Liste_descripteurs_imageRVB.txt");
	remove("../../Liste_descripteurs/Liste_descripteurs_imageNB.txt");
		
}	


//propose differentes recherches possibles selon le type d'image selectionné
void recherche (int type){
	//variables
	char choixAction[10];
	choixAction[0]='0';
	
	
	while((choixAction[0]!='D')){
		//si on recherche un texte
		if (type==1){
			printf(" ------------------------------------------------ \n");
			printf("| Quel type de recherche voulez-vous effectuer ? |\n \r");
			printf("| A - Recherche par nom de fichier               | \n \r");
			printf("| B - Recherche par mot clé                      | \n \r");
			printf("| C - Retour                                     |\n \r");
			printf(" ------------------------------------------------ \n");
			scanf("%s",choixAction);
			
			switch (choixAction[0]){
				case 'A' : 
					printf(" --------------------------------------------------- \n");
					printf("| Vous avez choisi une recherche de textes par nom de fichier | \n \r");
					RechercheClassique();
					choixAction[0]='D';
					break;
				
				case 'B' :
					printf(" ---------------------------------------------------- \n");
					printf("| Vous avez choisi une recherche de textes par mot clé | \n \r");
					rechCritTexte();
					choixAction[0]='D';
					break;

				case 'C' :
					choixAction[0]='D';
					break;


				default :
					printf(" Erreur : caractère invalide\n \r");
				
			}
		}
		//si on recherche une image
		if (type==2){
			printf(" ------------------------------------------------ \n");
			printf("| Quel type de recherche voulez-vous effectuer ? |\n \r");
			printf("|                                                |\n");
			printf("| A - Recherche par nom de fichier               | \n \r");
			printf("| B - Recherche par mots clefs                   | \n \r");
			printf("| C - Recherche par similitudes                  |\n \r");
			printf("| D - Retour                                     |\n \r");
			printf(" ------------------------------------------------ \n");
			scanf("%s",choixAction);
		
			switch (choixAction[0]){
				case 'A' : 
					printf(" --------------------------------------------------- \n");
					printf("| Vous avez choisi une recherche de texte par nom de fichier | \n \r");
					RechercheClassique();
					choixAction[0]='D';
					break;
			
				case 'B' :
					printf(" ------------------------------------------------------------------------------ \n");
					printf("| Vous avez choisi une recherche d'image par mots clefs                                |\n \r");
					IHMCrit();
					choixAction[0]='D';
					break;
					
				case 'C':
					printf(" ------------------------------------------------------------------------------ \n");
					printf("| Vous avez choisi une recherche d'image par similitudes                               |\n \r");
					IHMComp();
					choixAction[0]='D';
					break;
				case 'D':
					choixAction[0]='D';
					break;
				default :
					printf(" Erreur : caractère invalide\n \r");
			}
		}
		//si on recherche un audio
		if (type==3){
			
			printf(" ------------------------------------------------ \n");
			printf("| Quel type de recherche voulez-vous effectuer ? |\n \r");
			printf("|                                                |\n");
			printf("| A - Recherche par nom de fichier               | \n \r");
			printf("| B - Recherche par similitudes                  |\n \r");
			printf("| C - Retour                                     |\n \r");
			printf(" ------------------------------------------------ \n");
			scanf("%s",choixAction);
						switch (choixAction[0]){
				case 'A' : 
					printf(" --------------------------------------------------- \n");
					printf("| Vous avez choisi une recherche de d'un audio par nom de fichier | \n \r");
					RechercheClassique();
					choixAction[0]='D';
					break;
					
				case 'B':
				
					printf(" ------------------------------------------------------------------------------ \n");
					printf("| Vous avez choisi une recherche d'un audio par similitudes                               |\n \r");
					resultatRechercheAudio();
					choixAction[0]='D';
					break;
					
				case 'C':
					choixAction[0]='D';
					break;
				default :
					printf(" Erreur : caractère invalide\n \r");
			}
		}
	}
	printf("\n ");
}


//on choisi le type de fichier que l'on veut rechercher
void choixTypeFich(){
	char choixType[100];
	choixType[0]='0';
	int type;

//on demande le choix de l'administrateur
	printf(" ----------------------------------------------- \n");
	printf("| Sur quel type de document faire la recherche ?| \n \r");
	printf("| A- Texte                                      | \n \r");
	printf("| B- Image                                      | \n \r");
	printf("| C- Audio                                      |\n \r");
	printf(" ----------------------------------------------- \n");
	
	scanf("%s",choixType);
	
	switch (choixType[0]){
	case 'A' : 
			type=1;
			printf(" ------------------------------------------------ \n");
			printf("| Vous avez choisi une recherche Texte           |  \n \r");
			recherche(1);
			break;
			
	case 'B' :
			type=2;
			printf(" ------------------------------------------------ \n");
			printf("| Vous avez choisi une recherche Image           |\n \r");
			recherche(2);
			break;
			
	case 'C':
			type=3;
			printf(" ------------------------------------------------ \n");
			printf("| Vous avez choisi une recherche Audio           | \n \r");
			recherche(3);
			break;
			
			default :
			printf(" ------------------------------------------------ \n");
			printf("| Erreur : caractère invalide                    |\n");
		}
}


// Menu principal : 3 choix : se connecter, faire une recherche, ou fermer l'application	
void menuPrincipal(){
	
	//Variables
	char choixAction[10];
	
	
	//Tant que l'utilisateur ne veut pas fermer l'application on repropose le menu principal
	choixAction[0]='0';
	while((choixAction[0]!='C')){
		//On demande une première fois son choix à l'utilisateur : rechercher, se connecter ou fermer l'application
		printf(" ------------------------------------------  \n");
		printf("| Menu Principal : Que voulez-vous faire ? |\n \r");
		printf("| A- Faire une recherche                   |\n \r");
		printf("| B- Accéder aux droits administrateur     |\n \r");
		printf("| C- fermer l'application                  |\n \r");
		printf(" ------------------------------------------  \n");
		scanf("%s",choixAction);
		switch (choixAction[0]){	
		case 'A' :
			//Si l'utilisateur a demandé la fonction recherche 
			printf(" ----------------------------------------------- \n");
			printf("| Vous avez choisi d'effectuer une recherche    |\n");
			choixTypeFich();	
			break;
		case 'B' :
			//Si l'utilisateur a demandé la fonction connexion
			printf(" Vous avez choisi d'acceder aux droits administrateur\n");
			printf(" \n");
			seConnecter();	
			break;
		case 'C' :
			//Si l'utilisateur a demandé la fermeture de l'application
			printf(" ------------------------------------------ \n");
			printf("| Vous avez choisi de fermer l'application |\n");
			break;
		default :
			//Si l'utilisateur a demandé un caractère invalide, on reboucle
			printf(" Erreur : caractère invalide. Choisissez A,B ou C\n \r");
		}
	}
	printf("| Fermeture de l'application               |\n");
	printf(" ------------------------------------------ \n");
}






//connexion pour acceder aux droits administrateurs
void seConnecter(){
	
	//Variables
	char motDePasse[10]; 
	char choixConnexion[10];
	
	
	//Tant que l'utilisateur demande a se connecter, on se connecte
	choixConnexion[0]='A';
	while((choixConnexion[0]=='A')){
		
		//on rentre le mot de passe
		printf(" ---------------------------------------------------- \n");
		printf("| Une connexion est requise                          | \n");
		printf("| Entrez le mot de passe                             |\n"); 
		printf(" ---------------------------------------------------- \n");
		scanf("%s",motDePasse); 
		
		//si le mot de passe est correcte, on connecte
		if (strcmp(motDePasse,"1234")==0){
			printf(" ---------------------------------------------------- \n");
			printf("| Connexion réussie                                  |\n");
			printf("| Vous êtes désormais administrateur                 | \n \r");
			printf(" ---------------------------------------------------- \n");
			printf(" \n");
			choixAdmin();
			
			//On fait en sorte de quitter la boucle de reconnexion une fois qu'elle à été validée 
			//pour retourner directement au menu principal aprés l'execution du choix de l'admin
			choixConnexion[0]='B';
		}else {
			
			//si le mot de passe est incorrecte, on repropose la connexion ou le retour au menu principal
			printf(" -------------------------------------------------------- \n");
			printf("| Mot de passse incorrecte                                 |\n");
			printf("| Voulez-vous réessayer ?                                  |\n");
			printf("| A-Oui, je veux me reconnecter                            |\n");
			printf("| Autre caractère-non, je veux retourner au menu principal |\n");
			printf(" -------------------------------------------------------- \n");
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








//administrateur : 3 choix : rechercher, configurer ou retour au menu principal
void choixAdmin(){

	//Variables
	char choixAction[10];
	
	
	//on demande le choix : recherche, configurer, indexer ou revenir au menu principal
	//Tant que l'administrateur ne veux pas quitter le menu, on repasse par ce menu
	choixAction[0]='0';
	while((choixAction[0]!='C')){
		
		//on demande le choix de l'administrateur
		printf(" ----------------------------------------------------------------------------------------------------------\n");
		printf("| Que voulez-vous faire ?                                                                                  |\n \r");
		printf("| A- Faire une recherche                                                                                   |\n \r");
		printf("| B- Configurer la méthode d'indexation                                                                    |\n \r");
		printf("| C- Retourner au menu principal (attention, vous devrez à nouveau vous reconnecter pour acceder à ce menu)|\n \r");
		printf(" ----------------------------------------------------------------------------------------------------------\n");
		scanf("%s",choixAction);
		
		//on etudie le choix
		switch (choixAction[0]){
			
		//On fait une recherche 
		case 'A': 
			printf(" ----------------------------------------------- \n");
			printf("| Vous avez choisi d'effectuer une recherche    |\n");	
			choixTypeFich();
			break;
			
		//on configure
		case 'B' :
			printf(" ------------------------------------------------------- \n");
			printf("| Vous avez choisi de configurer la méthode d'indexation| \n");
			printf(" ------------------------------------------------------- \n");
			editConfig();
			printf(" ------------------------ \n");
			printf("| Modification effectuée | \n");	
			printf(" ------------------------ \n");
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




//On parcours le corpus et on indexe les documents
void automatisationIndexation(){
	
	//On lance l'indexation audio dans le repertoire contenant les fichiers audio
    struct dirent *dir;
    DIR *d = opendir("../../Corpus/AUDIO/"); 
    if (d) {
        while ((dir = readdir(d)) != NULL){
			if(strlen(dir->d_name)>4){
			
			VerifTypeFichierAudio(dir->d_name);
		}
			
        }
        closedir(d);
    }
   
	//On lance l'indexation texte dans le repertoire contenant les fichiers textes
    struct dirent *dirTxt;
    DIR *dTexte= opendir("../../Corpus/TEXTE/"); 
    if (dTexte) {
        while ((dirTxt = readdir(dTexte)) != NULL){
			if (strlen(dirTxt->d_name)>4){
				traitementTexte(dirTxt->d_name);
			}
        }
        closedir(dTexte);
    }
    
	//On lance l'indexation image dans le repertoire contenant les fichiers images RGB
    DIR *dImageRGB = opendir("../../Corpus/IMAGE/RGB/"); 
    struct dirent *dirImRGB;
    if (dImageRGB) {
        while ((dirImRGB = readdir(dImageRGB)) != NULL){
	   VerifTypeFichierImage(dirImRGB->d_name,0);
        }
        closedir(dImageRGB);
    }

	//On lance l'indexation image dans le repertoire contenant les fichiers images NB
    DIR *dImageNB = opendir("../../Corpus/IMAGE/NB/"); 
    struct dirent *dirImNB;
    if (dImageNB) {
        while ((dirImNB = readdir(dImageNB)) != NULL){
	   VerifTypeFichierImage(dirImNB->d_name,1);
        }
        closedir(dImageNB);
    }
  
}





//Lance une recherche par nom de fichier selon son extension 
void RechercheClassique() {
	char souhait[100];
	char suite[10];
	int fichierConnu=0;
	
	printf("| Entrez le nom de votre fichier                    |\n");
	printf(" --------------------------------------------------- \n");
	scanf("%s",souhait);
	
    int j;
    if (strlen(souhait) > 4) {
       for (j = 0; souhait[j + 3]; j++) {         
          if (!strcmp(&souhait[j], ".wav")){
			char chemin[strlen("../../Corpus/AUDIO/")+1+ strlen(souhait)];  //fichier audio
			strcpy(chemin,"../../Corpus/AUDIO/");
			strcat(chemin,souhait);
			char *fichier=(chemin);
			lanceFichierAudio(fichier);
			fichierConnu=1;
			printf("\n");
			 
		 } 
       }
       
       for (j = 0; souhait[j + 3]; j++) {         
          if (!strcmp(&souhait[j], ".xml")){
			  //printf("fichier texte\n");
			char chemin[strlen("../../Corpus/TEXTE/")+1+ strlen(souhait)]; //fichier texte
			strcpy(chemin,"../../Corpus/TEXTE/");
			strcat(chemin,souhait);
			char *fichier=(chemin);
			lanceFichierTexte(fichier);
			fichierConnu=1;
			printf("\n");
			 
		 } 
       }
       
      for (j = 0; souhait[j + 3]; j++) {         
          if (!strcmp(&souhait[j], ".bmp")){
			//printf("fichier img nb\n");
			char chemin[strlen("../../Corpus/IMAGE/NB/")+1+ strlen(souhait)]; //fichier image NB
			strcpy(chemin,"../../Corpus/IMAGE/NB/");
			strcat(chemin,souhait);
			char *fichier=(chemin);
			lanceFichierImage(fichier);
			fichierConnu=1;
			printf("\n");
			 
		 } 
       }
       
      for (j = 0; souhait[j + 3]; j++) {         
          if (!strcmp(&souhait[j], ".jpg")){
			  //sprintf("fichier img rvb\n");
			char chemin[strlen("../../Corpus/IMAGE/RGB/")+1+ strlen(souhait)]; //fichier RVB
			strcpy(chemin,"../../Corpus/IMAGE/RGB/");
			strcat(chemin,souhait);
			char *fichier=(chemin);
			lanceFichierImage(fichier);
			fichierConnu=1;
			printf("\n");
			 
		 } 
       }
       
    
    }
    
    if (fichierConnu==1){
		sleep(2);
		printf("\n");
		printf("Appuyez sur n'importe qu'elle touche pour retourner au Menu Principal\n");
		scanf("%s",suite);
		
	} else {
		printf("fichier inconnu\n");
	}
}


//on lance un fichier image avec EOM
void lanceFichierImage(char *fichierImage) {
	char *lecteurImage="eom";
	char *commande;

    // Allocation lecteurAudion + espace+ fichierAudio + &
	commande=(char *)malloc(strlen(fichierImage)+strlen(lecteurImage)+1+1+1);
	//printf("Malloc %d \n",strlen(fichierAudio)+strlen(lecteurAudio)+1+1);
	if (commande !=NULL){
		strcpy(commande,lecteurImage);
		strcat(commande," ");
		strcat(commande,fichierImage);
		strcat(commande,"&");
		//printf("Lancement de la commande %s\n",commande);
		system(commande);
		free(commande);
	}
}

//Lancement d'un fichier texte avec gedit
void lanceFichierTexte(char *fichierTexte) {
	char *lecteurTexte="gedit";
	char *commande;

    // Allocation lecteurAudion + espace+ fichierAudio + &
	commande=(char *)malloc(strlen(fichierTexte)+strlen(lecteurTexte)+1+1+1);
	//printf("Malloc %d \n",strlen(fichierAudio)+strlen(lecteurAudio)+1+1);
	if (commande !=NULL){
		strcpy(commande,lecteurTexte);
		strcat(commande," ");
		strcat(commande,fichierTexte);
		strcat(commande,"&");
		//printf("Lancement de la commande %s\n",commande);
		system(commande);
		free(commande);
	}
}



