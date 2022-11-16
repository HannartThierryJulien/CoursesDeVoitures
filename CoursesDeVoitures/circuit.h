#ifndef H_CIRCUIT
#define H_CIRCUIT
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "voiture.h"
#endif



void ajouterCircuits();
void afficherCircuits(Circuits *, int *);
void trierCircuits(Circuits *, int *);
void echangerCircuits(Circuits *, Circuits *);
void rechercherCircuits(Circuits *, int *);
void modifierCircuits(Circuits *, int *);
