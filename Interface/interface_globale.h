

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
void automatisationAudio();



//Menus et Login
// menuPrincipal() : choix : se connecter ou rechercher 
void menuPrincipal();
//seConnecter() : l'utilisateur se connecte, si cela échoue il peut réessayer ou retourner au menu Principal
void seConnecter();
//choixAdmin(): choix : rechercher ou configurer
void choixAdmin();



#endif
