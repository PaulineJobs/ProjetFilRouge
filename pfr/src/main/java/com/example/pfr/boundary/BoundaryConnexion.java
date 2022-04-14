/*  Créateur : Manon COUFFIN
    Date de derniere mise à jour : 09/03
 */
package com.example.pfr.boundary;

import com.example.pfr.controleur.code.ControlConnexion;
//import modele.Profil;

public class BoundaryConnexion {
    //attributs
    private ControlConnexion controlConnexion;
    private final static int nbEssais = 3;

    //constructeur
    public BoundaryConnexion(ControlConnexion controlConnexion) {
        this.controlConnexion = controlConnexion;
    }

    //methode
    public boolean connexionAdmin(){

        boolean isConnecte=false;
        System.out.println("Rentrez votre mot de passe : ");
        String mdp = Clavier.entrerClavierString();
        int i = nbEssais;

        boolean mdpOK =controlConnexion.verifierMDP(mdp);

        while((!mdpOK) && (i>0)){
            System.out.println("Ce n'est pas le bon mot de passe, veuillez réessayer (nombre d'essais restant :" + i + ")");
            mdp = Clavier.entrerClavierString();
            mdpOK = controlConnexion.verifierMDP(mdp);
            i--;
        }
        if(mdpOK){
            isConnecte=true;
        }
        if(i<=0){
            System.out.println("Erreur ! Vous vous etes trompés un trop grand nombre de fois...");
        }
        return isConnecte;
    }

    public static void main(String[] args) {
       // BoundaryConnexion boundaryConnexion = new BoundaryConnexion(new ControlConnexion(Profil.getInstance()));
        //boundaryConnexion.connexionAdmin();
    }
}
