lecture.o : lecture.c
	gcc -c -o lecture.o lecture.c

tst_lecture.o : tst_lecture.c
	gcc -c -o tst_lecture.o tst_lecture.c
	
prog : tst_lecture.o lecture.o
	gcc -o prog lecture.o tst_lecture.o
	