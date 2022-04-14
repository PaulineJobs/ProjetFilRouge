package com.example.pfr.controleur.code;

import com.example.pfr.JNI.JNI;

public class ControlLancerAppli {
    //attributes
    JNI jni = JNI.getInstance();

    //constructor
    public ControlLancerAppli(){

    }

    //methods
    public void lancerAppli(){
        jni.majAppli();
    }
}
