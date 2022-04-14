/*  Créateur : Manon COUFFIN
    Date de derniere mise à jour : 11/03
 */
package com.example.pfr.modele;

public class ParametreRecherche {
    //attributs
    private boolean modeFerme;
    private boolean modeOuvert;
    private boolean modeMultiMoteur;

    //singleton
    private ParametreRecherche(){
        modeFerme = true;
        modeOuvert = false;
        modeMultiMoteur = false;

    }

    //holder
    private static class ParametreRechercheHolder{
        private final static ParametreRecherche instance = new ParametreRecherche();
    }

    public static ParametreRecherche getInstance(){
        return ParametreRecherche.ParametreRechercheHolder.instance;
    }

    //methode

    /*
        si choix =
                1 : mode Ouvert
                2 : mode Ouvert MuliMoteur
                3 : mode Fermé
                4 : mode Fermé MultiMoteur

     */
    public void modifModeOuvertFerme(int choix){
        if(choix ==1 || choix == 2){
            modeOuvert = true;
            modeFerme = false;
        }
        else{
            modeFerme = true;
            modeOuvert = false;
        }
    }

    public void modifModeMultiMoteur(int choix){
        if(choix == 2 || choix == 4){
            modeMultiMoteur = true;
        }
        else{
            modeMultiMoteur = false;
        }

    }

    public String getMode(){
        String mode = "Mode ";

        if(modeFerme){
            mode = mode + "Fermé ";
        }
        if(modeOuvert){
            mode = mode + "Ouvert ";
        }
        if(modeMultiMoteur){
            mode = mode + "Multimoteur";
        }

        return mode;
    }

    public String afficherModes() {
        return "Voici les modes en cours : \n" +
                "modeFerme = " + modeFerme +
                "\nmodeOuvert = " + modeOuvert +
                "\nmodeMultiMoteur = " + modeMultiMoteur +
                '\n';
    }
}
