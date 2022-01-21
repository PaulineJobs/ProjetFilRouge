

interface: interface.c interface.h main.c ../Configuration/configuration.c ../Configuration/configuration.h ../RechercheAudio/rechercheAudio.c ../RechercheAudio/rechercheAudio.h ../IdxIm/IdxIm_V1.c ../IdxIm/IdxIm_V1.h ../IdxIm/fifo.c ../IdxIm/fifo.h ../IdxIm/element.c ../IdxIm/element.h ../RechercheImage/RechercheImComp.h ../RechercheImage/RechercheImComp.c ../RechercheImage/RechercheImCrit.h ../RechercheImage/RechercheImCrit.c ../Indexation_texte/descripteurTexte.c ../Indexation_texte/descripteurTexte.h ../Indexation_texte/nettoyageTexte.c ../Indexation_texte/nettoyageTexte.h ../Indexation_texte/filtrageTexte.c ../Indexation_texte/filtrageTexte.h
	gcc -c ../Indexation_texte/descripteurTexte.c -lm
	gcc -c ../Indexation_texte/nettoyageTexte.c -lm
	gcc -c ../Indexation_texte/filtrageTexte.c -lm
	gcc -c ../RechercheImage/RechercheImCrit.c -lm
	gcc -c ../RechercheImage/RechercheImComp.c -lm
	gcc -c ../IdxIm/IdxIm_V1.c -lm
	gcc -c ../IdxIm/fifo.c -lm
	gcc -c ../IdxIm/element.c
	gcc -c ../Configuration/configuration.c -lm
	gcc -c ../RechercheAudio/rechercheAudio.c -lm
	gcc -fno-stack-protector -c interface.c -lm
	gcc -c main.c -lm
	gcc -o interface.out interface.o configuration.o rechercheAudio.o main.o IdxIm_V1.o fifo.o element.o RechercheImCrit.o RechercheImComp.o descripteurTexte.o nettoyageTexte.o filtrageTexte.o -lm
	./interface.out

clean :
	rm -f prog *.o
	rm -f prog *.out
