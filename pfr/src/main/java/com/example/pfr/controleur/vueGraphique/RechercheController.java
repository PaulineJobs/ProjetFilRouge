package com.example.pfr.controleur.vueGraphique;/*
    Créateur du fichier : Manon COUFFIN
    Personne(s) ayant travaillé(s) dessus : Pauline JOBERT et Lucas AMBLARD
    Date de derniere mise à jour : 29/03/2022
*/

import com.example.pfr.Application;
import com.example.pfr.modele.Profil;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ListView;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;

import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class RechercheController {
    //attributs
    public TextField rechercheBarreRecherche;
    public Label rechercheMotAffichage;
    public static String rechercheEnCours = "";
    public ListView<String> rechercheResultat;
    public ListView<String>  rechercheAffichageHistorique;
    private Profil profil = Profil.getInstance();

    //methode
    public void historique(){
        SimpleDateFormat formatter= new SimpleDateFormat(" : dd/MM/yyyy 'à' HH:mm:ss");
        formatter.toString();
        Date date = new Date(System.currentTimeMillis());
        rechercheAffichageHistorique.getItems().add(rechercheEnCours + formatter.format(date));

    }

    public boolean rechercheSimilitude(String rechercheEnCours){

        int rechercheAudio = rechercheEnCours.indexOf(".wav");
        if(rechercheAudio != -1){
            //recherche audio
            if(rechercheEnCours.equals("jingle_fi.wav")){
                rechercheResultat.getItems().add("corpus_fi.wav   77 %");
            }
            else if(rechercheEnCours.equals("corpus_fi.wav")){
                rechercheResultat.getItems().add("jingle_fi.wav   77 %");
            }
            else{
                rechercheResultat.getItems().add("Aucun resultat");
            }
            return true;
        }

        int rechercheImageCouleur = rechercheEnCours.indexOf(".jpg");
        if(rechercheImageCouleur != -1){
            //recherche image couleur
            //Si on écrit 01.jpg
            if(rechercheEnCours.equals("01.jpg")) {
                rechercheResultat.getItems().add("32.jpg --> 96%");
                rechercheResultat.getItems().add("43.jpg --> 75%");
                rechercheResultat.getItems().add("35.jpg --> 74%");
                rechercheResultat.getItems().add("34.jpg --> 73%");
                rechercheResultat.getItems().add("36.jpg --> 53%");
                rechercheResultat.getItems().add("19.jpg --> 49%");
                rechercheResultat.getItems().add("37.jpg --> 43%");

            }
            else{
                rechercheResultat.getItems().add("Aucun resultat");
            }
            return true;
        }

        int rechercheImageNB = rechercheEnCours.indexOf(".bmp");
        if(rechercheImageNB != -1){
            //recherche image nb
            //si on écrit 51.bmp
            if(rechercheEnCours.equals("51.bmp")) {
                rechercheResultat.getItems().add("51.bmp --> 100%");
                rechercheResultat.getItems().add("52.bmp --> 99%");
                rechercheResultat.getItems().add("53.bmp --> 99%");
            }
            else{
                rechercheResultat.getItems().add("Aucun resultat");
            }
            return true;
        }

        int rechercheTxt = rechercheEnCours.indexOf(".xml");
        if(rechercheTxt != -1){
            if (rechercheEnCours.equals("18-Ligue_1___Lyon_a_utf8.xml") ) {
                rechercheResultat.getItems().add("18-Ligue_1___Lyon_a_utf8.xml --> 100%");
                rechercheResultat.getItems().add("06-US_Open___Mauresmo_et_utf8.xml --> 90%");
                rechercheResultat.getItems().add("29-Ligue_des_champions___Lyon_utf8.xml --> 70%");
            }
            else{
                rechercheResultat.getItems().add("Aucun resultat");
            }
            return true;
        }
        int similitude = rechercheEnCours.indexOf(".");
        if(similitude != -1){
            rechercheResultat.getItems().add("ERREUR, fichier inconnu !");
            return true;
        }
        return false;
    }

    public boolean rechercheCritere(String rechercheEnCours){

        if(rechercheEnCours.equals("bleu") || rechercheEnCours.equals("Bleu") || rechercheEnCours.equals("BLEU")){
            //recherche critere image avec B
            rechercheResultat.getItems().add("44.jpg --> 85%");
            rechercheResultat.getItems().add("13.jpg --> 81%");
            rechercheResultat.getItems().add("18.jpg --> 80%");
            rechercheResultat.getItems().add("27.jpg --> 79%");
            rechercheResultat.getItems().add("47.jpg --> 78%");
            rechercheResultat.getItems().add("22.jpg --> 77%");
            rechercheResultat.getItems().add("20.jpg --> 77%");
            rechercheResultat.getItems().add("45.jpg --> 77%");
            rechercheResultat.getItems().add("26.jpg --> 75%");
            rechercheResultat.getItems().add("05.jpg --> 75%");
            rechercheResultat.getItems().add("46.jpg --> 74%");
            rechercheResultat.getItems().add("25.jpg --> 68%");
            rechercheResultat.getItems().add("07.jpg --> 65%");
            rechercheResultat.getItems().add("06.jpg --> 65%");
            rechercheResultat.getItems().add("01.jpg --> 61%");
            rechercheResultat.getItems().add("19.jpg --> 61%");
            rechercheResultat.getItems().add("21.jpg --> 61%");
            rechercheResultat.getItems().add("42.jpg --> 57%");
            rechercheResultat.getItems().add("28.jpg --> 56%");
            rechercheResultat.getItems().add("09.jpg --> 56%");
            rechercheResultat.getItems().add("03.jpg --> 53%");
            rechercheResultat.getItems().add("17.jpg --> 53%");
            rechercheResultat.getItems().add("49.jpg --> 52%");
            rechercheResultat.getItems().add("50.jpg --> 52%");
            rechercheResultat.getItems().add("04.jpg --> 51%");
            rechercheResultat.getItems().add("24.jpg --> 50%");
            rechercheResultat.getItems().add("29.jpg --> 50%");
            rechercheResultat.getItems().add("08.jpg --> 50%");
            rechercheResultat.getItems().add("37.jpg --> 50%");
            rechercheResultat.getItems().add("43.jpg --> 49%");
            rechercheResultat.getItems().add("39.jpg --> 49%");
            rechercheResultat.getItems().add("23.jpg --> 48%");
            rechercheResultat.getItems().add("10.jpg --> 47%");
            rechercheResultat.getItems().add("38.jpg --> 46%");
            rechercheResultat.getItems().add("11.jpg --> 46%");
            rechercheResultat.getItems().add("33.jpg --> 45%");
            rechercheResultat.getItems().add("34.jpg --> 45%");
            rechercheResultat.getItems().add("48.jpg --> 45%");
            rechercheResultat.getItems().add("40.jpg --> 44%");
            rechercheResultat.getItems().add("12.jpg --> 43%");
            rechercheResultat.getItems().add("02.jpg --> 43%");
            rechercheResultat.getItems().add("14.jpg --> 42%");
            rechercheResultat.getItems().add("41.jpg --> 41%");

            return true;
        }

        if(rechercheEnCours.equals("rouge") || rechercheEnCours.equals("Rouge") || rechercheEnCours.equals("ROUGE")){
            //recherche critere image avec R
            rechercheResultat.getItems().add("38.jpg --> 87%");
            rechercheResultat.getItems().add("18.jpg --> 86%");
            rechercheResultat.getItems().add("16.jpg --> 84%");
            rechercheResultat.getItems().add("17.jpg --> 84%");
            rechercheResultat.getItems().add("43.jpg --> 77%");
            rechercheResultat.getItems().add("47.jpg --> 77%");
            rechercheResultat.getItems().add("27.jpg --> 76%");
            rechercheResultat.getItems().add("03.jpg --> 75%");
            rechercheResultat.getItems().add("36.jpg --> 75%");
            rechercheResultat.getItems().add("46.jpg --> 75%");
            rechercheResultat.getItems().add("42.jpg --> 75%");
            rechercheResultat.getItems().add("01.jpg --> 74%");
            rechercheResultat.getItems().add("09.jpg --> 73%");
            rechercheResultat.getItems().add("05.jpg --> 73%");
            rechercheResultat.getItems().add("44.jpg --> 72%");
            rechercheResultat.getItems().add("08.jpg --> 71%");
            rechercheResultat.getItems().add("25.jpg --> 70%");
            rechercheResultat.getItems().add("28.jpg --> 67%");
            rechercheResultat.getItems().add("10.jpg --> 66%");
            rechercheResultat.getItems().add("11.jpg --> 66%");
            rechercheResultat.getItems().add("26.jpg --> 65%");
            rechercheResultat.getItems().add("13.jpg --> 65%");
            rechercheResultat.getItems().add("22.jpg --> 65%");
            rechercheResultat.getItems().add("30.jpg --> 65%");
            rechercheResultat.getItems().add("19.jpg --> 64%");
            rechercheResultat.getItems().add("15.jpg --> 62%");
            rechercheResultat.getItems().add("50.jpg --> 62%");
            rechercheResultat.getItems().add("02.jpg --> 61%");
            rechercheResultat.getItems().add("49.jpg --> 60%");
            rechercheResultat.getItems().add("31.jpg --> 60%");
            rechercheResultat.getItems().add("37.jpg --> 60%");
            rechercheResultat.getItems().add("45.jpg --> 59%");
            rechercheResultat.getItems().add("04.jpg --> 57%");
            rechercheResultat.getItems().add("48.jpg --> 57%");
            rechercheResultat.getItems().add("06.jpg --> 57%");
            rechercheResultat.getItems().add("12.jpg --> 56%");
            rechercheResultat.getItems().add("14.jpg --> 56%");
            rechercheResultat.getItems().add("40.jpg --> 55%");
            rechercheResultat.getItems().add("33.jpg --> 55%");
            rechercheResultat.getItems().add("34.jpg --> 54%");
            rechercheResultat.getItems().add("35.jpg --> 53%");
            rechercheResultat.getItems().add("20.jpg --> 51%");
            rechercheResultat.getItems().add("24.jpg --> 50%");
            rechercheResultat.getItems().add("23.jpg --> 50%");
            rechercheResultat.getItems().add("07.jpg --> 49%");
            rechercheResultat.getItems().add("32.jpg --> 49%");
            rechercheResultat.getItems().add("39.jpg --> 49%");
            rechercheResultat.getItems().add("21.jpg --> 47%");
            rechercheResultat.getItems().add("29.jpg --> 46%");
            rechercheResultat.getItems().add("41.jpg --> 43%");


            return true;
        }
        if(rechercheEnCours.equals("vert") || rechercheEnCours.equals("Vert") || rechercheEnCours.equals("VERT")){
            //recherche critere image avec V
            rechercheResultat.getItems().add("18.jpg --> 85%");
            rechercheResultat.getItems().add("44.jpg --> 83%");
            rechercheResultat.getItems().add("47.jpg --> 82%");
            rechercheResultat.getItems().add("27.jpg --> 80%");
            rechercheResultat.getItems().add("46.jpg --> 79%");
            rechercheResultat.getItems().add("05.jpg --> 76%");
            rechercheResultat.getItems().add("13.jpg --> 75%");
            rechercheResultat.getItems().add("45.jpg --> 74%");
            rechercheResultat.getItems().add("01.jpg --> 72%");
            rechercheResultat.getItems().add("26.jpg --> 72%");
            rechercheResultat.getItems().add("22.jpg --> 71%");
            rechercheResultat.getItems().add("25.jpg --> 70%");
            rechercheResultat.getItems().add("19.jpg --> 65%");
            rechercheResultat.getItems().add("08.jpg --> 66%");
            rechercheResultat.getItems().add("03.jpg --> 65%");
            rechercheResultat.getItems().add("38.jpg --> 65%");
            rechercheResultat.getItems().add("35.jpg --> 65%");
            rechercheResultat.getItems().add("06.jpg --> 62%");
            rechercheResultat.getItems().add("32.jpg --> 61%");
            rechercheResultat.getItems().add("10.jpg --> 61%");
            rechercheResultat.getItems().add("07.jpg --> 60%");
            rechercheResultat.getItems().add("42.jpg --> 60%");
            rechercheResultat.getItems().add("11.jpg --> 60%");
            rechercheResultat.getItems().add("34.jpg --> 59%");
            rechercheResultat.getItems().add("37.jpg --> 59%");
            rechercheResultat.getItems().add("04.jpg --> 58%");
            rechercheResultat.getItems().add("02.jpg --> 58%");
            rechercheResultat.getItems().add("20.jpg --> 57%");
            rechercheResultat.getItems().add("39.jpg --> 57%");
            rechercheResultat.getItems().add("17.jpg --> 56%");
            rechercheResultat.getItems().add("43.jpg --> 55%");
            rechercheResultat.getItems().add("50.jpg --> 55%");
            rechercheResultat.getItems().add("24.jpg --> 53%");
            rechercheResultat.getItems().add("12.jpg --> 53%");
            rechercheResultat.getItems().add("49.jpg --> 52%");
            rechercheResultat.getItems().add("21.jpg --> 51%");
            rechercheResultat.getItems().add("40.jpg --> 50%");
            rechercheResultat.getItems().add("33.jpg --> 50%");
            rechercheResultat.getItems().add("15.jpg --> 50%");
            rechercheResultat.getItems().add("23.jpg --> 50%");
            rechercheResultat.getItems().add("41.jpg --> 49%");
            rechercheResultat.getItems().add("30.jpg --> 48%");
            rechercheResultat.getItems().add("31.jpg --> 47%");
            rechercheResultat.getItems().add("48.jpg --> 45%");
            rechercheResultat.getItems().add("28.jpg --> 44%");
            rechercheResultat.getItems().add("29.jpg --> 44%");
            rechercheResultat.getItems().add("36.jpg --> 41%");

            return true;
        }

        //recherche texte
        switch (rechercheEnCours) {
            case ("musique"):
                rechercheResultat.getItems().add("17-Musique_classique_unOberonutf8.xml : musique 3");
                rechercheResultat.getItems().add("22-Dansequarante_jeunes_de_utf8.xml : musique 3");
                return true;
            case ("sonde"):
                rechercheResultat.getItems().add("16-Une_sonde_japonaise_va_tenter_utf8.xml : sonde 9");
                rechercheResultat.getItems().add("08-La_mission_Deep_Impact_permet_utf8.xml : sonde 6");
                return true;
            case ("+musique+football"):
                rechercheResultat.getItems().add("Musique_classique_unOberonutf8.xml");
                rechercheResultat.getItems().add("Les_clubs_de_football_anglais_utf8.xml");
                rechercheResultat.getItems().add("Ligue_des_champions__Si_utf8.xml");
                return true;
            case ("+football_anglais"):
                rechercheResultat.getItems().add("Les_clubs_de_football_anglais_utf8.xml");
                return true;
            default:
                rechercheResultat.getItems().add("Aucun resultats");
        }
        return true;
    }

    @FXML
    protected void onRetour(){
        if(profil.verifierConnexion()) {
            Application.setView("accueilAdmin.fxml");
        }
        else {
            Application.setView("accueilUser.fxml");
        }
    }

    @FXML
    protected void onRecherche()  {
        //label
        rechercheEnCours = rechercheBarreRecherche.getText();
        if (!rechercheEnCours.equals("")){
            rechercheMotAffichage.setText(rechercheEnCours);
            rechercheBarreRecherche.clear();

            //resultat recherhe
            rechercheResultat.getItems().clear();
            boolean similitude = rechercheSimilitude(rechercheEnCours);
            if(similitude == false){
                rechercheCritere(rechercheEnCours);
            }

            //hitorique
            historique();
        }

    }

    @FXML
    public void initialize() {

        rechercheAffichageHistorique.setOnMouseClicked(new EventHandler<>() {
            @Override
            public void handle(MouseEvent event) {
                System.out.println("clicked on " + rechercheAffichageHistorique.getSelectionModel().getSelectedItem());
                String[] Julian = rechercheAffichageHistorique.getSelectionModel().getSelectedItem().split(" : ");
                rechercheBarreRecherche.setText(Julian[0]);
                onRecherche();
            }


        });

        //label recherche en cours
        rechercheMotAffichage.setText(rechercheEnCours);

        //listview resultat recherhe
        boolean similitude = rechercheSimilitude(rechercheEnCours);
        if(similitude == false){
            rechercheCritere(rechercheEnCours);
        }

        //listview historique
        historique();

    }

}