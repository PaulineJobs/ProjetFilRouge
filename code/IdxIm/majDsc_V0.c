#include <dirent.h>
#include <string.h>
#include <stdio.h>
 
int main()
{
//decl
    char* tmpDsc = ".dsc";
    char* retDsc;
    
    char theFileNameDsc[3]="";
    char caractereDsc;
    int cptDsc=0;
    int quitterDsc=0;    
   
    char* tmpIm = ".txt";
    char* retIm;
    
    char theFileNameIm[3]="";
    char caractereIm;
    int cptIm=0;
    int quitterIm=0;
    
    int equa;
    int cptEq=0;

//fin decl


    printf("passe0 \n \r");
    struct dirent *dirDsc;
    struct dirent *dirIm;
    // opendir() renvoie un pointeur de type DIR. 
    DIR* dsc = opendir("."); 

    
    if (dsc)
    {
 		    
			while ((dirDsc = readdir(dsc)) != NULL){
			    retDsc = strstr(dirDsc->d_name, tmpDsc);
			    if(retDsc!=NULL){
			      	printf("%s\n", dirDsc->d_name);
				
				while(!quitterDsc){
				caractereDsc=dirDsc->d_name[cptDsc];
				if(caractereDsc=='.'){
				   quitterDsc=1;
				}
				else{
				   theFileNameDsc[cptDsc]=caractereDsc;
				   cptDsc++;
				}
				}
        DIR* im = opendir("../Corpus/IMAGE/RGB");	
	if(im){
   	while((dirIm=readdir(im)) != NULL){
   		retIm = strstr(dirIm->d_name, tmpIm);
   		if(retIm!=NULL){
			      	printf("%s\n", dirIm->d_name);
				
				while(!quitterIm){
				caractereIm=dirIm->d_name[cptIm];
				if(caractereIm=='.'){
				   quitterIm=1;
				}
				else{
				   theFileNameIm[cptIm]=caractereIm;
				   cptIm++;
				}
				}
				quitterIm=0;
				cptIm=0;
			      	printf("%s\n", theFileNameIm);				
				printf("passe1 \n \r");
				
				equa=strcmp(theFileNameDsc,theFileNameIm);
			    	if(equa==0){
			   	 printf("existe \n");
			   	 cptEq+=1;
			    	}
			}
			}
			if(dirIm==NULL && (cptEq==0)){
			remove(dirDsc->d_name);
			printf(" %s supprimé \n",dirDsc->d_name);
			}
			}

				quitterDsc=0;
				cptDsc=0;
			      	printf("%s\n", theFileNameDsc);				
			        printf("passe2 \n \r");
			        closedir(im);
			}
			}
			}
        closedir(dsc);

    }
