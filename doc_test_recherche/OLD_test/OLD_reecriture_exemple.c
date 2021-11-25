#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *ptrFichier1, *ptrFichier2;
    //nom du fichier
    char fichierTeste[] = "teste.txt";
    char c;
    int del_line, temp = 1;

    ptrFichier1 = fopen(fichierTeste, "r");
    //ouvre le fichier en lecture seul
    
    //afficher le contenus du fichier
    c = getc(ptrFichier1);
    while (c != EOF) {
        printf("%c", c);
        c = getc(ptrFichier1);
    }

    //ask user for line number to be deleted.
    printf("\n\n Enter line number to be deleted and replaced");
    scanf("%d", &del_line);
    //take fp1 to start point.
    rewind(ptrFichier1);
    //open copy.c in write mode
    ptrFichier2 = fopen("copy.c", "w");
    c = getc(ptrFichier1);
    while (c != EOF) {// tant que le fichier n'est pas a la fin
        if (c == ' ') {
           temp++;
           }
        //till the line to be deleted comes,copy the content from one file to other
        if (temp != del_line){
            putc(c, ptrFichier2);//copie du contenu
        }else{  //when the line to be deleted comes
        
            while ((c = getc(ptrFichier1)) != ' ') {
            }
            //read and skip the line ask for new text
            printf("\nEnter new text");
            //flush the input stream
            fflush(stdin);
            putc(' ', ptrFichier2);  //put '' in new file

            while ((c = getchar()) != ' '){
                putc(c, ptrFichier2);
                //take the data from user and place it in new file
                fputs(" ", ptrFichier2);
                temp++;
            }
            //continue this till EOF is encountered
            c = getc(ptrFichier1);
            }
        //close both files
        fclose(ptrFichier1);
        fclose(ptrFichier2);
        //remove original file
        // remove(fichierTeste);
        //rename new file with old name opens the file in read mode
        rename("copy.c", "teste_V2.txt");
        ptrFichier1 = fopen(fichierTeste, "r");
        //reads the character from file
        c = getc(ptrFichier1);
        //until last character of file is encountered
        while (c != EOF){
            printf("%c", c);
            //all characters are printed
            c = getc(ptrFichier1);
        }
        //close the file pointer
        fclose(ptrFichier1);
        return 0;
    } 
}



//  https://www.w3schools.in/c-program/replace-a-specific-line-in-a-text-file/