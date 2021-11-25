#include <stdio.h>

int main(int argc, char* argv[])
{
//lire un fichier texte dans le repertoire courrant
char const* const fileName = "config.txt";

FILE* file = fopen(fileName, "r"); 

if(!file){
printf("\n Imposible d'ouvrir : %s ", fileName);
return -1;
}

printf("\nOuverture du fichier\n");

char line[500];

while (fgets(line, sizeof(line), file)) {

printf("%s", line); 
}
fclose(file);
return 0;
}