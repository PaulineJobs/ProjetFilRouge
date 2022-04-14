/*
Antoine LEVANEN
*/
package com.example.pfr.modele.rechercheComplexe;

import com.example.pfr.JNI.JNI;
import com.example.pfr.modele.Fichier;
import com.example.pfr.modele.rechercheComplexe.*;
import java.io.FileNotFoundException;
import java.util.*;

public class RechercheComplexe {

    //Attributes
    private LectureFichier lectureFichier = new LectureFichier();
    private String cheminUn = "/home/antoine/Documents/resultatUn";//fichier de test / à remplacer par de vrai resultat de recherche
    private String cheminDeux = "/home/antoine/Documents/resultatDeux";
    private Map<Integer, String> resultatUn = new TreeMap();
    private Map<Integer, String> resultatDeux = new TreeMap();
    private int nbResultat = 0;
    private boolean modeRecherche = false;// si false (-) -> intersection ; si true (-) -> différence
    private int nbPlus = 0;
    private int nbMoins = 0;
    private JNI jni = JNI.getInstance();

    //Constructor
    public RechercheComplexe(){
    }

    //Methods

    public List<String> isRechercheComplexe(String maRecherche, Fichier fichier) {
        String str = "";
        String[] string1;
        String[][] paramEtMotClef = new String[2][2];//matrice : ("+", "musique" ; "-", "football") exemple
        Map<Integer, String> resultat = new TreeMap();//les resultats
        List<String> resultatList = new ArrayList<>();
        //System.out.println(maRecherche);
        maRecherche = maRecherche.toLowerCase(Locale.ROOT);
        maRecherche = maRecherche.replaceAll(" ","");
        //maRecherche = maRecherche.replaceAll(">","");
        if((maRecherche.contains("+") || maRecherche.contains("-"))) {//is recherche complexe?
            paramEtMotClef[0][0] = String.valueOf(maRecherche.charAt(0));//ajouts du premier parametre
            str = maRecherche.substring(1);//suppression du 1er parametre

            for (int i = 0; i<str.length();i++){
                if(str.charAt(i) == '+' || str.charAt(i) == '-'){
                    nbPlus++;
                }
            }

            if(nbPlus >= 2 || nbPlus < 1) {//si il y a plus de 3 champs dans la recherche on met fin à la methode.
                System.out.println("La recherche complexe fonctionne avec seulement deux champs!");
                resultatList.addAll(resultat.values());
                return resultatList;
            }
            nbPlus = 0;// mise à zero du compteur

            if(str.contains("+")){//si le 2eme est avec le param "+"
                string1 = str.split("\\+");//separation de la string par rapport au "+"
                paramEtMotClef[0][1] = string1[0];//mise en forme de la matrice
                paramEtMotClef[1][0] = "+";
                paramEtMotClef[1][1] = string1[1];
            }else{//si le 2eme est avec le param "-"
                string1 = str.split("\\-");//separation de la string par rapport au "-"
                paramEtMotClef[0][1] = string1[0];//mise en forme de la matrice
                paramEtMotClef[1][0] = "-";
                paramEtMotClef[1][1] = string1[1];
            }
            //System.out.println(paramEtMotClef[0][0] + "->" + paramEtMotClef[0][1] + "\n" + paramEtMotClef[1][0] + "->" + paramEtMotClef[1][1]);
            resultat = determinerTypeRecherche(maRecherche, paramEtMotClef, fichier);
        }

        resultatList.addAll(resultat.values());
        //System.out.print("2 ->" + resultatList);
        return resultatList;
    }


    public Map<Integer, String> determinerTypeRecherche(String maRecherche, String[][] paramPlusMotClef, Fichier fichier){
        String[] newString = new String[2];
        newString[0] = paramPlusMotClef[0][1];
        newString[1] = paramPlusMotClef[1][1];

        Map<Integer, String> resultat = new TreeMap();

        if (paramPlusMotClef[0][0].equals("-") || paramPlusMotClef[1][0].equals("-")) {
            if(modeRecherche == true){
                resultat = differenceResultat(newString[0], newString[1], fichier);
            }else {
                resultat = intersectionResultat(newString[0], newString[1], fichier);
            }
        } else {
            resultat = unionResultat(newString[0], newString[1], fichier);
        }

        //System.out.println("1 ->" + resultat);//affichage des resultats
        return resultat;
    }


    //union (+) des résultats des deux mots clefs
    public Map<Integer, String> unionResultat(String motClefUn, String motClefDeux, Fichier fichier){
        //appelle recherches sur motClefUn
        //resultatUn = lectureFichier.miseEnPage(cheminUn);
        //appelle recherches sur motClefDeux
        //resultatDeux = lectureFichier.miseEnPage(cheminDeux);
        //traitement en fonction du type de fichier
        String resJniUn = "";
        String resJniDeux = "";
        switch (fichier){//ajouter case TEXTE
            case TEXTE :
                resJniUn = jni.rechercheTexteParCritere(motClefUn);
                //resultatUn = stringToMap("3-res0 4-res2 5-res3 6-res4");
                resultatUn = stringToMapTexte(resJniUn);
                resJniDeux = jni.rechercheTexteParCritere(motClefDeux);
                //resultatDeux = stringToMap("11-res11 12-res2 13-res13 14-res4 15-res15");
                resultatDeux = stringToMapTexte(resJniDeux);
                break;
            case IMAGE :
                resJniUn = jni.rechercheImageParCritere(motClefUn);
                resultatUn = stringToMapImage(resJniUn);
                resJniDeux = jni.rechercheImageParCritere(motClefDeux);
                resultatDeux = stringToMapImage(resJniDeux);
                break;
            default:
                resultatUn.put(0,"un");
                resultatDeux.put(1,"deux");
                break;
        }

        Map<Integer, String> unionResultat = new TreeMap();
        unionResultat = resultatUn;//on copie la 1ere liste de résultat dans la nouvelle liste
        //System.out.println(unionResultat);

        nbResultat = 0;
        for (Map.Entry entry: unionResultat.entrySet()) {//pour ne pas ecraser les key existantes
            if(nbResultat < (int) entry.getKey()){
                nbResultat = (int) entry.getKey();
            }
        }

        for (String a: resultatDeux.values()) {//on parcours la seconde liste
            if(!unionResultat.containsValue(a)){//si unionResulat ne contient pas la value alors on l'ajoute
                unionResultat.put(nbResultat , a);
                nbResultat++;
            }
        }
        //System.out.println(unionResultat);
        return unionResultat;
    }

    // intersection (-) des deux mots clefs
    public Map<Integer, String> intersectionResultat(String motClefUn, String motClefDeux, Fichier fichier){
        //appelle recherches sur motClefUn
        //resultatUn = lectureFichier.miseEnPage(cheminUn);
        //appelle recherches sur motClefDeux
        //resultatDeux = lectureFichier.miseEnPage(cheminDeux);

        //traitement en fonction du type de fichier
        String resJniUn = "";
        String resJniDeux = "";
        switch (fichier){//ajouter case TEXTE
            case TEXTE :
                resJniUn = jni.rechercheTexteParCritere(motClefUn);
                //resultatUn = stringToMap("3-res0 4-res2 5-res3 6-res4");
                resultatUn = stringToMapTexte(resJniUn);
                resJniDeux = jni.rechercheTexteParCritere(motClefDeux);
                //resultatDeux = stringToMap("11-res11 12-res2 13-res13 14-res4 15-res15");
                resultatDeux = stringToMapTexte(resJniDeux);
                break;
            case IMAGE :
                resJniUn = jni.rechercheImageParCritere(motClefUn);
                resultatUn = stringToMapImage(resJniUn);
                resJniDeux = jni.rechercheImageParCritere(motClefDeux);
                resultatDeux = stringToMapImage(resJniDeux);
                break;
            default:
                resultatUn.put(0,"un");
                resultatDeux.put(1,"deux");
                break;
        }

        Map<Integer, String> intersectionResultat = new TreeMap();
        nbResultat = 1;

        for (String a: resultatDeux.values()) {//on parcours la seconde liste
            if(resultatUn.containsValue(a)){//si resulatUn contient la value alors on l'ajoute
                intersectionResultat.put(nbResultat , a);
                nbResultat++;
            }//sinon on passe notre tour
        }
        //idem union => if map.size = 0 then pas de correspondance
        return intersectionResultat;
    }


    // difference (-) des deux mots clefs, si modeRecherche == true
    public Map<Integer, String> differenceResultat(String motClefUn, String motClefDeux, Fichier fichier){
        //appelle recherches sur motClefUn
        //resultatUn = lectureFichier.miseEnPage(cheminUn);
        //appelle recherches sur motClefDeux
        //resultatDeux = lectureFichier.miseEnPage(cheminDeux);
        nbResultat = 1;

        //traitement en fonction du type de fichier
        String resJniUn = "";
        String resJniDeux = "";
        switch (fichier){//ajouter case TEXTE
            case TEXTE :
                resJniUn = jni.rechercheTexteParCritere(motClefUn);
                //resultatUn = stringToMap("3-res0 4-res2 5-res3 6-res4");
                resultatUn = stringToMapTexte(resJniUn);
                resJniDeux = jni.rechercheTexteParCritere(motClefDeux);
                //resultatDeux = stringToMap("11-res11 12-res2 13-res13 14-res4 15-res15");
                resultatDeux = stringToMapTexte(resJniDeux);
                break;
            case IMAGE :
                resJniUn = jni.rechercheImageParCritere(motClefUn);
                resultatUn = stringToMapImage(resJniUn);
                resJniDeux = jni.rechercheImageParCritere(motClefDeux);
                resultatDeux = stringToMapImage(resJniDeux);
                break;
            default:
                resultatUn.put(0,"un");
                resultatDeux.put(1,"deux");
                break;
        }

        Map<Integer, String> differenceResultat = new TreeMap();

        for (String a: resultatUn.values()) {
            if(!resultatDeux.containsValue(a)){//si la value n'est pas dans resultatDeux, on l'ajoute à differenceResultat
                differenceResultat.put(nbResultat, a);
                nbResultat++;
            }
        }

        for (String a: resultatDeux.values()) {
            if(!resultatUn.containsValue(a)){//si la value n'est pas dans resultatUn, on l'ajoute à differenceResultat
                differenceResultat.put(nbResultat, a);
                nbResultat++;
            }
        }

        return differenceResultat;
    }


    //setter du modeRecherche (intersection ou difference)
    public boolean setModeRecherche(boolean mode){
        return modeRecherche = mode;
    }


    public Map<Integer, String> stringToMapTexte(String maString){//methode pour séparer la string des resultats Texte et mettre les resultats dans une Map
        Map<Integer, String> maMap = new TreeMap<>();
        String[] strTab;

        //smaString = maString.substring(maString.indexOf("-"));
        strTab = maString.split("\n");
        for (int i = 0; i < strTab.length; i++) {
            strTab[i] = strTab[i].substring(strTab[i].indexOf("-"));//enleve ce qui est avant "-"
            String[] strIntermediaire = strTab[i].split(":");//split aux :
            strIntermediaire[0] = strIntermediaire[0].replaceAll(" ","");
            strIntermediaire[0] = strIntermediaire[0].replaceAll("-","");
            maMap.put(i, strIntermediaire[0]);//prends que la 1er partie
        }
        return maMap;
    }

    public Map<Integer, String> stringToMapImage(String maString){//methode pour séparer la string des resultats Image et mettre les resultats dans une Map
        Map<Integer, String> maMap = new TreeMap<>();
        List<String> strSepare = new ArrayList<>();
        String[] strTab = new String[20];
        maString = maString.replaceAll(" ", "");
        strTab = maString.split("\n");

        for (int i = 0; i < strTab.length; i++) {
            //strTab[i] = strTab[i].replaceAll("\n", "");
            String[] tempStr = strTab[i].split("-");
            maMap.put(i, tempStr[0]);
        }
        return maMap;
    }

    public String miseEnPageResultat(List<String> listeResultat){
        String strResultat = "";
        for (String str: listeResultat) {
            strResultat += str + "\n";
        }
        return strResultat;
    }
}