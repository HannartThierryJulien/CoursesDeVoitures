#ifndef H_PILOTE
#define H_PILOTE
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
#endif


#define FICBINAIREPILOTES "Fichiers_binaires\\Pilotes.bin"


typedef struct Date{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct Pilotes{
    char nom[15];
    char prenom[25];
    int nbrPodium;
    Date dateNaissance;
    int age;
}Pilotes;


void ajouterPilotes();
void afficherPilotes(Pilotes *, int *);
void trierPilotes(Pilotes *, int *);
void echangerPilotes(Pilotes *, Pilotes *);
void rechercherPilotes(Pilotes *, int *);
void modifierPilotes(Pilotes *, int *);
