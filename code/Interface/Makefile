

interface: interface.c interface.h main.c ../Configuration/configuration.c ../Configuration/configuration.h ../RechercheAudio/rechercheAudio.c ../RechercheAudio/rechercheAudio.h ../Indexation_texte/nettoyageTexte.c ../Indexation_texte/nettoyageTexte.h ../Indexation_texte/filtrageTexte.c ../Indexation_texte/filtrageTexte.h ../Indexation_texte/descripteurTexte.c ../Indexation_texte/descripteurTexte.h 
	gcc -c ../Configuration/configuration.c 
	gcc -c ../Indexation_texte/nettoyageTexte.c
	gcc -c ../Indexation_texte/filtrageTexte.c
	gcc -c ../Indexation_texte/descripteurTexte.c
	gcc -c ../RechercheAudio/rechercheAudio.c
	gcc -fno-stack-protector -c interface.c
	gcc -c main.c
	gcc -o interface.out  nettoyageTexte.o filtrageTexte.o descripteurTexte.o interface.o configuration.o rechercheAudio.o main.o
	./interface.out

clean :
	rm -f prog *.o
	rm -f prog *.out



