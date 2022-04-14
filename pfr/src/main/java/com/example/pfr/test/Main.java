package com.example.pfr.test;


import com.example.pfr.boundary.*;
import com.example.pfr.controleur.code.*;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    //attributs
    //constructeur

    //methodes

    /*
    static {
        System.loadLibrary("JNI"); // Load native library hello.dll (Windows) or libhello.so (Unixes)
        //  at runtime
        // This library contains a native method called sayHello()
    }
    */
    public static void main(String[] args) throws FileNotFoundException {
        /*test
        JNI jni = new JNI();
        jni.majAppli();
        */

        //attributs
        int choix=0;
        Scanner scan = new Scanner(System.in);

        ControlLancerAppli controlLancerAppli = new ControlLancerAppli();
        BoundaryLancerAppli boundaryLancerAppli = new BoundaryLancerAppli(controlLancerAppli);

        ControlConnexion controlConnexion = new ControlConnexion();
        BoundaryConnexion boundaryConnexion = new BoundaryConnexion(controlConnexion);

        ControlAdmin controlAdmin = new ControlAdmin();
        BoundaryAdmin boundaryAdmin = new BoundaryAdmin(controlAdmin);

        ControlRecherche controleRecherche = new ControlRecherche();
        BoundaryRecherche boundaryRecherche = new BoundaryRecherche(controleRecherche);

        //appelles
        //System.out.println("passe avant IDX");
        boundaryLancerAppli.lancerAppli();
        while (true) {
            while (choix < 1 || choix > 3) {
                System.out.println("Que souhaitez vous faire : \n");
                System.out.println("1 - Effectuer une recherche \n");
                System.out.println("2 - Accéder aux droits administrateur \n");
                System.out.println("3 - Quitter \n");
                System.out.println("Choisir une valeur entre 1 et 3 ");
                choix = scan.nextInt();
                System.out.print("\033[H\033[2J");
            }
            System.out.println("vous avez choisi : " + choix);

            switch (choix) {
                case 3:
                    System.out.println("sortie system");
                    System.exit(1);
                    break;

                case 2:
                    //System.out.println("passe cas connexion");
                    boolean isAdmin = boundaryConnexion.connexionAdmin();
                    System.out.print("\033[H\033[2J");
                    //System.out.println(isAdmin);
                    if (isAdmin) {
                        boundaryAdmin.interfaceAdmin();
                    }
                    break;

                case 1:
                    boundaryRecherche.choixRecherche();
                    break;

            }
            System.out.print("\033[H\033[2J");
            choix=0;
        }
        /*
        1 - *Boundary*  lancerAppli
            -> *Controleur*  lancerAppli
            -> *Entity*  lancerAppli
            -> *C* appelle de la fonction existante de majAppli
       2 - demande choix
       3 - si "recherche" :
            -> *Boundary* Recherche (-> verif type de recherche -> demande critere -> demande type fichier
                ->demande motsclef)

         */
        /*
        1- *C* Lancement appli (mise à jour base descripteur/liste descripteur)
        2- *Textuelle/Graphique* Choix de ce qu'on veut faire :recherche, connexion admin ou quitter
        3- Switch :
            recherche : - Si recherche normal alors utiliser *C*
                        - Si recherche complexe (texte ou img) nouvelle fonctionnalité -> util
                        plusieurs fois fonction *C*
         */
    }

}
