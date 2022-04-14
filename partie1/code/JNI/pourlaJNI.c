#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <unistd.h>

#include <jni.h>        // JNI header provided by JDK
#include "../../../pfr/src/main/java/com/example/pfr/boundary/com_example_pfr_JNI_JNI.h"   // Generated


#include "pourlaJNI.h"
#include "../Interface/interface.h"



#include "../Configuration/configuration.h"

#include "../IndexationAudio/indexationAudio.h"
#include "../RechercheAudio/arbre.h"
#include "../RechercheAudio/rechercheAudio.h"


#include "../IdxIm/fifo.h"
#include "../IdxIm/element.h"
#include "../IdxIm/IdxIm_V1.h"

#include "../RechercheImage/RechercheImComp.h"
#include "../RechercheImage/RechercheImCrit.h"

#include "../Indexation_texte/descripteurTexte.h"
#include "../RechercheTexte/rechercheTexte.h"

JNIEXPORT void JNICALL Java_com_example_pfr_JNI_JNI_majAppli(JNIEnv *env, jobject thisObj){
    demarrageApplication();
    return ;
}

JNIEXPORT int JNICALL Java_com_example_pfr_JNI_JNI_valeurConfiguration(JNIEnv *env, jobject thisObj, jstring javaNom){
	
    const char *cNom = (*env)->GetStringUTFChars(env,javaNom, NULL);
	int resultat =  valeurParametre(cNom);
    return resultat;
}


JNIEXPORT jstring JNICALL Java_com_example_pfr_JNI_JNI_rechercheImageParCritere(JNIEnv *env, jobject thisObj, jstring critere){
    const char *criterechar= (*env)->GetStringUTFChars(env,critere, NULL);
    
    char* res = rechercheImageParCriteres(criterechar[0]);
    
    return (*env)->NewStringUTF(env, res);
}


JNIEXPORT jstring JNICALL Java_com_example_pfr_JNI_JNI_rechercheImageParComp(JNIEnv *env, jobject thisObj, jstring fichierRef, jstring type){
    const char *fichierRefC= (*env)->GetStringUTFChars(env,fichierRef, NULL);
    const char *typeC= (*env)->GetStringUTFChars(env,type, NULL);
    char* res = rechercheImageParComparaisons((char*)fichierRefC, (char*)typeC);
    
    return (*env)->NewStringUTF(env, res);
}


JNIEXPORT jstring JNICALL Java_com_example_pfr_JNI_JNI_rechercheAudioParComp(JNIEnv *env, jobject thisObj, jstring fichierRef){
    const char *fichierDeReference= (*env)->GetStringUTFChars(env,fichierRef, NULL);
    
    char* res = rechercheAudioParComparaisons((char*)fichierDeReference);
    
    return (*env)->NewStringUTF(env, res);
}


JNIEXPORT void JNICALL Java_com_example_pfr_JNI_JNI_modifierParam(JNIEnv *env, jobject thisObj, jint numero, jint valeur){
    
    modifierParametre ((int) numero, (int) valeur);
    
    return ;
}

JNIEXPORT void JNICALL Java_com_example_pfr_JNI_JNI_afficherConfig(JNIEnv *env, jobject thisObj){
	afficherLaconfig();
    return ;
}

JNIEXPORT int JNICALL Java_com_example_pfr_JNI_JNI_ouvertureFichier(JNIEnv *env, jobject thisObj, jstring javaNom){
	
    const char *nomFichier= (*env)->GetStringUTFChars(env,javaNom, NULL);
	int resultat =  ouvertureFichier((char*)nomFichier);
    return resultat;
}

JNIEXPORT jstring JNICALL Java_com_example_pfr_JNI_JNI_rechercheTexteParCritere(JNIEnv *env, jobject thisObj, jstring critere){
    const char *criterechar= (*env)->GetStringUTFChars(env,critere, NULL);
   printf("change");
    char* res = rechercheTexteParCriteres((char*)criterechar);
    
    return (*env)->NewStringUTF(env, res);
}




//demarrage de l'appli : indexation des fichiers, maj des listes de descripteurs..etc
void demarrageApplication(){
	majOuverture();
	
}





//Verification du mdp de connexion
int verificationConnexion(char * motDePasse){
	return verifierConnexion(motDePasse);
}



int rechercheParNomFichiers(char* nomFichier){
	return RechercheClassique(nomFichier) ;
}

char * rechercheTexteParCriteres(char* critere){
	return rechercheCritereTxt(critere);
}


char* rechercheImageParCriteres(char critere){
	return recherchCritere(critere);
}

char* rechercheImageParComparaisons(char * fichierDeReference, char * typeImage){
	return RechercheImgComp(fichierDeReference,typeImage);
}



char * rechercheAudioParComparaisons(char * fichierDeReference){
    printf("passe fction pourLaJNI \n");
	return resultatRechercheAudio(fichierDeReference);
}


void modifierParametre (int numeroDuParametre, int nouvelleValeur){
	editConfig(numeroDuParametre , nouvelleValeur );
}


int valeurParametre(char* nom){
	return config(nom);

}

void afficherLaconfig(){
	afficherConfig();
}


int ouvertureFichier(char* nomFichier){
	return RechercheClassique(nomFichier);
	
}

/*

int main(){
	printf("hello\n");
	char* resultat;
	resultat = rechercheImageParCriteres('R');
	printf("le resultat est \n%s \n", resultat);
	
}*/











