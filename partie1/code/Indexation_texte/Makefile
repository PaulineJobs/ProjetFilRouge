nettoyage: nettoyageTexte.c nettoyageTexte.h tstNettoyageTexte.c
	gcc -c nettoyageTexte.c
	gcc -c tstNettoyageTexte.c
	gcc -o nettoyage.out tstNettoyageTexte.o nettoyageTexte.c
	./nettoyage.out

filtrage: filtrageTexte.c filtrageTexte.h tstFiltrageTexte.c
	gcc -c filtrageTexte.c
	gcc -c tstFiltrageTexte.c
	gcc -o filtrage.out tstFiltrageTexte.o filtrageTexte.c

descripteur: nettoyageTexte.c nettoyageTexte.h filtrageTexte.c filtrageTexte.h descripteurTexte.c descripteurTexte.h tstDescripteurTexte.c
	gcc -c nettoyageTexte.c
	gcc -c filtrageTexte.c
	gcc -c descripteurTexte.c
	gcc -c tstDescripteurTexte.c
	gcc -o descripteur.out tstDescripteurTexte.o nettoyageTexte.c filtrageTexte.c descripteurTexte.c
	
clean :
	rm -f prog *.o
	rm -f prog *.out
