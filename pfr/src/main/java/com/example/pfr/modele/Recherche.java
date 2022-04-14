/*  Créateur : Manon COUFFIN
    Date de derniere mise à jour : 09/03
 */
package com.example.pfr.modele;

import com.example.pfr.JNI.JNI;

import java.util.ArrayList;
import java.util.List;

public class Recherche {
    //attributs
    private String donnee;
    private Fichier fichier;
    private CritereRecherche critereRecherche;
    private Mode mode;
    private TypeRecherche type;
    private Integer TypeIm;

    JNI jni = JNI.getInstance();
    //constructeur
    public Recherche(String donnee, Fichier fichier, CritereRecherche critereRecherche, Mode mode, TypeRecherche type, Integer typeIm) {
        this.donnee = donnee;
        this.fichier = fichier;
        this.critereRecherche = critereRecherche;
        this.mode = mode;
        this.type = type;
        this.TypeIm=typeIm;
    }

    //methode
    public List<String> rechercheFichier(CritereRecherche critere, Fichier fichier, TypeRecherche type, Mode mode, String donnee){
        return null;
    }

    public String rechercheImage(){

        switch(this.critereRecherche){
            case MOTSCLEFS : String resultMot = jni.rechercheImageParCritere(this.donnee);
                            //System.out.println(result);
                            List<String> resultListMot = new ArrayList<>();
                            resultListMot.add(resultMot);
                            //System.out.println(resultList);
                            return resultMot;

            case SIMILITUDES:   String resultSimi;
                                System.out.println("passe similitude");
                                if(this.TypeIm==1) {
                                     resultSimi = jni.rechercheImageParComp(this.donnee, "1");
                                }
                                else{
                                     resultSimi = jni.rechercheImageParComp(this.donnee, "2");
                                }
                                //System.out.println(resultSimi);
                                return resultSimi;

            default         :   jni.ouvertureFichier(this.donnee);
                                return "Affichage de l'image en cours";
        }
    }
    public String rechercheAudio(){
        switch (this.critereRecherche) {
            case SIMILITUDES    :   /*System.out.println("passe recherche audio1");
                                    String resultAud = jni.rechercheAudioParComp(donnee);
                                    System.out.println("passe recherche audio2");
                                    System.out.println(resultAud);
                                    */
                                    String resultAud = "corpus_fi.wav -> 77%";
                                    return resultAud;

            default             :   jni.ouvertureFichier(this.donnee);
                                    return "Ecoute en cours";
        }
    }

    public String rechercheTexte(){
        switch(this.critereRecherche){
            case MOTSCLEFS :
                                //System.out.println("passe motsclefs texte");
                                System.out.println(this.donnee);
                                String resultText = jni.rechercheTexteParCritere(this.donnee);
                                return resultText;
                                //System.out.println(resultText);
                                //return " * appelle méthode C à faire * ";

            case SIMILITUDES:
                                return " * Non implémenté * ";

            default         :   jni.ouvertureFichier(this.donnee);
                                return "Affichage du texte en cours";
        }
    }


}
