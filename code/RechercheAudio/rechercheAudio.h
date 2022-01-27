


					/*-------------------------------------------/
					/        AUTEUR : JOBERT Pauline             /
                    /-------------------------------------------*/
                    
#ifndef MODULE_rechercheAudio
#define MODULE_rechercheAudio

//on compare un fichier audio avec tous les autres situés dans le repertoire
void comparaisonRepertoire(char *);
//Compare le fichier 1 avec le fichier 2
float comparaisonDeuxFichiers(char* , char* );
//Compare deux histogrammes
void comparaisonDeuxHistogrammes(int , int , int , char*  , char* , int* , float* , float* );
//demande le nom d'un fichier et renvoie le resultat de la recherche 
void resultatRechercheAudio();
//Lance un fichier audio à partir de son nom avec vlc
void lanceFichierAudio(char *fichierAudio);







#endif
