#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    // on ouvre le fichier
  FILE *fichier = NULL;
  fichier  =fopen("teste.txt","r");
  
  if(fichier == NULL){//getion erreurs
    printf("on ne peut pas ouvrir le fichier");
    exit(1);
  }
  // variable et char
  char texte[256] = "stoplist";
  char param[256];
  int valeurParam = 0;

  //lire le contenu (1er ligne)
  fgets(param, 255, fichier);
  printf("%s\n", param);

  //on compare la chaine de caratere avec le parametre désiré
  int a = strcoll(param, texte);
  printf("%d\n", a);
  printf("%s\n", param);

  while(strcmp(param, texte) == 0){
        
  fgets(param, 255, fichier);
  printf("%s", param);    

  }

  return 0;
}
/*
int main() {          //test fonctionnel
  char str1[] = "abcd", str2[] = "abCd", str3[] = "abcd";
  int result;

  // comparing strings str1 and str2
  result = strcmp(str1, str2);
  printf("strcmp(str1, str2) = %d\n", result);

  // comparing strings str1 and str3
  result = strcmp(str1, str3);
  printf("strcmp(str1, str3) = %d\n", result);

  return 0;
}*/