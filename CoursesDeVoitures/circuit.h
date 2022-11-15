#ifndef H_CIRCUIT
#define H_CIRCUIT
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
#endif


#define FICBINAIRECIRCUITS "Fichiers_binaires\\Circuits.bin"


typedef struct Circuits{
    char nom[25];
    char pays[20];
    float longueur; //exprimee en Km avec une precision au metre pres
}Circuits;


void ajouterCircuits();
void afficherCircuits(Circuits *, int *);
void trierCircuits(Circuits *, int *);
void echangerCircuits(Circuits *, Circuits *);
void rechercherCircuits(Circuits *, int *);
void modifierCircuits(Circuits *, int *);
