#include "menus.h"



void menuPrincipal(){
    int choixMenuPrincipal;

    do{
        system("cls");
        printf("\n");

        printf("\n------------------------------------------------------------");
        printf("\n-----------------------MENU PRINCIPAL-----------------------");
        printf("\n------------------------------------------------------------");
            printf("\n\n   1 : Pilotes\n");
            printf("   2 : Voitures\n");
            printf("   3 : Circuits\n");
            printf("   4 : Courses\n");
            printf("\n   5 : Quitter le programme\n");

        printf("\n------------------------------------------------------------\n");
        printf("Votre choix : ");
        fflush(stdin);
        scanf("%d", &choixMenuPrincipal);
    }while (choixMenuPrincipal < 1 || choixMenuPrincipal > 5);

    switch (choixMenuPrincipal){
        case 1:
            menuPilote();
            break;
        case 2:
            menuVoiture();
            break;
        case 3:
            menuCircuit();
            break;
        case 4:
            menuCourse();
            break;
        default:
            break;
    }
}



void reAfficherMenuPrincipal(){
    int choix;
    printf("\n\n------------------------------------------------");
    do{
        printf("\nVoulez-vous afficher le menu a nouveau ? (1/0) ");
        fflush(stdin);
        scanf("%d", &choix);
    }while(choix < 0 || choix > 1);

    if(choix){
        menuPrincipal();
    }
}



void menuPilote(){

    int choixMenuPilote, nbrPilotes;
    Pilotes * pilote = NULL;


    do{
        system("cls");
        printf("\n");

        printf("\n------------------------------------------------------------");
        printf("\n-------------------------MENU PILOTE------------------------");
        printf("\n------------------------------------------------------------");
            printf("\n\n   1 : Ajouter\n");
            printf("   2 : Afficher\n");
            printf("   3 : Trier\n");
            printf("   4 : Rechercher\n");
            printf("   5 : Modifier\n");
            printf("\n   6 : Quitter le programme\n");

        printf("\n------------------------------------------------------------\n");
        printf("Votre choix : ");
        fflush(stdin);
        scanf("%d", &choixMenuPilote);
    }while (choixMenuPilote < 1 || choixMenuPilote > 6);


    if(choixMenuPilote != 1 && choixMenuPilote != 6){
        pilote=lectureFichierPilotes(&nbrPilotes);
    }


    switch (choixMenuPilote){
        case 1:
            ajouterPilotes();
            break;
        case 2:
            afficherPilotes(pilote, &nbrPilotes);
            break;
        case 3:
            trierPilotes(pilote, &nbrPilotes);
            afficherPilotes(pilote, &nbrPilotes);
            break;
        case 4:
            rechercherPilotes(pilote, &nbrPilotes);
            break;
        case 5:
            modifierPilotes(pilote, &nbrPilotes);
            break;
        default:
            break;
    }


    free(pilote);
    if(choixMenuPilote!=6) reAfficherMenuPrincipal();
}



void menuVoiture(){

    int choixMenuVoiture, nbrVoitures, nbrPilotes;
    Voitures * voiture= NULL;
    Pilotes * pilote = NULL;


    do{
        system("cls");
        printf("\n");

        printf("\n------------------------------------------------------------");
        printf("\n-------------------------MENU VOITURE-----------------------");
        printf("\n------------------------------------------------------------");
            printf("\n\n   1 : Ajouter\n");
            printf("   2 : Afficher\n");
            printf("   3 : Trier\n");
            printf("   4 : Rechercher\n");
            printf("   5 : Modifier\n");
            printf("\n   6 : Quitter le programme\n");

        printf("\n------------------------------------------------------------\n");
        printf("Votre choix : ");
        fflush(stdin);
        scanf("%d", &choixMenuVoiture);
    }while (choixMenuVoiture < 1 || choixMenuVoiture > 6);


    if(choixMenuVoiture != 3){
        pilote=lectureFichierPilotes(&nbrPilotes);
    }


    if(choixMenuVoiture != 1 && choixMenuVoiture != 6){
        voiture=lectureFichierVoitures(&nbrVoitures);
    }


    switch (choixMenuVoiture){
        case 1:
            ajouterVoitures(pilote, &nbrPilotes);
            break;
        case 2:
            afficherVoitures(voiture, &nbrVoitures, pilote, &nbrPilotes);
            break;
        case 3:
            trierVoitures(voiture, &nbrVoitures);
            afficherVoitures(voiture, &nbrVoitures, pilote, &nbrPilotes);
            break;
        case 4:
            rechercherVoitures(voiture, &nbrVoitures, pilote, &nbrPilotes);
            break;
        case 5:
            modifierVoitures(voiture, &nbrVoitures, pilote, &nbrPilotes);
            break;
        default:
            break;
    }


    free(pilote);
    free(voiture);
    if(choixMenuVoiture!=6) reAfficherMenuPrincipal();
}



void menuCircuit(){

    int choixMenuCircuit, nbrCircuits;
    Circuits * circuit = NULL;


    do{
        system("cls");
        printf("\n");

        printf("\n------------------------------------------------------------");
        printf("\n-------------------------MENU CIRCUIT-----------------------");
        printf("\n------------------------------------------------------------");
            printf("\n\n   1 : Ajouter\n");
            printf("   2 : Afficher\n");
            printf("   3 : Trier\n");
            printf("   4 : Rechercher\n");
            printf("   5 : Modifier\n");
            printf("\n   6 : Quitter le programme\n");

        printf("\n------------------------------------------------------------\n");
        printf("Votre choix : ");
        fflush(stdin);
        scanf("%d", &choixMenuCircuit);
    }while (choixMenuCircuit < 1 || choixMenuCircuit > 6);


    if(choixMenuCircuit != 1 && choixMenuCircuit != 6){
        circuit=lectureFichierCircuits(&nbrCircuits);
    }


    switch (choixMenuCircuit){
        case 1:
            ajouterCircuits();
            break;
        case 2:
            afficherCircuits(circuit, &nbrCircuits);
            break;
        case 3:
            trierCircuits(circuit, &nbrCircuits);
            afficherCircuits(circuit, &nbrCircuits);
            break;
        case 4:
            rechercherCircuits(circuit, &nbrCircuits);
            break;
        case 5:
            modifierCircuits(circuit, &nbrCircuits);
            break;
        default:
            break;
    }


    free(circuit);
    if(choixMenuCircuit!=6) reAfficherMenuPrincipal();
}



void menuCourse(){

    int choixMenuCourse, nbrCourses, nbrVoitures, nbrPilotes;
    Courses * course = NULL;
    Voitures * voiture= NULL;
    Pilotes * pilote = NULL;


    do{
        system("cls");
        printf("\n");

        printf("\n------------------------------------------------------------");
        printf("\n-------------------------MENU COURSE------------------------");
        printf("\n------------------------------------------------------------");
            printf("\n\n   1 : Ajouter\n");
            printf("   2 : Afficher\n");
            printf("   3 : Rechercher\n");
            printf("   4 : Modifier\n");
            printf("\n   5 : Quitter le programme\n");

        printf("\n------------------------------------------------------------\n");
        printf("Votre choix : ");
        fflush(stdin);
        scanf("%d", &choixMenuCourse);
    }while (choixMenuCourse < 1 || choixMenuCourse > 5);


    pilote=lectureFichierPilotes(&nbrPilotes);


    if(choixMenuCourse == 1 || choixMenuCourse == 4){
        voiture=lectureFichierVoitures(&nbrVoitures);
    }


    if(choixMenuCourse != 1 && choixMenuCourse != 6){
        course=lectureFichierCourses(&nbrCourses);
    }


    switch (choixMenuCourse){
        case 1:
            ajouterCourses(voiture, &nbrVoitures, pilote, &nbrPilotes);
            break;
        case 2:
            afficherCourses(course, &nbrCourses, pilote, &nbrPilotes);
            break;
        case 3:
            rechercherCourses(course, &nbrCourses, pilote, &nbrPilotes);
            break;
        case 4:
            modifierCourses(course, &nbrCourses, voiture, &nbrVoitures, pilote, &nbrPilotes);
            break;
        default:
            break;
    }


    free(course);
    if(choixMenuCourse!=6) reAfficherMenuPrincipal();
}
