get_next_line
=============

Usages:
Avec un fichier: cat "fichier" | ./exec
Avec l'entree standard: ./exec

Details:

Récupère x caractères depuis un file descriptor jusqu’à rencontrer un caractère de retour chariot (backslash + n).

Le programme est composé de trois fonctions:

-my_realloc: Implémentation "maison" de la fonction realloc de la bibliothèque standard, son comportement interne diffère de la vraie fonction, en effet le tableau passé paramètre est COPIÉ dans un NOUVEAU tableau alloué avec n cases en plus de la taille du tableau passé en paramètre tandis que le véritable realloc renvoie le même tableau avec n cases en plus.
ex: tab1 = 5 cases, je realloc avec n = 6, je récupère un nouveau tableau contenant la même chose que tab1 mais avec n cases en plus, soit 11 cases.

-my_len: Copie de la fonction strlen() de la libc, elle renvoie la taille d'une chaine.

-get_next_line: Fonction qui prends en paramètre un file descriptor sous la forme d'un int et renvoie un char * représentant une ligne lue dans ce file descriptor. Une ligne étant définie par une suite continue de caractères prenant fin dès lors qu'un caractère backslash + n (ASCII 10 Décimal) est rencontré.

/!\ NOTE IMPORTANTE /!\

Ce projet étant réalisé dans le cadre de l'enseignement de l'Epitech, ce dernier est donc soumis a la norme de programmation de cette école, ce qui explique les choix d’implémentation parfois déroutants présents dans le code, notamment la déclaration des variables, l’utilisation de while au lieu de for, la "reimplementation" de fonctions de base telles que strlen et realloc etc...
