package com.example.pfr.controleur.vueGraphique;
/*
    Créateur du fichier : Manon COUFFIN
    Personne(s) ayant travaillé(s) dessus : 
    Date de derniere mise à jour : 29/03/2022
*/

import com.example.pfr.Application;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import java.io.IOException;

public class AccueilAdminController {
    public TextField accueilAdminBarreRecherche;
    public Button accueilAdminBontonRecherche;

    @FXML
    protected void onDeconnexion(){
        Application.setView("accueilUser.fxml");
    }

    @FXML
    protected void onBoutonParametre(){
        Application.setView("parametres.fxml");
    }
    @FXML
    protected void onBoutonRecherche(){
        RechercheController.rechercheEnCours = accueilAdminBarreRecherche.getText();
        Application.setView("recherche.fxml");
    }
}
