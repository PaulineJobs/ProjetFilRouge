/*  Créateur : Manon COUFFIN
    Date de derniere mise à jour : 09/03
 */
package com.example.pfr.modele;

public class Profil {
    //attributs
    private String mdp;
    private boolean admin;

    //singleton
    private Profil(){
        mdp ="1234";
        admin = false;
    }

    //holder
    private static class ProfilHolder{
        private final static Profil instance = new Profil();
    }

    public static Profil getInstance(){
        return ProfilHolder.instance;
    }

    //methodes
    public boolean verifierMDP(String mdp){
        if(this.mdp.equals(mdp)){
            this.connexion();
            return true;
        }
        return false;
    }

    public void connexion(){
        admin = true;
    }

    public boolean verifierConnexion(){
        return admin;
    }

}
