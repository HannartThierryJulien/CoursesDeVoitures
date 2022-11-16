#ifndef H_VOITURE
#define H_VOITURE
    #include <stdio.h>
    //#include <stdlib.h>
    //#include <string.h>
    #include "pilote.h"
#endif



void ajouterVoitures(Pilotes *, int *);
void afficherVoitures(Voitures *, int *, Pilotes *, int *);
void trierVoitures(Voitures *, int *);
void echangerVoitures(Voitures *, Voitures *);
void rechercherVoitures(Voitures *, int *, Pilotes *, int *);
void modifierVoitures(Voitures *, int *, Pilotes *, int *);
