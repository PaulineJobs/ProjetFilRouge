JAVA_HOME=/home/manon/.jdks/openjdk-17.0.2
cheminControleur=com/example/pfr/controleur/code
cheminBoundary=com/example/pfr/boundary
cheminModele=com/example/pfr/modele
cheminJNI=com/example/pfr/JNI
cheminC=../../../../partie1/code/
cheminTest=com/example/pfr/test

all:  $(cheminBoundary)/BoundaryAdmin.class $(cheminBoundary)/BoundaryConnexion.class $(cheminBoundary)/BoundaryLancerAppli.class $(cheminBoundary)/BoundaryModifParam.class $(cheminBoundary)/BoundaryRecherche.class $(cheminControleur)/ControlAdmin.class $(cheminControleur)/ControlConnexion.class $(cheminControleur)/ControlLancerAppli.class $(cheminControleur)/ControlModifParam.class $(cheminControleur)/ControlRecherche.class $(cheminModele)/Recherche.class $(cheminModele)/rechercheComplexe/RechercheComplexe.class $(cheminModele)/ParametresAvances.class $(cheminJNI)/JNI.class $(cheminTest)/Main.class $(cheminJNI)/arbre.o $(cheminJNI)/element.o $(cheminJNI)/fifo.o $(cheminJNI)/configuration.o $(cheminJNI)/rechercheImageComparaison.o $(cheminJNI)/indexationAudio.o  $(cheminJNI)/rechercheImageCritere.o $(cheminJNI)/rechercheTexteCritere.o $(cheminJNI)/nettoyageTexte.o $(cheminJNI)/filtrageTexte.o $(cheminJNI)/descripteurTexte.o $(cheminJNI)/indexationImage.o $(cheminJNI)/rechercheAudio.o  $(cheminJNI)/interface.o $(cheminJNI)/majAppli.o $(cheminJNI)/libJNI.so

$(cheminBoundary)/BoundaryAdmin.class: $(cheminBoundary)/BoundaryAdmin.java
	javac -h $(cheminBoundary) $(cheminBoundary)/BoundaryAdmin.java

$(cheminBoundary)/BoundaryConnexion.class: $(cheminBoundary)/BoundaryConnexion.java
	javac -h $(cheminBoundary) $(cheminBoundary)/BoundaryConnexion.java

$(cheminBoundary)/BoundaryLancerAppli.class: $(cheminBoundary)/BoundaryLancerAppli.java
	javac -h $(cheminBoundary) $(cheminBoundary)/BoundaryLancerAppli.java

$(cheminBoundary)/BoundaryModifParam.class: $(cheminBoundary)/BoundaryModifParam.java
	javac -h $(cheminBoundary) $(cheminBoundary)/BoundaryModifParam.java
	
$(cheminBoundary)/BoundaryRecherche.class: $(cheminBoundary)/BoundaryRecherche.java
	javac -h $(cheminBoundary) $(cheminBoundary)/BoundaryRecherche.java
	
$(cheminControleur)/ControlAdmin.class: $(cheminControleur)/ControlAdmin.java
	javac -h $(cheminControleur) $(cheminControleur)/ControlAdmin.java
	
$(cheminControleur)/ControlConnexion.class: $(cheminControleur)/ControlConnexion.java
	javac -h $(cheminControleur) $(cheminControleur)/ControlConnexion.java

$(cheminControleur)/ControlLancerAppli.class: $(cheminControleur)/ControlLancerAppli.java
	javac -h $(cheminControleur) $(cheminControleur)/ControlLancerAppli.java
	
$(cheminControleur)/ControlModifParam.class: $(cheminControleur)/ControlModifParam.java
	javac -h $(cheminControleur) $(cheminControleur)/ControlModifParam.java
	
$(cheminControleur)/ControlRecherche.class: $(cheminControleur)/ControlRecherche.java
	javac -h $(cheminControleur) $(cheminControleur)/ControlRecherche.java

$(cheminModele)/Recherche.class: $(cheminModele)/Recherche.java
	javac -h $(cheminModele) $(cheminModele)/Recherche.java
	
$(cheminModele)/rechercheComplexe/RechercheComplexe.class: $(cheminModele)/rechercheComplexe/RechercheComplexe.java
	javac -h $(cheminModele) $(cheminModele)/rechercheComplexe/RechercheComplexe.java

$(cheminModele)/ParametresAvances.class : $(cheminModele)/ParametresAvances.java
	javac -h $(cheminModele) $(cheminModele)/ParametresAvances.java
    
$(cheminJNI)/JNI.class: $(cheminJNI)/JNI.java
	javac -h $(cheminJNI) $(cheminJNI)/JNI.java

$(cheminTest)/Main.class: $(cheminTest)/Main.java
	javac -h $(cheminTest) $(cheminTest)/Main.java

$(cheminJNI)/configuration.o: $(cheminC)/Configuration/configuration.c  $(cheminC)/Configuration/configuration.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/configuration.o $(cheminC)/Configuration/configuration.c
	
$(cheminJNI)/indexationAudio.o: $(cheminC)/IndexationAudio/indexationAudio.c $(cheminC)/IndexationAudio/indexationAudio.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/indexationAudio.o $(cheminC)/IndexationAudio/indexationAudio.c
	
$(cheminJNI)/indexationImage.o: $(cheminC)/IdxIm/IdxIm_V1.c $(cheminC)/IdxIm/IdxIm_V1.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/indexationImage.o $(cheminC)/IdxIm/IdxIm_V1.c
	
$(cheminJNI)/nettoyageTexte.o: $(cheminC)/Indexation_texte/nettoyageTexte.c $(cheminC)/Indexation_texte/nettoyageTexte.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/nettoyageTexte.o $(cheminC)/Indexation_texte/nettoyageTexte.c
	
$(cheminJNI)/filtrageTexte.o: $(cheminC)/Indexation_texte/filtrageTexte.c $(cheminC)/Indexation_texte/filtrageTexte.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/filtrageTexte.o $(cheminC)/Indexation_texte/filtrageTexte.c
	
	
$(cheminJNI)/descripteurTexte.o: $(cheminC)/Indexation_texte/descripteurTexte.c  $(cheminC)/Indexation_texte/descripteurTexte.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/descripteurTexte.o $(cheminC)/Indexation_texte/descripteurTexte.c
	
$(cheminJNI)/arbre.o: $(cheminC)/RechercheAudio/arbre.c  $(cheminC)/RechercheAudio/arbre.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/arbre.o $(cheminC)/RechercheAudio/arbre.c
	

$(cheminJNI)/rechercheAudio.o: $(cheminC)/RechercheAudio/rechercheAudio.c $(cheminC)/RechercheAudio/rechercheAudio.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/rechercheAudio.o $(cheminC)/RechercheAudio/rechercheAudio.c
	
$(cheminJNI)/rechercheImageCritere.o: $(cheminC)/RechercheImage/RechercheImCrit.c $(cheminC)/RechercheImage/RechercheImCrit.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/rechercheImageCritere.o $(cheminC)/RechercheImage/RechercheImCrit.c
	
$(cheminJNI)/rechercheImageComparaison.o: $(cheminC)/RechercheImage/RechercheImComp.c  $(cheminC)/RechercheImage/RechercheImComp.c
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/rechercheImageComparaison.o $(cheminC)/RechercheImage/RechercheImComp.c

$(cheminJNI)/rechercheTexteCritere.o: $(cheminC)/RechercheTexte/rechercheTexte.c $(cheminC)/RechercheTexte/rechercheTexte.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/rechercheTexteCritere.o $(cheminC)/RechercheTexte/rechercheTexte.c
	
$(cheminJNI)/interface.o: $(cheminC)/Interface/interface.c $(cheminC)/Interface/interface.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/interface.o $(cheminC)/Interface/interface.c

$(cheminJNI)/fifo.o: $(cheminC)/IdxIm/fifo.c  $(cheminC)/IdxIm/fifo.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/fifo.o $(cheminC)/IdxIm/fifo.c

$(cheminJNI)/element.o: $(cheminC)/IdxIm/element.c $(cheminC)/IdxIm/element.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/element.o $(cheminC)/IdxIm/element.c

$(cheminJNI)/majAppli.o: $(cheminJNI)/interface.o $(cheminC)/JNI/pourlaJNI.c $(cheminC)/JNI/pourlaJNI.h
	cc -fPIC -c -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -o $(cheminJNI)/majAppli.o $(cheminC)/JNI/pourlaJNI.c
	

$(cheminJNI)/libJNI.so: $(cheminJNI)/majAppli.o $(cheminJNI)/interface.o
	gcc --shared -fPIC -o $(cheminJNI)/libJNI.so $(cheminJNI)/arbre.o $(cheminJNI)/nettoyageTexte.o $(cheminJNI)/element.o $(cheminJNI)/fifo.o $(cheminJNI)/rechercheImageCritere.o $(cheminJNI)/rechercheImageComparaison.o $(cheminJNI)/filtrageTexte.o $(cheminJNI)/majAppli.o $(cheminJNI)/descripteurTexte.o $(cheminJNI)/configuration.o  $(cheminJNI)/interface.o $(cheminJNI)/indexationAudio.o $(cheminJNI)/indexationImage.o $(cheminJNI)/rechercheAudio.o $(cheminJNI)/rechercheTexteCritere.o -lc -lm

clean : 
	rm -f ./$(cheminJNI)/JNI.class ./$(cheminJNI)/libJNI.so ./$(cheminJNI)/JNI_JNI.h ./$(cheminJNI)/*.o ./$(cheminBoundary)/*.class ./$(cheminBoundary)/*.h ./$(cheminControleur)/*.class ./$(cheminTest)/*.class


# Pour executer dans le repertoire src
# java -cp . -Djava.library.path=./com/example/pfr/JNI com.example.pfr.test.Main



