package com.example.pfr.controleur.code;
import com.example.pfr.boundary.*;

import java.io.FileNotFoundException;

public class ControlAdmin {
    //attributs


    //constructor
    public ControlAdmin(){

    }

    //methods
    public void interfaceAdmin(int choix) throws FileNotFoundException {
        switch(choix) {
            case 3 :    System.exit(1);
                        break;

            case 2 :   BoundaryModifParam boundaryModifParam = new BoundaryModifParam(new ControlModifParam());
                       try {
                           boundaryModifParam.modifierParametre();
                       }
                       catch(FileNotFoundException e){
                           throw new RuntimeException("erreur file");
                        }
                       break;

            default :   //System.out.println(" * faire un meilleur appelle à BoundaryRecherche *");
                ControlRecherche controleRecherche = new ControlRecherche();
                BoundaryRecherche boundaryRecherche = new BoundaryRecherche(controleRecherche);
                        boundaryRecherche.choixRecherche();
                        break;
        }
    }

}
