					/*		AUTEUR : AMBLARD Lucas			*/
					/*		DATE CREATION : 25/11/2021		*/
					/*----------------------------------------------------*/
					
#define _POSIX_C_SOURCE  2


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ImageCoul.h"

#include "fifo.h"
#include "element.h"
#include "../Configuration/modifParametre.c"


void main(int argc, char *argv[]){
	//Déclarations locales

	int n;	//correspond au .config
	char param[]="nbrbit";

	//fin decl

/*
	printf(" %d \n \r",argc);
	
	for(int i=0; i<argc; i++){
			printf(" argv[%d] : '%s' \n \r", i, argv[i]);
	}
	printf("passe 1\n");
	n=config(param);
printf("passe 2\n");
*/
	n=config(param);
	if(n==1 || n==2 || n==3){
		printf("correct param\n");
		IdxImage(argv[1],n);
	}
	else
	{
		printf("erreur param\n");
	}

	printf("\n test fini \n \r");
	
/*	
	char tampon[1000];
        FILE *sortie;
 
        if ((sortie = popen ("./appel.sh", "r")) == NULL) {
                fprintf (stderr, "erreur");
                //return EXIT_FAILURE;
        }
 
        while (fgets (tampon, sizeof tampon, sortie) != NULL) {
                fputs (tampon, stdout);
        }
 
        fclose (sortie);
       // return EXIT_SUCCESS;
*/
}



