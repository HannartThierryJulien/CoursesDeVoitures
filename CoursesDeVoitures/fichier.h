#ifndef H_FICHIER
#define H_FICHIER
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
#endif


#define FICBINAIREPILOTES "Fichiers_binaires\\Pilotes.bin"
#define FICBINAIREVOITURES "Fichiers_binaires\\Voitures.bin"
#define FICBINAIRECIRCUITS "Fichiers_binaires\\Circuits.bin"
#define FICBINAIRECOURSES "Fichiers_binaires\\Courses.bin"


typedef struct Date{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct Pilotes{
    char nom[15];
    char prenom[25];
    int nbrPodium;
    long int nbrDateNaissance;
    long int nn; //numero national (fait maison)
}Pilotes;

typedef struct Voitures{
    int numero;
    char marque[15];
    int puissance; //exprimee en CV
    long int pilote[2];
}Voitures;

typedef struct Circuits{
    char nom[25];
    char pays[20];
    float longueur; //exprimee en Km avec une precision au metre pres
}Circuits;

typedef struct Courses{
    char nomCircuit[25];
    Date dateCourse;
    int nbrVoituresParticipant;
    Voitures voitureParticipant[10];
}Courses;


Pilotes * lectureFichierPilotes(int *);
Voitures * lectureFichierVoitures(int *);
Circuits * lectureFichierCircuits(int *);
Courses * lectureFichierCourses(int *);
