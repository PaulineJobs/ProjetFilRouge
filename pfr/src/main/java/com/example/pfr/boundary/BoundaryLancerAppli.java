package com.example.pfr.boundary;

import com.example.pfr.controleur.code.ControlLancerAppli;

public class BoundaryLancerAppli {
    //attributes
    ControlLancerAppli controlLancerAppli;

    //constructor
    public BoundaryLancerAppli(ControlLancerAppli controlLancerAppli){
        this.controlLancerAppli=controlLancerAppli;
    }

    //methods
    public void lancerAppli(){
        this.controlLancerAppli.lancerAppli();
    }

}
