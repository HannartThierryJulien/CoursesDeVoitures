#include "voiture.h"


FILE * fichierVoitures = NULL;



void ajouterVoitures(Pilotes *pt_pilote, int *pt_nbrPilotes){
    system("cls");
    printf("\n\n");

    int nbrVoituresAAjouter, i, j, k, choix;
    char nomPilote[15], prenomPilote[25];
    Voitures * voiture = NULL;

    printf("Combien de voitures voulez vous ajouter ? ");
    scanf("%d", &nbrVoituresAAjouter);
    printf("\n");

    if(nbrVoituresAAjouter>0){

        voiture = malloc(nbrVoituresAAjouter*(sizeof(Voitures)));

        fichierVoitures = fopen(FICBINAIREVOITURES, "ab");
        if (fichierVoitures == NULL){
            printf("%s", strerror(errno));
            exit(99);
        }
        else{
            printf("\n------------------------------------------------");
                printf("\nAfficher la liste des pilotes actuellement enregistres (1/0) ? ");
                fflush(stdin);
                scanf("%d", &choix);
                if(choix){
                    for (j=0; j<*pt_nbrPilotes; j++){
                        printf("   %s %s - %d podium(s)\n", pt_pilote[j].nom, pt_pilote[j].prenom, pt_pilote[j].nbrPodium);
                    }
                }
            printf("\n------------------------------------------------");

            for(i=0; i<nbrVoituresAAjouter; i++){
                printf("\nVoitures %d - Completez ces champs :\n", i+1);
                printf("   Numero (unique) ? ");
                fflush(stdin);
                scanf("%d", &voiture[i].numero);
                printf("   Marque ? ");
                fflush(stdin);
                scanf("%s", voiture[i].marque);
                printf("   Puissance (en CV) ? ");
                fflush(stdin);
                scanf("%d", &voiture[i].puissance);

                for (j=0; j<2; j++){
                    printf("   Nom du pilote %d ? ", j+1);
                    fflush(stdin);
                    scanf("%s", nomPilote);
                    printf("   Prenom du pilote %d ? ", j+1);
                    fflush(stdin);
                    scanf("%s", prenomPilote);
                    for (k=0; k<*pt_nbrPilotes; k++){
                        if(strcmp(nomPilote, pt_pilote[k].nom) == 0 && strcmp(prenomPilote, pt_pilote[k].prenom) == 0){
                            voiture[i].pilote[j]=pt_pilote[k];
                        }
                    }
                }

                fwrite(&voiture[i], 1, sizeof(Voitures), fichierVoitures);
            }
        }
        fclose(fichierVoitures);
    }
    free(voiture);
}



void afficherVoitures(Voitures *pt_voiture, int *pt_nbrVoitures){

    system("cls");
    printf("\n\n");

    int i, j;

    printf("Nombre de voitures : %d\n\n", *pt_nbrVoitures);

    for (i=0; i<*pt_nbrVoitures; i++){
        printf("\nNumero : %d \n", pt_voiture[i].numero);
        printf("Marque : %s \n", pt_voiture[i].marque);
        printf("Puissance : %d \n", pt_voiture[i].puissance);
        for (j=0; j<2; j++){
            printf("Pilote %d : %s %s\n", j+1, pt_voiture[i].pilote[j].nom, pt_voiture[i].pilote[j].prenom);
        }
    }
}



void trierVoitures(Voitures *pt_voiture, int *pt_nbrVoitures){

    system("cls");
    printf("\n\n");

    int i, j, choix;

    do{
        printf("Trier les voitures par\n");
        printf("   1 : leur puissance croissante\n");
        printf("   2 : leur puissance décroissante\n");
        printf("   3 : l'ordre alphabetique des marques\n");
        printf("\nVotre choix : ");
        fflush(stdin);
        scanf("%d", &choix);
    }while(choix < 1 || choix > 3);

    switch (choix){
        case 1:
            for(i=0;i<*pt_nbrVoitures-1;i++){
                for(j=i+1;j<*pt_nbrVoitures;j++){
                    if( pt_voiture[i].puissance > pt_voiture[j].puissance){
                        echangerVoitures(&pt_voiture[i], &pt_voiture[j]);
                    }
                }
            }
            break;
        case 2:
            for(i=0;i<*pt_nbrVoitures-1;i++){
                for(j=i+1;j<*pt_nbrVoitures;j++){
                    if( pt_voiture[i].puissance < pt_voiture[j].puissance){
                        echangerVoitures(&pt_voiture[i], &pt_voiture[j]);
                    }
                }
            }
            break;
        case 3:
            for(i=0;i<*pt_nbrVoitures-1;i++){
                for(j=i+1;j<*pt_nbrVoitures;j++){
                    if(strcmp(pt_voiture[i].marque, pt_voiture[i].marque) > 0){
                        echangerVoitures(&pt_voiture[i], &pt_voiture[j]);
                    }
                }
            }
            break;
        default:
            break;
    }



    printf("\n\nVoitures triees :\n\n");
}



void echangerVoitures(Voitures *voiture1, Voitures *voiture2){
    Voitures temp_voiture = *voiture1;
    *voiture1 = *voiture2;
    *voiture2 = temp_voiture;
}



void rechercherVoitures(Voitures *pt_voiture, int *pt_nbrVoitures){

    system("cls");
    printf("\n\n");

    int choix, i, j, resultatRecherche=0;
    char nomOuPrenom[25], marque[15];
    Voitures * temp_voiture = NULL;

    do{
        printf("Voulez vous rechercher une voiture par");
        printf("\n   1 : le nom ou le prenom d'un des pilotes");
        printf("\n   2 : la marque");
        printf("\n\nVotre choix : ");
        fflush(stdin);
        scanf("%d", &choix);
    }while(choix < 1 || choix > 2);

    switch (choix){
        case 1:
            printf("\n\nEntrez un nom ou un prenom: ");
            fflush(stdin);
            scanf("%s", nomOuPrenom);

            for (i=0; i<*pt_nbrVoitures; i++){
                for (j=0; j<2; j++){
                    if(strcmp(nomOuPrenom, pt_voiture[i].pilote[j].nom) == 0 || strcmp(nomOuPrenom, pt_voiture[i].pilote[j].prenom) == 0){
                        ++resultatRecherche;
                    }
                }
            }

            temp_voiture=malloc(resultatRecherche*(sizeof(Voitures)));
            resultatRecherche=0;

            for (i=0; i<*pt_nbrVoitures; i++){
                for (j=0; j<2; j++){
                    if(strcmp(nomOuPrenom, pt_voiture[i].pilote[j].nom) == 0 || strcmp(nomOuPrenom, pt_voiture[i].pilote[j].prenom) == 0){
                        ++resultatRecherche;
                        temp_voiture[resultatRecherche-1]=pt_voiture[i];
                    }
                }
            }
            break;

        case 2:
            printf("\n\nEntrez une marque : ");
            fflush(stdin);
            scanf("%s", marque);

            for (i=0; i<*pt_nbrVoitures; i++){
                if(strcmp(marque, pt_voiture[i].marque) == 0){
                    ++resultatRecherche;
                }
            }

            temp_voiture=malloc(resultatRecherche*(sizeof(Voitures)));
            resultatRecherche=0;

            for (i=0; i<*pt_nbrVoitures; i++){
                if(strcmp(marque, pt_voiture[i].marque) == 0){
                    ++resultatRecherche;
                    temp_voiture[resultatRecherche-1]=pt_voiture[i];
                }
            }
        default:
            break;
    }

    if(resultatRecherche!=0){
        afficherVoitures(temp_voiture, &resultatRecherche);
    }
    else{
        printf("\nAucune voiture correspondante n a ete trouvee.\n");
    }

    free (temp_voiture);
}



void modifierVoitures(Voitures *pt_voiture, int *pt_nbrVoitures, Pilotes *pt_pilote, int *pt_nbrPilotes){

    system("cls");
    printf("\n\n");


    int choix, i, j, k, resultatRecherche=0, numeroVoiture;
    char nomPilote[15], prenomPilote[25];


    printf("\nVoulez-vous un rappel des voitures actuellement enregistrees (1/0) ? ");
    fflush(stdin);
    scanf("%d", &choix);
    if(choix){
        afficherVoitures(pt_voiture, pt_nbrVoitures);
    }
    printf("------------------------------------------------\n");


    printf("\n\nEntrez le numero de la voiture que vous voulez modifier : ");
    fflush(stdin);
    scanf("%d", &numeroVoiture);


    for (i=0; i<*pt_nbrVoitures; i++){
        if(numeroVoiture == pt_voiture[i].numero){
            printf("\nEntrez les nouvelles donnees de la voiture %d :", numeroVoiture);
            printf("\n   Numero (unique) ? ");
                fflush(stdin);
                scanf("%d", &pt_voiture[i].numero);
                printf("   Marque ? ");
                fflush(stdin);
                scanf("%s", pt_voiture[i].marque);
                printf("   Puissance (en CV) ? ");
                fflush(stdin);
                scanf("%d", &pt_voiture[i].puissance);

                for (j=0; j<2; j++){
                    printf("   Nom du pilote %d ? ", j+1);
                    fflush(stdin);
                    scanf("%s", nomPilote);
                    printf("   Prenom du pilote %d ? ", j+1);
                    fflush(stdin);
                    scanf("%s", prenomPilote);
                    for (k=0; k<*pt_nbrPilotes; k++){
                        if(strcmp(nomPilote, pt_pilote[k].nom) == 0 && strcmp(prenomPilote, pt_pilote[k].prenom) == 0){
                            pt_voiture[i].pilote[j]=pt_pilote[k];
                        }
                    }
                }

            ++resultatRecherche;
        }
    }
    if(resultatRecherche==0){printf("\nAucune voiture correspondante n a ete trouvee.\n");}


    if(resultatRecherche==1){
        fichierVoitures = fopen(FICBINAIREVOITURES, "wb");
        if (fichierVoitures == NULL){
            printf("%s", strerror(errno));
            exit(99);
        }
        else{
            for(i=0; i<*pt_nbrVoitures; i++){
                fwrite (&pt_voiture[i], 1, sizeof(Voitures), fichierVoitures );
            }
        }
        fclose(fichierVoitures) ;
    }
}
