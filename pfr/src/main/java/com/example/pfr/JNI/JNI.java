package com.example.pfr.JNI;

import java.lang.String;

public class JNI {
    //constructor
    private JNI(){

    }

    //Holder
    private static class JNIHolder{
        private final static JNI instance = new JNI();
    }

    public static JNI getInstance(){
        return JNIHolder.instance;
    }

    static {
        System.loadLibrary("JNI"); // Load native library hello.dll (Windows) or libhello.so (Unixes)
        //  at runtime
        // This library contains a native method called sayHello()
    }

    // Declare an instance native method sayHello() which receives no parameter and returns void
    public native void majAppli();
    
    public native int valeurConfiguration(String nom);

    public native String rechercheImageParCritere(String critere);
    
    public native String rechercheImageParComp(String fichierRef, String type);
    
    public native String rechercheAudioParComp(String fichierRef);

    public native void modifierParam(int numero, int valeur);
    
    public native void afficherConfig();
    
    public native int ouvertureFichier(String fichierRef);
    
    public native String rechercheTexteParCritere(String critere);
    
    public static void main(String[] args) {
		//Indexation 
        //new JNI().majAppli();
        
        //System.out.println(new JNI().ouvertureFichier("jingle_fi.wav"));
       
        //Lire dans la config 
        //System.out.print("Valeur de M à l'indexation audio : ");
        //System.out.println(new JNI().valeurConfiguration("indexationAudioM"));
        
        //Changer la config 
        //System.out.print("Valeur de M à l'indexation audio avant  : ");
        //System.out.println(new JNI().valeurConfiguration("indexationAudioM"));
        //new JNI().modifierParam(3,200);
        //System.out.print("Valeur de M à l'indexation audio apres  : ");
        //System.out.println(new JNI().valeurConfiguration("indexationAudioM"));
        //new JNI().modifierParam(3,100);
        
        //Lire dans la config
        //System.out.print("Valeur de nbr bit à l'indexation audio : ");
        //System.out.println(new JNI().valeurConfiguration("nbrbit"));

		//recherche image par critere 
        //System.out.println(new JNI().rechercheImageParCritere("R"));
        
        //recherche image par comparaison
        //System.out.println(new JNI().rechercheImageParComp("01.jpg","1"));
        
        //recherche audio par comparaison
        //System.out.println(JNI.getInstance().rechercheAudioParComp("jingle_fi.wav"));
        //System.out.println(new JNI().rechercheAudioParComp("corpus_fi.wav"));

        //recherche texte critere
        System.out.println(new JNI().rechercheTexteParCritere("sonde"));
        
        //afficher la config
        //new JNI().afficherConfig();
        
         
        
    }
    
}
