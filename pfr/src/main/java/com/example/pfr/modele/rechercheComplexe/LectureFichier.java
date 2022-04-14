/*
Antoine LEVANEN
*/
package com.example.pfr.modele.rechercheComplexe;

import com.example.pfr.modele.Clavier;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class LectureFichier {

    //Attribute

    private ArrayList<String> lireFichier(String chemin) throws FileNotFoundException {

        File fichier = new File(chemin);
        Scanner scan = new Scanner(fichier);
        ArrayList<String> maListe = new ArrayList<>();

        while(scan.hasNextLine()){
            maListe.add(scan.nextLine());
        }
        return maListe;
    }

    public Map<Integer, String> miseEnPage(String chemin) throws FileNotFoundException {
        Map<Integer,String> maMap = new TreeMap<>();
        ArrayList<String> listeChamps = lireFichier(chemin);//recuperation de la liste de resultat

        final Pattern p = Pattern.compile("^\\d{2}");// on trouve le 1er "entier"; ^ debut de ligne; \\d : entier; {2} : les deux premier chiffres.
        for (int i = 0; i < listeChamps.size(); i++) {//boucle sur la liste de resultat
            Matcher m = p.matcher(listeChamps.get(i));//on cherche les entiers dans la String
            while(m.find()){//si il y a un entier
                int niveau = Integer.parseInt(m.group());
                //System.out.println(niveau);//affichage pour les tests
                maMap.put(niveau, listeChamps.get(i));
            }
        }

        return maMap;
    }
}
