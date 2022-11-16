#include "fichier.h"


FILE * fichierPilotes = NULL;
FILE * fichierVoitures = NULL;
FILE * fichierCircuits = NULL;
FILE * fichierCourses = NULL;


Pilotes * lectureFichierPilotes(int *pt_nbrPilotes){

    int i;
    Pilotes * pilote=NULL;

    fichierPilotes = fopen(FICBINAIREPILOTES, "rb") ;
    if (fichierPilotes==NULL){
        system("cls");
        printf("%s", strerror(errno));
        printf("\n\n !!! PAS DE FICHIER PILOTES DETECTES !!! \n\n");
        printf(" ! Veuillez ajouter des pilotes avant de continuer ! \n\n\n");
        system("PAUSE");
    }
    else{
        fseek(fichierPilotes, 0, SEEK_END);
            *pt_nbrPilotes=ftell(fichierPilotes) / sizeof(Pilotes);

        pilote=malloc((*pt_nbrPilotes)*(sizeof(Pilotes)));

        fseek(fichierPilotes, 0, SEEK_SET);
            for (i=0; i<*pt_nbrPilotes; i++){
                fread(&pilote[i],sizeof(Pilotes),1,fichierPilotes);
            }
        fclose(fichierPilotes);
    }
    return pilote;
}



Voitures * lectureFichierVoitures(int *pt_nbrVoitures){

    int i;
    Voitures * voiture=NULL;

    fichierVoitures = fopen(FICBINAIREVOITURES, "rb") ;
    if (fichierVoitures==NULL){
        system("cls");
        printf("%s", strerror(errno));
        printf("\n\n !!! PAS DE FICHIER VOITURES DETECTES !!! \n\n");
        printf(" ! Veuillez ajouter des voitures avant de continuer ! \n\n\n");
        system("PAUSE");
    }
    else{
        fseek(fichierVoitures, 0, SEEK_END);
        *pt_nbrVoitures=ftell(fichierVoitures) / sizeof(Voitures);

        voiture=malloc((*pt_nbrVoitures)*(sizeof(Voitures)));

        fseek(fichierVoitures, 0, SEEK_SET);
        for (i=0; i<*pt_nbrVoitures; i++){
            fread(&voiture[i],sizeof(Voitures),1,fichierVoitures);
        }
        fclose(fichierVoitures);
    }
    return voiture;
}



Circuits * lectureFichierCircuits(int *pt_nbrCircuits){

    int i;
    Circuits * circuit=NULL;

    fichierCircuits = fopen(FICBINAIRECIRCUITS, "rb") ;
    if (fichierCircuits==NULL){
        system("cls");
        printf("%s", strerror(errno));
        printf("\n\n !!! PAS DE FICHIER CIRCUITS DETECTES !!! \n\n");
        printf(" ! Veuillez ajouter des circuits avant de continuer ! \n\n\n");
        system("PAUSE");
    }
    else{
        fseek(fichierCircuits, 0, SEEK_END);
        *pt_nbrCircuits=ftell(fichierCircuits) / sizeof(Circuits);

        circuit=malloc((*pt_nbrCircuits)*(sizeof(Circuits)));

        fseek(fichierCircuits, 0, SEEK_SET);
        for (i=0; i<*pt_nbrCircuits; i++){
            fread(&circuit[i],sizeof(Circuits),1,fichierCircuits);
        }
        fclose(fichierCircuits);
    }
    return circuit;
}



Courses * lectureFichierCourses(int *pt_nbrCourses){

    int i;
    Courses * course=NULL;

    fichierCourses = fopen(FICBINAIRECOURSES, "rb") ;
    if (fichierCourses==NULL){
        system("cls");
        printf("%s", strerror(errno));
        printf("\n\n !!! PAS DE FICHIER CIRCUITS DETECTES !!! \n\n");
        printf(" ! Veuillez ajouter des circuits avant de continuer ! \n\n\n");
        system("PAUSE");
    }
    else{
        fseek(fichierCourses, 0, SEEK_END);
        *pt_nbrCourses=ftell(fichierCourses) / sizeof(Courses);

        course=malloc((*pt_nbrCourses)*(sizeof(Courses)));

        fseek(fichierCourses, 0, SEEK_SET);
        for (i=0; i<*pt_nbrCourses; i++){
            fread(&course[i],sizeof(Courses),1,fichierCourses);
        }
        fclose(fichierCourses);
    }
    return course;
}
