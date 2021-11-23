/*config.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE_MAX 100 // Tableau de taille 100 (correspond à une ligne de config)

int main() {
	char fileName[] = ".configtst";
	char strSearch[] = "varTestFourch";
	FILE* fichier = NULL;
 
    fichier = fopen(fileName, "r+");
 
    if (fichier != NULL)
    {
        //fputc('A', fichier); // Écriture du caractère A
        fclose(fichier);
    }
    else
    	fprintf(stderr,"Erreur smarchepas !");

    //int trouve = find(fileName, strSearch);

    //trouve = findByLigne(fileName, strSearch);

    int trouve = editByLigne(fileName, strSearch);
 
    return 0;
}

// Retourne 1 si la chaine est trouvée dans le
// fichier specifié, sinon 0 (Algorithme naif)

int find(char *fileName,char *strSearch) {

  FILE *f;
  char c;
  int found=0;
  int pos=0;
  int length;

  f = fopen(fileName,"r");
  if( f == NULL )
    return 0;

  length=strlen(strSearch);

  while( fread(&c,1,1,f)>0 && !found ) {

    if( c==strSearch[pos] ) {
      pos++;
    } else {
      if(pos!=0) {
        // On doit rembobiner !
        fseek(f,-pos,SEEK_CUR);
        pos=0;
      }
    }

    found = (pos==length);

  }
  fclose(f);

  return found;

}

//Recherche une variable de configuration strSearch dans le fichier .config (fileName)
int findByLigne(char *fileName,char *strSearch) {

  FILE *f;
  char ligne[100];
  int found=0;
  int pos=0;
  int length;
  char mot[strlen(strSearch)];

  f = fopen(fileName,"r+");
  if( f == NULL )
    return 0;

  length=strlen(strSearch);

  while(fgets(ligne, 80, f) != NULL)
	{
		strtok(ligne, "="); //sélectionne le string avant le = (delimiteur)
		if(strcmp(ligne, strSearch)==0)
	    	printf("%s\n", ligne);
	}
  fclose(f);

  return found;

}

//Edite la variable de configuration strSearch dans le fichier .config (fileName)
int editByLigne(char *fileName,char *strSearch) {

  FILE *f;
  char ligne[100];
  int found=0;
  int pos=0;
  int length;
  char mot[strlen(strSearch)];

  f = fopen(fileName,"r+");
  if( f == NULL )
    return 0;

  length=strlen(strSearch);

  while(fgets(ligne, 80, f) != NULL)
  {
    strtok(ligne, "="); //sélectionne le string avant le = (delimiteur)
    if(strcmp(ligne, strSearch)==0){
      printf("%s\n", ligne);
      fseek(f,strlen(ligne)+1,SEEK_CUR);
      fputc('A', f);
    }

    //printf("%ld\n",ftell(f));
  }
  char chaine[1000] = "";
  fgets(chaine, 1000, f);
  fclose(f);

  return found;

}