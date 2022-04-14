#ifndef JNI
#define JNI


void demarrageApplication();

int verificationConnexion(char * motDePasse);

int rechercheParNomFichiers(char* nomFichier);


char * rechercheTexteParCriteres(char* critere);

char* rechercheImageParCriteres(char critere);

char* rechercheImageParComparaisons(char * fichierDeReference, char * typeImage);

char * rechercheAudioParComparaisons(char * fichierDeReference);

void modifierParametre (int numeroDuParametre, int nouvelleValeur);

int valeurParametre();

void afficherLaconfig();

//return 1 si le fichier est connu et l'ouvre, return 0 sinon
int ouvertureFichier(char* nomFichier);

#endif
