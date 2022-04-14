

					/*-------------------------------------------/
					/        AUTEUR : JOBERT Pauline             /
                    /-------------------------------------------*/
                    

#ifndef MODULE_Audio           
#define MODULE_Audio


//Indexation Audio
//Verifie que le fichier est bien un fichier audio avant indexation
void VerifTypeFichierAudio(char *nomFichier);
//Lit le paramètre m dans la configuration
int lireConfigAudioM();
//Lit le paramètre n dans la configuration
int lireConfigAudioN();
//Cree l'histogramme d'un fichier audio
void histogrammeAudio(char* nomDuFichier);
//Cree le descripteur d'un fichier audio avec son identifiant et son histogramme 
void descripteurAudio(int **histogramme,char* NomFichierParam, int m, int k);
//écrit le nom du fichier dans la liste des descripteurs
void miseAJourListeDescripteursAudio(char* nomFichierParam);


#endif
