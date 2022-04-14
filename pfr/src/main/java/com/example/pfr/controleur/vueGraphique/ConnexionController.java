package com.example.pfr.controleur.vueGraphique;/*
    Créateur du fichier : Manon COUFFIN
    Personne(s) ayant travaillé(s) dessus : 
    Date de derniere mise à jour : 28/03/2022
*/

import com.example.pfr.Application;
import com.example.pfr.modele.Profil;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;

import java.io.IOException;

public class ConnexionController {
    public PasswordField connexionMotDePasse;
    public Profil profil = Profil.getInstance();
    public Label connexionMessageErreur;
    private int nbEssaiConnexion = 2;

    @FXML
    protected void onConnexion() throws IOException {
        if (profil.verifierMDP(connexionMotDePasse.getText())) {
            profil.connexion();
            nbEssaiConnexion = 3;
            Application.setView("accueilAdmin.fxml");
        }
        else{
            if(nbEssaiConnexion == 0){
                connexionMotDePasse.setText("");
                Application.setView("accueilUser.fxml");
            }
            else{
                connexionMessageErreur.setText("MOT DE PASSE INCORRECT : il vous reste " + nbEssaiConnexion+ " essai(s)");
                nbEssaiConnexion--;
                connexionMotDePasse.setText("");
            }
        }
    }

    @FXML
    protected void onBoutonRetour(){
        Application.setView("accueilUser.fxml");
    }

    public void initialize() {
        nbEssaiConnexion = 2;
    }


}
