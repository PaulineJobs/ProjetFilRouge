package com.example.pfr.boundary;

import com.example.pfr.controleur.code.*;

import java.io.FileNotFoundException;
import java.util.Scanner;

public class BoundaryAdmin {
    //atributes
    ControlAdmin controlAdmin;
    Scanner scanner = new Scanner(System.in);
    //constructor
    public BoundaryAdmin(ControlAdmin controlAdmin){
        this.controlAdmin=controlAdmin;
    }

    //methods
    public void interfaceAdmin() throws FileNotFoundException {
        int choix = 0;
        while(choix<1 || choix>3) {
            System.out.println("Vous êtes connecté en tant qu'administrateur \n");
            System.out.println("Que souhaitez vous faire : ");
            System.out.println("\t 1 - Effectuer une recherche ");
            System.out.println("\t 2 - Modifier les parametres ");
            System.out.println("\t 3 - Quitter ");

            choix = scanner.nextInt();
            System.out.print("\033[H\033[2J");
        }
        controlAdmin.interfaceAdmin(choix);
    }
}
