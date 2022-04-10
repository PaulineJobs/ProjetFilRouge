# ProjetFilRouge : DTSoft (Durable Technical Software)   


## Manuel d'installation et d'utilisation    


###  Avant l'installation    

   > cd ~    
   > type java    
  
  Ceci vous retournera un résultat du type :     
  
  > java is *resultat1*    
 
  Ensuite, faites :     
  
  > ll *resultat1*

  Ceci vous retournera un résultat du type :
 
  > *resultat1* -> *resultat2* 
  
  Ensuite, faites : 
  
  > ll *resultat2*
  
  Ceci vous retournera un résultat du type :
  
  *resultat1* -> *monResultat*/bin/java
  
  Copiez soignement *monResultat* et mettez le de coté, nous le réutiliserons plus tard
  

###  Installation

Mettez vous dans l'emplacement souhaité et clonez le projet :

> git cone MettreLeLien

Deplcez vous dans l'emplacement suivant :
> cd ProjetFilRouge/partie1

Dézippez le fichier suivant :
> unzip -r Corpus.zip Corpus

Déplacez vous dans l'emplacement suivant :
> cd ../partie2/src/main/java

Ouvrez le fichier suivant 
> gedit Makefile

A la première ligne, remplacez la valeur du JAVA_HOME par *monResultat* récupéré précedement
Fermez le fichier 


###  Execution

Executez les commandes suivantes et suivez les instructions d'utilisation :
> make all
> java -cp machin truc


## Détail des fonctionnalités

Vous pourrez directement les retrouver dans notre rapport fourni dans ProjetFilRouge/partie2 (il faudra l'y mettre bien sur)


