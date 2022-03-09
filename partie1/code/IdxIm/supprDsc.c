#include <dirent.h>
#include <string.h>
#include <stdio.h>
 
int supprDsc()
{
//decl
    char* tmpDsc = ".dsc";
    char* retDsc;
    char theFileNameDsc[3]="";
    char caractereDsc;
    int cptDsc=0;
    int quitterDsc=0;    
   
    char* tmpIm = ".txt";
    char* retImCoul;
    char theFileNameImCoul[3]="";
    char caractereImCoul;
    int cptImCoul=0;
    int quitterImCoul=0;
    
    char* retImNB;
    char theFileNameImNB[3]="";
    char caractereImNB;
    int cptImNB=0;
    int quitterImNB=0;
    
    int equa;
    int cptEq=0;

//fin decl


    printf("passe0 \n \r");
    struct dirent *dirDsc;
    struct dirent *dirImCoul;
    struct dirent *dirImNB;
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
        DIR* imCoul = opendir("../Corpus/IMAGE/RGB");	
	if(imCoul){
   	while((dirImCoul=readdir(imCoul)) != NULL){
   		retImCoul = strstr(dirImCoul->d_name, tmpIm);
   		if(retImCoul!=NULL){
			      	printf("%s\n", dirImCoul->d_name);
				
				while(!quitterImCoul){
				caractereImCoul=dirImCoul->d_name[cptImCoul];
				if(caractereImCoul=='.'){
				   quitterImCoul=1;
				}
				else{
				   theFileNameImCoul[cptImCoul]=caractereImCoul;
				   cptImCoul++;
				}
				}
				quitterImCoul=0;
				cptImCoul=0;
			      	printf("%s\n", theFileNameImCoul);				
				printf("passe1 \n \r");
				
				equa=strcmp(theFileNameDsc,theFileNameImCoul);
			    	if(equa==0){
			   	 printf("existe \n");
			   	 cptEq+=1;
			    	}
			}
			}
			if(cptEq==0 && dirImCoul==NULL){
			DIR* imNB = opendir("../Corpus/IMAGE/NB");	
					if(imNB){
					   	while((dirImNB=readdir(imNB)) != NULL){
					   		retImNB = strstr(dirImNB->d_name, tmpIm);
					   		if(retImNB!=NULL){
								      	printf("%s\n", dirImNB->d_name);
									
									while(!quitterImNB){
									caractereImNB=dirImNB->d_name[cptImNB];
									if(caractereImNB=='.'){
									   quitterImNB=1;
									}
									else{
									   theFileNameImNB[cptImNB]=caractereImNB;
									   cptImNB++;
									}
									}
									quitterImNB=0;
									cptImNB=0;
								      	printf("%s\n", theFileNameImNB);				
									printf("passe3 \n \r");
									
									equa=strcmp(theFileNameDsc,theFileNameImNB);
								    	if(equa==0){
								   	 printf("existe \n");
								   	 cptEq+=1;
								    	}
								}
								}
								if(dirImNB==NULL && (cptEq==0)){
									remove(dirDsc->d_name);
									printf(" %s supprimé \n",dirDsc->d_name);
								}
								}
								closedir(imNB);
						}
			}
			closedir(imCoul);
			}
				cptEq=0;
				quitterDsc=0;
				cptDsc=0;
			      	printf("%s\n", theFileNameDsc);				
			        printf("passe2 \n \r");
			        //closedir(imCoul);
			        //closedir(imNB);
			}
			}
			
        closedir(dsc);

    }
