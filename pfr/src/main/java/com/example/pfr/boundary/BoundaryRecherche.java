/*  Créateur : Manon COUFFIN
    Date de derniere mise à jour : 09/03
 */
package com.example.pfr.boundary;

import com.example.pfr.controleur.code.ControlRecherche;
import com.example.pfr.modele.*;

public class BoundaryRecherche {
    //attribut
    private ControlRecherche controleRecherche;

    //constructeur
    public BoundaryRecherche(ControlRecherche controleRecherche) {
        this.controleRecherche = controleRecherche;
    }

    //methode

    public void choixRecherche(){
        String paramIm;
        String paramAud;
        String paramTexte;

        System.out.print("Quel type de recherche effectuer : \n" +
                "\tSIMPLE \n"+
                "\tCOMPLEXE \n");
        String choixType = Clavier.entrerClavierString();
        TypeRecherche type = TypeRecherche.valueOf(choixType);
        switch(type){
            case  SIMPLE :  Fichier typeFichier = demanderFichier();

                            switch(typeFichier){
                                case IMAGE  :   Integer typeIm;
                                                CritereRecherche critereRechercheImage = demanderCritereImageTexte();
                                                if(critereRechercheImage==CritereRecherche.SIMILITUDES) {
                                                    typeIm = demanderTypeImage();
                                                }
                                                else{
                                                    typeIm = null;
                                                }
                                                paramIm = demanderParametreImage(critereRechercheImage);
                                                //List<String> resultImage = new ArrayList<>();
                                                String resultImage;
                                                resultImage = controleRecherche.lancerRecherche(critereRechercheImage,typeFichier,type,paramIm,typeIm);
                                                System.out.println("Les résultats de la recherche sont : \n " +
                                                     resultImage);
                                                break;

                                case AUDIO  :   CritereRecherche critereRechercheAudio = demanderCritereAud();
                                                paramAud = demanderParametreAudio(critereRechercheAudio);
                                                //System.out.println("parametre audio");
                                                String resultAudio = controleRecherche.lancerRecherche(critereRechercheAudio,typeFichier,type,paramAud,null);
                                                System.out.println("Les résultats de la recherche sont : \n " +
                                                resultAudio);;
                                                break;

                                default     :   //System.out.println("* Recherche Texte à reimplémenter *");

                                                CritereRecherche critereRechercheTexte = demanderCritereImageTexte();
                                                paramTexte = demanderParametreTexte(critereRechercheTexte);
                                                String resultTexte=controleRecherche.lancerRecherche(critereRechercheTexte,typeFichier,type,paramTexte,null);
                                                System.out.println("Les résultats de la recherche sont : \n " +
                                                resultTexte);
                                                break;

                            }
                            break;

            case COMPLEXE : 
            	typeFichier = demanderFichier();
		String resultTexte = "";
		paramTexte = demanderParametreTexte();
              	resultTexte = controleRecherche.lancerRechercheComplexe(CritereRecherche.MOTSCLEFS,typeFichier,type,paramTexte);//appele recherche Complexe
              	System.out.println("Les résultats de la recherche sont : \n" + resultTexte);
              	break;

        }
    }

    public CritereRecherche demanderCritereImageTexte(){
        System.out.print(" Selon quel critère effectuer la recherche : \n"+
                "\tCLASSIQUE \n"+
                "\tMOTSCLEFS \n"+
                "\tSIMILITUDES \n");
        String choixCritere = Clavier.entrerClavierString();
        switch(choixCritere){
            case "MOTSCLEFS"    :  return CritereRecherche.MOTSCLEFS;
            case "SIMILITUDES"  :  return CritereRecherche.SIMILITUDES;
            default             :  return CritereRecherche.CLASSIQUE;
        }
    }

    public CritereRecherche demanderCritereAud(){
        System.out.print(" Selon quel critère effectuer la recherche : \n"+
                "\tCLASSIQUE \n"+
                "\tSIMILITUDES\n");
        String choixCritere = Clavier.entrerClavierString();
        switch(choixCritere){
            case "SIMILITUDES"   :  return CritereRecherche.SIMILITUDES;
            default              :  return CritereRecherche.CLASSIQUE;
        }
    }

    public Fichier demanderFichier(){
        System.out.print("Pour quel type de fichier souhaitez vous faire la recherche : \n"+
                "\tAUDIO \n"+
                "\tIMAGE \n"+
                "\tTEXTE \n");
        String choixFichier = Clavier.entrerClavierString();
        switch(choixFichier){
            case "AUDIO" :  return Fichier.AUDIO;
            case "IMAGE" :  return Fichier.IMAGE;
            default      :  return Fichier.TEXTE;
        }
    }

    public String demanderParametreImage(CritereRecherche critereRecherche){
        switch(critereRecherche){
            case CLASSIQUE  :   System.out.println("Saisissez le nom du fichier à afficher");
                                return Clavier.entrerClavierString();
            case MOTSCLEFS  :   System.out.println("Saisissez le mot clé correctement (R,V ou B)");
                                return Clavier.entrerClavierString();
            case SIMILITUDES:   System.out.println("Saisissez le nom du fichier de reference");
                                return Clavier.entrerClavierString();
            default :   System.out.println("default case");
                        return null;
        }
    }

    public int demanderTypeImage(){
        System.out.println("Sur quel type d'image effectuer la recherche par similitude ?");
        System.out.println("\t 1 - Images en couleurs");
        System.out.println("\t 2 - Images en noir et blanc");
        return Clavier.entrerClavierInt();
    }

    public String demanderParametreAudio(CritereRecherche critereRecherche){
        switch(critereRecherche){
            case CLASSIQUE  :   System.out.println("Saisissez le nom du fichier à écouter");
                return Clavier.entrerClavierString();
            case SIMILITUDES:   System.out.println("Saisissez le nom du fichier de reference");
                return Clavier.entrerClavierString();
            default :   System.out.println("default case");
                return null;
        }
    }

    public String demanderParametreTexte(CritereRecherche critereRecherche){
        switch(critereRecherche){
            case CLASSIQUE  :   System.out.println("Saisissez le nom du texte à afficher");
                return Clavier.entrerClavierString();
            case MOTSCLEFS  :   System.out.println("Saisissez le mot clé correctement");
                return Clavier.entrerClavierString();
            case SIMILITUDES:   System.out.println("Saisissez le nom du texte de reference");
                return Clavier.entrerClavierString();
            default :   System.out.println("default case");
                return null;
        }
    }

    public String demanderParametreTexte(){
        System.out.println("Entrer clavier : ");
        return Clavier.entrerClavierString();
    }

    /*
    public void demanderMotClefs(){

    }


    public List<String> rechercher(Fichier fichier, CritereRecherche critere, String donnee){

    }
     */
}
