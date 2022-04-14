# ProjetFilRouge : DTSoft (Durable Technical Software)   


## Manuel d'installation et d'utilisation    


###  Avant l'installation    

```
   $cd ~    
   $ type java 
```   
  
Ceci vous retournera un résultat du type :     
  
  > java is *resultat1*    
 
Ensuite, faites :     
  
  > ll *resultat1*

Ceci vous retournera un résultat du type :
 
  > *resultat1* -> *resultat2* 
  
  Ensuite, faites : 
  
  > ll *resultat2*
  
Ceci vous retournera un résultat du type :
  
  > *resultat1* -> *monResultat*/bin/java
  
Copiez soignesement *monResultat*  et mettez le de coté, nous le réutiliserons plus tard.
  

###  Installation

Mettez vous dans l'emplacement souhaité et clonez le projet : ```$ git cone chemin/voulu/pour/copier/le/projet ```

Deplacez vous dans l'emplacement suivant : ```$ cd ProjetFilRouge/partie1 ```

Dézippez le fichier suivant : ```$ unzip -r Corpus.zip Corpus ```

Déplacez vous dans l'emplacement suivant : ```$ cd ../partie2/src/main/java ```

Ouvrez le fichier : ```$ gedit Makefile ```

**A la première ligne**, remplacez la valeur du JAVA_HOME par *monResultat* récupéré précedement
Fermez le fichier 


###  Execution
***Lancer l'application textuelle :***
* Dans le projet, se placer au niveau de *ProjetFilRouge/pfr/src/main/java.*
* Faire un ```$ make clean ```
* Faire un : ```$ make all ```
* Excuter avec  : 
```$ java -cp . -Djava.library.path=./com/example/pfr/JNI com.example.pfr.test.Main ```
   
***Lancer l'application graphique***
* Ouvrir le Projet Fil rouge au niveau du dossier pfr avec IntelliJ
* Ouvrir la classe **"Application"** se situant dans *ProjetFilRouge/pfr/src/main/java.com/example/pfr*
* Run la classe

### Détail des fonctionnalités

Vous pourrez directement les retrouver dans notre rapport fourni dans ProjetFilRouge/partie2
