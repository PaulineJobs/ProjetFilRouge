


interface: interface_globale.c interface_globale.h test_interface.c ../Configuration/configuration.c ../Configuration/configuration.h
	gcc -c ../Configuration/configuration.c
	gcc -c interface_globale.c
	gcc -c test_interface.c
	gcc -o interface.out interface_globale.o test_interface.o configuration.o
	./interface.out

clean :
	rm -f prog *.o
	rm -f prog *.out