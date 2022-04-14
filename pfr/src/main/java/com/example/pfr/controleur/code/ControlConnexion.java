/*  Créateur : Manon COUFFIN
    Date de derniere mise à jour : 11/03
 */
package com.example.pfr.controleur.code;

//import modele.Profil;

import com.example.pfr.JNI.JNI;
import com.example.pfr.modele.Profil;

public class ControlConnexion {
    //attributs
   // private Profil profil;

    //constructeur
  /*  public ControlConnexion(Profil profil) {
        this.profil = profil;
    }
   */

    public ControlConnexion(){

    }

    //methode
    public boolean verifierMDP(String mdp){
        Profil profil = Profil.getInstance();
        if(profil.verifierMDP(mdp)){
            profil.connexion();
        }
        //System.out.println(profil.verifierConnexion());
        return profil.verifierConnexion();
    }
}
