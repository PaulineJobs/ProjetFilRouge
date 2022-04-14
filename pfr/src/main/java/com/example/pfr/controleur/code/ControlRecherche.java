/*  Créateur : Manon COUFFIN
    Date de derniere mise à jour : 09/03
 */
package com.example.pfr.controleur.code;

import com.example.pfr.modele.rechercheComplexe.*;
import com.example.pfr.modele.*;
import java.util.List;


public class ControlRecherche {
    //attribut
    private ParametreRecherche parametreRecherche;
    private Recherche recherche;
    private Indexation indexation;
    private RechercheComplexe rechercheComplexe = new RechercheComplexe();

    //constructeur


    //methode
    public TypeRecherche verifierTypeRequete(){
        return null;
    }

    public Mode verifierMode(){
        return null;
    }

    public String lancerRecherche(CritereRecherche critere, Fichier fichier, TypeRecherche type, String param, Integer typeIm){
        switch(fichier){
            case IMAGE  :   Recherche rechercheIm = new Recherche(param,fichier,critere,Mode.FERME,type, typeIm);
                            return rechercheIm.rechercheImage();

            case AUDIO  :   Recherche rechercheAud = new Recherche(param,fichier,critere,Mode.FERME,type,null);
                            //System.out.println("passe controle audio");
                            return rechercheAud.rechercheAudio();

            case TEXTE  :   Recherche rechercheText = new Recherche(param,fichier,critere,Mode.FERME,type,null);
                            //System.out.println(param + fichier + critere + type);
                            return rechercheText.rechercheTexte();

            default     :   System.out.println("default case");
                            return null;
        }
    }
    
    public String lancerRechercheComplexe(CritereRecherche critere, Fichier fichier, TypeRecherche type, String param)  {
        List<String> listeResultat = rechercheComplexe.isRechercheComplexe(param, fichier);
        String str = rechercheComplexe.miseEnPageResultat(listeResultat);
        return str;
    }
    
}
