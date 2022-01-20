# ProjetFilRouge
*Auteurs : AMBLARD Lucas, BELLER Willy, COUFFIN Manon, JOBERT Pauline et LEVANEN Antoine*
dernière mise à jour du README.md : 20/01/2022


Installation
----
Pour récupérer le projet, il faut dans un premier temps télécharger ce qui permettra de le faire fonctionner :
* Télécharger le code sur le gitub en suivant le lien : https://github.com/PaulineJobs/ProjetFilRouge
* Récupérer le Corpus disponible **au même endroit**
* **Décompresser** le Corpus avec la ligne : ```unzip Corpus.zip```

Il ne reste plus qu'à lancer le code avec les lignes de commande :
```
$ cd code/Interface
$ make
```

Présentation du projet
----
Ce projet est un moteur de recherche en language C, qui compare et recherche des fichiers audios, images (N&B ou RVB) et textes. Ces derniers sont stockés dans un Corpus et chacun d'entre eux possède un descripteur.

![lienLogitielEnvironnement](https://user-images.githubusercontent.com/92680110/150433772-e3128b03-0004-41a3-abb5-70d4b325715c.png)

A Chaque recherche, le logiciel va aller chercher la reponse au près des descripteurs des fichiers. L'admin lui va avoir accés au Coorpus pour y ajourter des fichiers ou en retirer. 

![algo](https://user-images.githubusercontent.com/92680110/150434166-d3b6f2fb-9e18-4ecb-9723-f64cfdde141d.png)
Voici l'organigrame représentant le système de fonctionnement du logitiel.



Architecture
----
|noms du répertoires|Fonctionnalités|
|-----------------|---------------------|
|Base_Descripteurs | Contient tous les descripteurs textes, images et audios|
|Liste_Descripteurs|Contient toutes les listes des descripteurs|
|code|Contient tous les fichiers.c et fichiers.h qui servent à faire tourner le projet ainsi que son makefile|
|sujet|Contient l'énoncé du projet, son cahier des charges|
