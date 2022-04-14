package com.example.pfr.controleur.vueGraphique;/*
    Créateur du fichier : Manon COUFFIN
    Personne(s) ayant travaillé(s) dessus : 
    Date de derniere mise à jour : 17/03/2022
*/

import com.example.pfr.Application;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

import java.io.IOException;

public class AccueilUserController {
    public TextField accueilUserBarreRecherche;

    @FXML
    private Label welcomeText;

    @FXML
    protected void onBoutonConnexion() throws IOException {
        Application.setView("Connexion.fxml");
    }

    @FXML
    protected void onBoutonRecherche() throws IOException {
        RechercheController.rechercheEnCours = accueilUserBarreRecherche.getText();
        Application.setView("recherche.fxml");
    }


}
