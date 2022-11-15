#ifndef H_COURSE
#define H_COURSE
    #include <stdio.h>
    //#include <stdlib.h>
    //#include <string.h>
    #include "voiture.h"
#endif


#define FICBINAIRECOURSES "Fichiers_binaires\\Courses.bin"


typedef struct Courses{
    char nomCircuit[25];
    Date dateCourse;
    int nbrVoituresParticipant;
    Voitures voitureParticipant[10];
}Courses;


void ajouterCourses(Voitures *, int *);
void afficherCourses(Courses *, int *);
void rechercherCourses(Courses *, int *);
void modifierCourses(Courses *, int *, Voitures *, int *);
