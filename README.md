get_next_line
=============

Récupère x caractères depuis un file descriptor jusqu’à rencontrer un caractère de retour chariot (backslash + n).

Le programme est composé de trois fonctions:

-my_realloc: Copie de la fonction realloc() de la libc, elle permet d'étendre la taille d'un tableau à n cases EN PLUS de sa taille d'origine.
ex: J'ai un tableau de 6 cases, je le réalloue avec n = 5, mon tableau aura une taille de 11 cases.

-my_len: Copie de la fonction strlen() de la libc, elle renvoie la taille d'une chaine.

-get_next_line: Fonction qui prends en paramètre un file descriptor sous la forme d'un int et renvoie un char * représentant une ligne lue dans ce file descriptor. Une ligne étant définie par une suite continue de caractères prenant fin dès lors qu'un caractère backslash + n (ASCII 10 Decimal) est rencontré.
