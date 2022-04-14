/*  Créateur : Manon COUFFIN
    Date de derniere mise à jour : 09/03
 */
package com.example.pfr.controleur.code;

import com.example.pfr.JNI.JNI;
import com.example.pfr.modele.ParametresAvances;

import java.io.FileNotFoundException;

/*
import modele.ParametreRecherche;
import modele.ParametresAvances;
*/
public class ControlModifParam {
    //attributs
   // private ParametreRecherche parametreRecherche;
    //private ParametresAvances parametresAvances;

   // JNI jni = JNI.getInstance();

    //constructeur
    /*
    public ControleModifParam(ParametreRecherche parametreRecherche, ParametresAvances parametresAvances) {
        this.parametreRecherche = parametreRecherche;
        this.parametresAvances = parametresAvances;
    }
*/
    //attributes
    ParametresAvances parametresAvances = new ParametresAvances();

    //constructor
    public ControlModifParam(){

    }

    //methods
    public void AfficherParametreAvances() throws FileNotFoundException {
        parametresAvances.AfficheParametreAvances();
    }
    public void modifParametresAvances(int numLigne, int nouvelleValeur){
        parametresAvances.modifierParam(numLigne, nouvelleValeur);
    }

    public void modifParametresRecherche(int choix){

    }

}
