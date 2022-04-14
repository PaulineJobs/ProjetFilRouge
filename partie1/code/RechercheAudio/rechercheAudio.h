


					/*-------------------------------------------/
					/        AUTEUR : JOBERT Pauline             /
                    /-------------------------------------------*/
                    
#ifndef MODULE_rechercheAudio
#define MODULE_rechercheAudio


//on compare un fichier audio avec tous les autres situés dans le repertoire
ARBRE comparaisonRepertoire(char *);
//Compare le fichier 1 avec le fichier 2
float comparaisonDeuxFichiers(char* , char* );
//Compare deux histogrammes
void comparaisonDeuxHistogrammes(int , int , int , char*  , char* , int* , float* , float* );
//Lance un fichier audio à partir de son nom avec vlc
void lanceFichierAudio(char *fichierAudio);
//Demande la fichier à comparer 
void saisieRechercheAudio();
//affiche les resultats
void afficherResultats(ARBRE);



//Pour le JNI
// renvoie le resultat de la recherche en fonction du paramètre d'entree 
char *resultatRechercheAudio(char* souhait);




#endif
