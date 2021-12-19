//codé par Pauline

#ifndef MODULE_ELEMENT_INCLUS    /*--  Inclusion conditionnelle --> si pas déjà inclus */          
#define MODULE_ELEMENT_INCLUS     /*--  alors créer la constante symbolique MODULE_IMAGE_H_INCLUS */

// ouverture(): ouvre l'appli et dirige vers le menu principal
void ouverture();
// menuPrincipal() : choix : se connecter ou rechercher 
void menuPrincipal();
//seConnecter() : l'utilisateur se connecte, si cela échoue il peut réessayer ou retourner au menu Principal
void seConnecter();
//choixAdmin(): choix : rechercher, indexer ou configurer
void choixAdmin();
void rmListeDescripteurs();

#endif
