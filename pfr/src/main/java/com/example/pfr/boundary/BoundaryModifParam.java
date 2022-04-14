/*  Créateur : Manon COUFFIN
    Date de derniere mise à jour : 09/03
 */
package com.example.pfr.boundary;

import com.example.pfr.JNI.JNI;
import com.example.pfr.controleur.code.ControlModifParam;
import com.example.pfr.controleur.code.ControlModifParam;
import com.example.pfr.modele.ParametresAvances;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class BoundaryModifParam {
    //attributes
    private ControlModifParam controlModifParam =new ControlModifParam();
    JNI jni = JNI.getInstance();

    //constructor
    public BoundaryModifParam(ControlModifParam controlModifParam) {
        this.controlModifParam = controlModifParam;
    }


    //methode
    public void modifierParametre() throws FileNotFoundException {
        int choixParametre = 0;
        while (choixParametre != 1 && choixParametre != 2){
            System.out.println("Choisissez les parametres à modifier : ");
            System.out.println("1. Parametres Avancés\n" +
                "2. Parametres de recherche\n");
            choixParametre = Clavier.entrerClavierInt();
            System.out.print("\033[H\033[2J");
        }
        if(choixParametre == 1) {
            //Parametre avancés

            // jni.afficherConfig();
            int numLigne = 0;
            while(numLigne<1 || numLigne >5){
                System.out.println("Quel parametre voulez vous modifier ?");

            try{
                controlModifParam.AfficherParametreAvances();
            }catch(FileNotFoundException e){
                throw new RuntimeException("erreur file");
            }

            System.out.println("Entrer votre choix entre 1 et 5");
            numLigne = Clavier.entrerClavierInt();
            System.out.print("\033[H\033[2J");
        }
            System.out.println("Quelle est la nouvelle valeur que vous voulez entrer ?");
            int nouvelleValeur = Clavier.entrerClavierInt();

            //appel du controleur
            controlModifParam.modifParametresAvances(numLigne+1, nouvelleValeur);

            System.out.println("Modification prise en compte ");
            controlModifParam.AfficherParametreAvances();

        }
        else{
            //Parametre recherche
            int choix = 0;

            System.out.println("Choisissez le mode de recherche : ");
            System.out.println("1. Ouvert\n" +
                    "2. Ouvert & MultiMoteur\n" +
                    "3. Fermé\n" +
                    "4. Fermé & MultiMoteur");
            while(choix<1 || choix >4){
                System.out.println("Entrer votre choix");
                choix = Clavier.entrerClavierInt();
                if(choix<1 || choix >4){
                    System.out.println("Vous devez entrer un chiffre entre 1 et 4");
                }
            }

            //appel du controleur
            controlModifParam.modifParametresRecherche(choix);
        }

        System.out.println("Paramètres modifiés \n");

    }
/*
    public static void main(String[] args) {

        BoundaryModifParam boundaryModifParam = new BoundaryModifParam(new ControleModifParam(null,null));

        boundaryModifParam.modifierParametre();
    }
*/
}
