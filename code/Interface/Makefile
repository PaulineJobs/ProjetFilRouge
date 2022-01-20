

interface: interface.c interface.h main.c ../Configuration/configuration.c ../Configuration/configuration.h ../RechercheAudio/rechercheAudio.c ../RechercheAudio/rechercheAudio.h
	gcc -c ../Configuration/configuration.c
	gcc -c ../RechercheAudio/rechercheAudio.c
	gcc -fno-stack-protector -c interface.c
	gcc -c main.c
	gcc -o interface.out interface.o configuration.o rechercheAudio.o main.o
	./interface.out

clean :
	rm -f prog *.o
	rm -f prog *.out
