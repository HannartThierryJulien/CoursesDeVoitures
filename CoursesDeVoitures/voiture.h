#ifndef H_VOITURE
#define H_VOITURE
    #include <stdio.h>
    //#include <stdlib.h>
    //#include <string.h>
    #include "pilote.h"
#endif


#define FICBINAIREVOITURES "Fichiers_binaires\\Voitures.bin"


typedef struct Voitures{
    int numero;
    char marque[15];
    int puissance; //exprimee en CV
    Pilotes pilote[2];
}Voitures;


void ajouterVoitures(Pilotes *, int *);
void afficherVoitures(Voitures *, int *);
void trierVoitures(Voitures *, int *);
void echangerVoitures(Voitures *, Voitures *);
void rechercherVoitures(Voitures *, int *);
void modifierVoitures(Voitures *, int *, Pilotes *, int *);
