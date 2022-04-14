package com.example.pfr.controleur.vueGraphique;/*
    Créateur du fichier : Manon COUFFIN
    Personne(s) ayant travaillé(s) dessus : 
    Date de derniere mise à jour : 29/03/2022
*/

import com.example.pfr.Application;
import javafx.fxml.FXML;
import javafx.scene.control.CheckBox;
import javafx.scene.control.RadioButton;
import javafx.scene.control.Spinner;
import javafx.scene.control.SpinnerValueFactory;

import java.io.IOException;

public class ParametresController {
    public RadioButton parametreBoutonOuvert;
    public RadioButton parametreBoutonFerme;
    public CheckBox parametreBoutonMultiMoteur;
    public Spinner parametreAudioN;
    public Spinner parametreNbBit;
    public Spinner paramtreAudioM;
    public Spinner parametreNbOccurence;
    public Spinner paramatreSeuil;

    @FXML
    protected void onRetour() throws IOException {
        Application.setView("accueilAdmin.fxml");
    }

    @FXML
    protected void onBoutonValider() throws IOException {
        int audioN = (int)parametreAudioN.getValue();
        int audioM = (int)paramtreAudioM.getValue();
        int nbBit = (int)parametreNbBit.getValue();
        int nbocc = (int)parametreNbOccurence.getValue();
        int seuil= (int)paramatreSeuil.getValue();

        //appel configuration

        Application.setView("accueilAdmin.fxml");
    }

    @FXML
    protected void onBoutonModeOuvert() throws IOException {
        parametreBoutonOuvert.setSelected(true);
        parametreBoutonFerme.setSelected(false);
    }

    @FXML
    protected void onBoutonModeFerme() throws IOException {
        parametreBoutonOuvert.setSelected(false);
        parametreBoutonFerme.setSelected(true);
    }

    @FXML
    public void initialize() {
        parametreBoutonOuvert.setSelected(false);
        parametreBoutonFerme.setSelected(true);
        parametreBoutonMultiMoteur.setSelected(false);
        SpinnerValueFactory<Integer> audioN = new SpinnerValueFactory.IntegerSpinnerValueFactory(0, 30000, 1024);
        parametreAudioN.setValueFactory(audioN);

        SpinnerValueFactory<Integer> nbBits = new SpinnerValueFactory.IntegerSpinnerValueFactory(1, 4, 3);
        parametreNbBit.setValueFactory(nbBits);

        SpinnerValueFactory<Integer> audioM = new SpinnerValueFactory.IntegerSpinnerValueFactory(0, 1000000, 100);
        paramtreAudioM.setValueFactory(audioM);

        SpinnerValueFactory<Integer> nbOccu = new SpinnerValueFactory.IntegerSpinnerValueFactory(1, 4, 1);
        parametreNbOccurence.setValueFactory(nbOccu);

        SpinnerValueFactory<Integer> seuil = new SpinnerValueFactory.IntegerSpinnerValueFactory(0, 100, 50);
        paramatreSeuil.setValueFactory(seuil);
    }

}
