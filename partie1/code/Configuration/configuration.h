#ifndef configuration
#define configuration


void afficherConfig();
void saisieConfig();


//Pour la JNI
//Change la config en fonction du numero de la config et de la nouvelle valeur
void editConfig(int , int );
//recupere la valeur du parametre 
int config(char nom[]);


#endif
