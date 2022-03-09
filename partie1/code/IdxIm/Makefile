test1 : IdxIm_V1.c ImageCoul.h element.c element.h fifo.c fifo.h
	gcc -c element.c -lm
	gcc -c fifo.c -lm
	gcc -c IdxIm_V1.c -lm 	
	gcc -o test1.out IdxIm_V1.o element.o fifo.o -lm

clean : 
	rm -rf *.o 
	rm -rf *.out
