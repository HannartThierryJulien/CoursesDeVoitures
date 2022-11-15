#include "course.h"


FILE * fichierCourses = NULL;



void ajouterCourses(Voitures *pt_voiture, int *pt_nbrVoitures){

    system("cls");
    printf("\n\n");

    int nbrCoursesAAjouter, choix, i, j, k, numeroVoiture;
    Courses * course = NULL;

    printf("Combien de courses voulez vous ajouter ? ");
    scanf("%d", &nbrCoursesAAjouter);
    printf("\n");

    if(nbrCoursesAAjouter>0){

        printf("\nAffichez la liste des voitures actuellement enregistrees (1/0) ? ");
        fflush(stdin);
        scanf("%d", &choix);
        if(choix){
           afficherVoitures(pt_voiture, pt_nbrVoitures);
        }
        printf("------------------------------------------------\n");


        course = malloc(nbrCoursesAAjouter*(sizeof(Courses)));

        fichierCourses = fopen(FICBINAIRECOURSES, "ab");
        if (fichierCourses == NULL){
            printf("%s", strerror(errno));
            exit(99);
        }
        else{
            for(i=0; i<nbrCoursesAAjouter; i++){
                printf("\nCourse %d - Completez ces champs :\n", i+1);
                printf("   Nom du circuit ? ");
                fflush(stdin);
                scanf("%s", course[i].nomCircuit);

                do{
                    printf("\nCombien de voitures participeront a la courses (min. 2 - max. 10) ? ");
                    fflush(stdin);
                    scanf("%d", &course[i].nbrVoituresParticipant);
                }while (course[i].nbrVoituresParticipant < 2 || course[i].nbrVoituresParticipant > 10);

                for(j=0; j<course[i].nbrVoituresParticipant; j++){
                    printf("\n   Numero de la voiture : ");
                    fflush(stdin);
                    scanf("%d", &numeroVoiture);
                    for (k=0; k<*pt_nbrVoitures; k++){
                        if(numeroVoiture == pt_voiture[k].numero){
                            course[i].voitureParticipant[j]=pt_voiture[k];
                        }
                    }

                }
                printf("   Date ? ");
                    printf("\n      Jour : ");
                    fflush(stdin);
                    scanf("%d", &course[i].dateCourse.jour);
                    printf("      Mois : ");
                    fflush(stdin);
                    scanf(" %d", &course[i].dateCourse.mois);
                    printf("      Annee : ");
                    fflush(stdin);
                    scanf(" %d", &course[i].dateCourse.annee);

                fwrite (&course[i], 1, sizeof(Courses), fichierCourses );
            }
        }
        fclose(fichierCourses) ;
    }
    free(course);
}



void afficherCourses(Courses *pt_course, int *pt_nbrCourses){

    system("cls");
    printf("\n\n");

    int i, j, k;

    printf("Nombre de courses : %d\n\n", *pt_nbrCourses);

    for (i=0; i<*pt_nbrCourses; i++){
        printf("\nNom : %s \n", pt_course[i].nomCircuit);

        printf("\nVoitures participant :");
        for (j=0; j<pt_course[i].nbrVoituresParticipant; j++){
            printf("\n   Numero : %d\n", pt_course[i].voitureParticipant[j].numero);
            printf("   Marque : %s\n", pt_course[i].voitureParticipant[j].marque);
            printf("   Puissance : %d\n", pt_course[i].voitureParticipant[j].puissance);
            for (k=0; k<2; k++){
                printf("   Pilote %d : %s %s\n", k+1, pt_course[i].voitureParticipant[j].pilote[k].nom, pt_course[i].voitureParticipant[j].pilote[k].prenom);
            }
        }

        printf("\nDate : %d/%d/%d\n\n\n", pt_course[i].dateCourse.jour, pt_course[i].dateCourse.mois, pt_course[i].dateCourse.annee);
    }
}



void rechercherCourses(Courses *pt_course, int *pt_nbrCourses){

    system("cls");
    printf("\n\n");

    int choix, i, j, k, resultatRecherche=0, jour, mois, annee;

    printf("\nEntrez la date de la course que vous rechercher : ");
    printf("\n  Jour : ");
    fflush(stdin);
    scanf("%d", &jour);
    printf("  Mois : ");
    fflush(stdin);
    scanf("%d", &mois);
    printf("  Annee : ");
    fflush(stdin);
    scanf("%d", &annee);

    for (i=0; i<*pt_nbrCourses; i++){
        if(jour==pt_course[i].dateCourse.jour && mois==pt_course[i].dateCourse.mois && annee==pt_course[i].dateCourse.annee){

            do{
                printf("\n\nVoulez vous afficher la liste des bolides en fonction de leur puissance dans");
                printf("\n   1 : l ordre croissant");
                printf("\n   2 : l ordre decroissant");
                printf("\nVotre choix : ");
                fflush(stdin);
                scanf("%d", &choix);
            }while(choix < 1 || choix > 2);

            switch (choix){
                case 1:
                    for(j=0;j<pt_course[i].nbrVoituresParticipant-1;j++){
                        for(k=j+1;k<pt_course[i].nbrVoituresParticipant;k++){
                            if(pt_course[i].voitureParticipant[j].puissance > pt_course[i].voitureParticipant[k].puissance){
                                echangerVoitures(&pt_course[i].voitureParticipant[j], &pt_course[i].voitureParticipant[k]);
                            }
                        }
                    }
                    break;

                case 2:
                    for(j=0;j<pt_course[i].nbrVoituresParticipant-1;j++){
                        for(k=j+1;k<pt_course[i].nbrVoituresParticipant;k++){
                            if(pt_course[i].voitureParticipant[j].puissance < pt_course[i].voitureParticipant[k].puissance){
                                echangerVoitures(&pt_course[i].voitureParticipant[j], &pt_course[i].voitureParticipant[k]);
                            }
                        }
                    }
                    break;

                default:
                    break;
            }
        ++resultatRecherche;
        }
    }

    if(resultatRecherche!=0){
        afficherCourses(pt_course, pt_nbrCourses);
    }
    else{
        printf("\nAucune course correspondante n a ete trouvee.\n");
    }
}



void modifierCourses(Courses *pt_course, int *pt_nbrCourses, Voitures *pt_voiture, int *pt_nbrVoitures){

    system("cls");
    printf("\n\n");


    int choix, i, j, k, resultatRecherche=0, jour, mois, annee, numeroVoiture;


    printf("\nVoulez-vous un rappel des courses actuellement enregistrees (1/0) ? ");
    fflush(stdin);
    scanf("%d", &choix);
    if(choix){
        afficherCourses(pt_course, pt_nbrCourses);
    }
    printf("------------------------------------------------\n");


    printf("\nEntrez la date de la course que vous voulez modifier : ");
    printf("\n  Jour : ");
    fflush(stdin);
    scanf("%d", &jour);
    printf("  Mois : ");
    fflush(stdin);
    scanf("%d", &mois);
    printf("  Annee : ");
    fflush(stdin);
    scanf("%d", &annee);


    for (i=0; i<*pt_nbrCourses; i++){
        if(jour == pt_course[i].dateCourse.jour && mois == pt_course[i].dateCourse.mois && annee == pt_course[i].dateCourse.annee){
            printf("\nEntrez les nouvelles donnees de la course du %d/%d/%d :", jour, mois, annee);
            printf("\n   Nom du circuit ? ");
            fflush(stdin);
            scanf("%s", pt_course[i].nomCircuit);

            do{
                printf("\nCombien de voitures participeront a la courses (min. 2 - max. 10) ? ");
                fflush(stdin);
                scanf("%d", &pt_course[i].nbrVoituresParticipant);
            }while (pt_course[i].nbrVoituresParticipant < 2 || pt_course[i].nbrVoituresParticipant > 10);

            for(j=0; j<pt_course[i].nbrVoituresParticipant; j++){
                printf("\n   Numero de la voiture : ");
                fflush(stdin);
                scanf("%d", &numeroVoiture);
                for (k=0; k<*pt_nbrVoitures; k++){
                    if(numeroVoiture == pt_voiture[k].numero){
                        pt_course[i].voitureParticipant[j]=pt_voiture[k];
                    }
                }

            }

            printf("   Date ? ");
                printf("\n      Jour : ");
                fflush(stdin);
                scanf("%d", &pt_course[i].dateCourse.jour);
                printf("      Mois : ");
                fflush(stdin);
                scanf(" %d", &pt_course[i].dateCourse.mois);
                printf("      Annee : ");
                fflush(stdin);
                scanf(" %d", &pt_course[i].dateCourse.annee);

            ++resultatRecherche;
        }
    }
    if(resultatRecherche==0){printf("\nAucune course correspondante n a ete trouvee.\n");}


    if(resultatRecherche==1){
        fichierCourses = fopen(FICBINAIRECOURSES, "wb");
        if (fichierCourses == NULL){
            printf("%s", strerror(errno));
            exit(99);
        }
        else{
            for(i=0; i<*pt_nbrCourses; i++){
                fwrite (&pt_course[i], 1, sizeof(Courses), fichierCourses );
            }
        }
        fclose(fichierCourses) ;
    }
}
