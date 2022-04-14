					/*-------------------------------------------/
					/       AUTEUR : JOBERT Pauline             /
                    /------------------------------------------*/
                    
#ifndef MODULE_interface             
#define MODULE_interface  




//Ouverture de l'application
//Ouvre l'application, lance l'indexation et dirige vers le menu principal
void ouverture();


//Mise à jour indexation
//Supprime la liste des desripteurs crees lors de la précédente ouverture de l'application
void rmListeDescripteurs();
//Supprime les descripteurs crees lors de la précédente ouverture de l'application
void rmDescripteurs();
//automatisation de l'indexation des fichiers à l'ouverture de l'application
void automatisationIndexation();



//Menus et Login
// menuPrincipal() : choix : se connecter ou rechercher 
void menuPrincipal();
//seConnecter() : l'utilisateur se connecte, si cela échoue il peut réessayer ou retourner au menu Principal
void seConnecter();
//choixAdmin(): choix : rechercher ou configurer
void choixAdmin();


//on choisi le type de fichier que l'on veut rechercher
void recherche (int type);
//Lance une recherche par nom de fichier selon son extension 
void requeteRechercheClassique();
//on lance un fichier image avec EOM
void lanceFichierImage(char *fichierImage);
//Lancement d'un fichier texte avec gedit
void lanceFichierTexte(char *fichierTexte);





//A mettre dans JNI :
//indexation et suppression des descripteurs à l'ouverture
void majOuverture();
//verifie le mdp donné en entree
int verifierConnexion(char*);
//lance la recherche classique à partir du nom donné en entree
int RechercheClassique(char*) ;





#endif
