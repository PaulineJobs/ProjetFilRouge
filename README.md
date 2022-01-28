# ProjetFilRouge
*Auteurs : AMBLARD Lucas, BELLER Willy, COUFFIN Manon, JOBERT Pauline et LEVANEN Antoine*

Dernière mise à jour du README.md : 26/01/2022


Installation
----
Pour récupérer le projet, il faut dans un premier temps télécharger ce qui permettra de le faire fonctionner :
* Téléchargez l'application sur le gitub en suivant le lien : https://github.com/PaulineJobs/ProjetFilRouge
* Clonnez le projet sur votre ordinateur et placez vous à l'interieur
* **Décompressez** le Corpus avec la ligne de code suivante :
```$ unzip Corpus.zip```
Il ne reste plus qu'à lancer le code avec les lignes de commande suivantes :
```
$ cd code/Interface
$ make
```
**ATTENTION**, il faut être sous Linux pour faire tourner le logiciel.

Présentation du projet
----
Ce projet est un moteur de recherche en language C, qui compare et recherche des fichiers audios, images (N&B ou RVB) et textes. Ces derniers sont stockés dans un Corpus et chacun d'entre eux possède un descripteur.

![lienLogitielEnvironnement](https://user-images.githubusercontent.com/92680110/150433772-e3128b03-0004-41a3-abb5-70d4b325715c.png)

A chaque recherche, le logiciel va aller chercher la reponse au près des descripteurs des fichiers. L'administrateur lui va avoir accés au Corpus pour y ajourter des fichiers ou en retirer. 

Architecture
----
|noms du répertoires|Fonctionnalités|
|-----------------|---------------------|
|Base_Descripteurs | Contient tous les descripteurs textes, images et audios|
|Liste_Descripteurs|Contient toutes les listes des descripteurs|
|code|Contient tous les fichiers.c et fichiers.h qui servent à faire tourner le projet ainsi que son makefile|
|sujet|Contient l'énoncé du projet, son cahier des charges|
|Validation_G5|Contient le script de validation du 21/01/2022 et le complément de validation|
