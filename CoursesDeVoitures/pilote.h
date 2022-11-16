#ifndef H_PILOTE
#define H_PILOTE
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "general-autre.h"
    #include "fichier.h"
#endif



void ajouterPilotes();
void afficherPilotes(Pilotes *, int *);
void trierPilotes(Pilotes *, int *);
void echangerPilotes(Pilotes *, Pilotes *);
void rechercherPilotes(Pilotes *, int *);
void modifierPilotes(Pilotes *, int *);
