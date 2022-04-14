

interface: ../RechercheAudio/arbre.h ../IndexationAudio/indexationAudio.c ../IndexationAudio/indexationAudio.h ../RechercheAudio/arbre.c interface.c interface.h main.c ../Configuration/configuration.c ../Configuration/configuration.h ../RechercheAudio/rechercheAudio.c ../RechercheAudio/rechercheAudio.h ../IdxIm/IdxIm_V1.c ../IdxIm/IdxIm_V1.h ../IdxIm/fifo.c ../IdxIm/fifo.h ../IdxIm/element.c ../IdxIm/element.h ../RechercheImage/RechercheImComp.h ../RechercheImage/RechercheImComp.c ../RechercheImage/RechercheImCrit.h ../RechercheImage/RechercheImCrit.c ../Indexation_texte/descripteurTexte.c ../Indexation_texte/descripteurTexte.h ../Indexation_texte/nettoyageTexte.c ../Indexation_texte/nettoyageTexte.h ../Indexation_texte/filtrageTexte.c ../Indexation_texte/filtrageTexte.h ../RechercheTexte/rechercheTexte.h
	gcc -c -g ../IndexationAudio/indexationAudio.c -lm
	gcc -c -g ../RechercheAudio/arbre.c -lm 
	gcc -c -g ../Indexation_texte/descripteurTexte.c -lm
	gcc -c -g ../Indexation_texte/nettoyageTexte.c -lm
	gcc -c -g ../Indexation_texte/filtrageTexte.c -lm
	gcc -c -g ../RechercheImage/RechercheImCrit.c -lm
	gcc -c -g ../RechercheImage/RechercheImComp.c -lm
	gcc -c -g ../IdxIm/IdxIm_V1.c -lm
	gcc -c -g ../IdxIm/fifo.c -lm
	gcc -c -g ../IdxIm/element.c
	gcc -c -g ../Configuration/configuration.c -lm
	gcc -c -g ../RechercheAudio/rechercheAudio.c -lm
	gcc -c -g ../RechercheTexte/rechercheTexte.c -lm
	gcc -fno-stack-protector -c -g interface.c -lm
	gcc -c main.c -lm
	gcc -o interface.out indexationAudio.o arbre.o interface.o configuration.o rechercheAudio.o main.o IdxIm_V1.o fifo.o element.o RechercheImCrit.o RechercheImComp.o descripteurTexte.o nettoyageTexte.o filtrageTexte.o rechercheTexte.o -lm
	./interface.out

clean :
	rm -f prog *.o
	rm -f prog *.out
