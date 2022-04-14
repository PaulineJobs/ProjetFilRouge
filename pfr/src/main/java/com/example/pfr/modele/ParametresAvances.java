/*  Créateur : Manon COUFFIN
    Date de derniere mise à jour : 09/03
 */
package com.example.pfr.modele;

import com.example.pfr.JNI.JNI;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class ParametresAvances {
    //attribut

    //singleton
    /*private ParametresAvances(){

    }

    //holder
    private static class ParametresAvancesHolder{
        private final static ParametresAvances instance = new ParametresAvances();
    }

    public static ParametresAvances getInstance(){
        return ParametresAvances.ParametresAvancesHolder.instance;
    }

    //methode
    public void configuration(int numLigne, int nouvelleValeur){

    }*/

    //Attributes
    JNI jni = JNI.getInstance();

    //constructor
    public ParametresAvances(){

    }

    public void AfficheParametreAvances() throws FileNotFoundException {
        // LECTURE FICHIER .CONFIG EN JAVA (si besoin)
        File doc =
                new File("../../../../partie1/code/Configuration/.config/");
        Scanner obj = new Scanner(doc);
        int lignParam = 1;
        if (obj.hasNextLine()) {
            obj.nextLine();
        }
        while (obj.hasNextLine() && lignParam < 6) {
            if (obj.hasNext()) {
                obj.next();
            }
            System.out.print(lignParam + ". ");
            System.out.println(obj.nextLine());
            lignParam++;
        }

    }

    public void modifierParam(int numLigne, int nouvelleValeur){
        //System.out.println("passe avant JNI");
        jni.modifierParam(numLigne,nouvelleValeur);
        //System.out.println("passe apres JNI");
    }
}
