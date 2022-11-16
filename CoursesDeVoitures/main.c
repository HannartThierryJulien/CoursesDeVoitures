/*
NOTES :
    - à ameliorer :
        - pour les pointeurs, les remplacer malloc par realloc
        - le cas 1 de la fct recherche de la voiture va renvoyer 2x la même voiture dans le cas où deux pilotes d'une même famille conduise une même voiture.
        Il faudrait faire une vérification, au moyen de qq boucles et if, afin de ne pas stocker dans temp_voiture la voiture qui a été trouvée par la recherche.
        - une fct sauvegarde de fichier
            -> voir même une fonction qui lit et sauvegarde une structure dans un fichier.
                -> par exemple si on lui transmet le nombre "1" on sait qu'il faut uniquement lire le fichier.
                Et si le nombre en parametre est "0", faire une sauvegarde de la struct passée en parametre.
        - retirer les "else" inutile...
        -

*/

#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

int main()
{
    printf("\n\n ---- NOTES DESTINEES A L UTILISATEUR ----\n\n");
    printf("-> Si vous souhaitez ecrire un nombre a virgule, remplacez la virgule par un point.\n");
    printf("-> N utilisez pas de majuscules.\n\n");


    system("PAUSE");

    menuPrincipal();
    return 0;
}
