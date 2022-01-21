

					/*		AUTEUR : AMBLARD Lucas			*/
					/*		DATE CREATION : 25/11/2021		*/
					/*----------------------------------------------------*/
					

#ifndef IMAGECOUL_H_INCLUS     /*--  Inclusion conditionnelle --> si pas déjà inclus           */
#define IMAGECOUL_H_INCLUS     /*--  alors créer la constante symbolique MODULE_IMAGE_H_INCLUS */

//#include "element.h"

/* DECLARATIONS DES FONCTIONS */

//void quantifImage(int n, char* fileName);
void VerifTypeFichierImage(char *nomFichierint, int type);
void initTab(int* tab, int nbVal);
void Histogramme(int* tabValPix,int valPix);
int DecompoMSB(int valC, int n);
int calculValPixRVB(int elValR, int elValV, int elValB,int n);
void recupIdIm(char* fileName, char* theFileName);
void creaDescripteur(char* theFileName, int nbVal, int* tabValPix, int type);
void IdxImage(char* fileName, int n, int type);

void INDEXIMAGE(char* nomFichier,int type);


#endif
