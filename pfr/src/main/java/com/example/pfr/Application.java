package com.example.pfr;
/*
    Créateur du fichier : Manon COUFFIN
    Personne(s) ayant travaillé(s) dessus : 
    Date de derniere mise à jour : 17/03/2022
*/

import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;

import java.io.IOException;

public class Application extends javafx.application.Application {

    public static Stage stage;

    @Override
    public void start(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(Application.class.getResource("accueilUser.fxml"));
        Scene scene = new Scene(fxmlLoader.load(), 900, 700);

        Application.stage = stage;

        stage.setScene(scene);
        stage.show();
    }

    public static void setView(String view) {
        if (stage == null) return;


        try {
            FXMLLoader fxmlLoader = new FXMLLoader(Application.class.getResource(view));
            Scene scene = new Scene(fxmlLoader.load());
            stage.setScene(scene);

        } catch (IOException | NullPointerException e) {
            System.out.println("Err: failed to change the view");
            e.printStackTrace();
        }
    }


    public static void main(String[] args) {
        launch();
    }
}
