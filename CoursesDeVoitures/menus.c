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
            reAfficherMenuPrincipal();
            break;
        case 2:
            menuVoiture();
            reAfficherMenuPrincipal();
            break;
        case 3:
            menuCircuit();
            reAfficherMenuPrincipal();
            break;
        case 4:
            menuCourse();
            reAfficherMenuPrincipal();
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

    FILE * fichierPilotes = NULL;
    int choixMenuPilote, nbrPilotes, i;
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
                nbrPilotes=ftell(fichierPilotes) / sizeof(Pilotes);

            pilote=malloc(nbrPilotes*(sizeof(Pilotes)));

            fseek(fichierPilotes, 0, SEEK_SET);
                for (i=0; i<nbrPilotes; i++){
                    fread(&pilote[i],sizeof(Pilotes),1,fichierPilotes);
                }
            fclose(fichierPilotes);
        }
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
}



void menuVoiture(){

    FILE * fichierPilotes = NULL;
    FILE * fichierVoitures = NULL;
    int choixMenuVoiture, nbrVoitures, nbrPilotes, i;
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


    if(choixMenuVoiture == 1 || choixMenuVoiture == 5){
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
                nbrPilotes=ftell(fichierPilotes) / sizeof(Pilotes);

            pilote=malloc(nbrPilotes*(sizeof(Pilotes)));

            fseek(fichierPilotes, 0, SEEK_SET);
                for (i=0; i<nbrPilotes; i++){
                    fread(&pilote[i],sizeof(Pilotes),1,fichierPilotes);
                }
            fclose(fichierPilotes);
        }
    }


    if(choixMenuVoiture != 1 && choixMenuVoiture != 6){
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
                nbrVoitures=ftell(fichierVoitures) / sizeof(Voitures);

            voiture=malloc(nbrVoitures*(sizeof(Voitures)));

            fseek(fichierVoitures, 0, SEEK_SET);
                for (i=0; i<nbrVoitures; i++){
                    fread(&voiture[i],sizeof(Voitures),1,fichierVoitures);
                }
            fclose(fichierVoitures);
        }
    }


    switch (choixMenuVoiture){
        case 1:
            ajouterVoitures(pilote, &nbrPilotes);
            break;
        case 2:
            afficherVoitures(voiture, &nbrVoitures);
            break;
        case 3:
            trierVoitures(voiture, &nbrVoitures);
            afficherVoitures(voiture, &nbrVoitures);
            break;
        case 4:
            rechercherVoitures(voiture, &nbrVoitures);
            break;
        case 5:
            modifierVoitures(voiture, &nbrVoitures, pilote, &nbrPilotes);
            break;
        default:
            break;
    }


    free(pilote);
    free(voiture);
}



void menuCircuit(){

    FILE * fichierCircuits = NULL;
    int choixMenuCircuit, nbrCircuits, i;
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
                nbrCircuits=ftell(fichierCircuits) / sizeof(Circuits);

            circuit=malloc(nbrCircuits*(sizeof(Circuits)));

            fseek(fichierCircuits, 0, SEEK_SET);
                for (i=0; i<nbrCircuits; i++){
                    fread(&circuit[i],sizeof(Circuits),1,fichierCircuits);
                }
            fclose(fichierCircuits);
        }
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
}



void menuCourse(){

    FILE * fichierCourses = NULL;
    FILE * fichierVoitures = NULL;
    int choixMenuCourse, nbrCourses, nbrVoitures, i;
    Courses * course = NULL;
    Voitures * voiture= NULL;


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


    if(choixMenuCourse == 1 || choixMenuCourse == 4){
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
                nbrVoitures=ftell(fichierVoitures) / sizeof(Voitures);

            voiture=malloc(nbrVoitures*(sizeof(Voitures)));

            fseek(fichierVoitures, 0, SEEK_SET);
                for (i=0; i<nbrVoitures; i++){
                    fread(&voiture[i],sizeof(Voitures),1,fichierVoitures);
                }
            fclose(fichierVoitures);
        }
    }


    if(choixMenuCourse != 1 && choixMenuCourse != 6){
        fichierCourses = fopen(FICBINAIRECOURSES, "rb") ;
        if (fichierCourses==NULL){
            system("cls");
            printf("%s", strerror(errno));
            printf("\n\n !!! PAS DE FICHIER COURSES DETECTES !!! \n\n");
            printf(" ! Veuillez ajouter des courses avant de continuer ! \n\n\n");
            system("PAUSE");
        }
        else{
            fseek(fichierCourses, 0, SEEK_END);
                nbrCourses=ftell(fichierCourses) / sizeof(Courses);

            course=malloc(nbrCourses*(sizeof(Courses)));

            fseek(fichierCourses, 0, SEEK_SET);
                for (i=0; i<nbrCourses; i++){
                    fread(&course[i],sizeof(Courses),1,fichierCourses);
                }
            fclose(fichierCourses);
        }
    }


    switch (choixMenuCourse){
        case 1:
            ajouterCourses(voiture, &nbrVoitures);
            break;
        case 2:
            afficherCourses(course, &nbrCourses);
            break;
        case 3:
            rechercherCourses(course, &nbrCourses);
            break;
        case 4:
            modifierCourses(course, &nbrCourses, voiture, &nbrVoitures);
            break;
        default:
            break;
    }


    free(course);
}
