#include "pilote.h"


FILE * fichierPilotes;



void ajouterPilotes(){
   system("cls");
    printf("\n\n");

    int nbrPilotesAAjouter, i, jour, mois, annee;
    Pilotes * pilote = NULL;

    printf("Combien de pilotes voulez vous ajouter ? ");
    scanf("%d", &nbrPilotesAAjouter);
    printf("\n");

    if(nbrPilotesAAjouter>0){

        pilote = malloc(nbrPilotesAAjouter*(sizeof(Pilotes)));

        fichierPilotes = fopen(FICBINAIREPILOTES, "ab");
        if (fichierPilotes == NULL){
            printf("%s", strerror(errno));
            exit(99);
        }
        else{
            for(i=0; i<nbrPilotesAAjouter; i++){
                printf("\nPilote %d - Completez ces champs :\n", i+1);
                printf("   Nom ? ");
                fflush(stdin);
                scanf("%s", pilote[i].nom);
                printf("   Prenom ? ");
                fflush(stdin);
                scanf("%s", pilote[i].prenom);
                printf("   Nombre de podium obtenu(s) (3 premiers) ? ");
                fflush(stdin);
                scanf("%d", &pilote[i].nbrPodium);
                printf("   Date de naissance ? ");
                    printf("\n      Jour : ");
                    fflush(stdin);
                    scanf("%d", &jour);
                    printf("      Mois : ");
                    fflush(stdin);
                    scanf(" %d", &mois);
                    printf("      Annee : ");
                    fflush(stdin);
                    scanf(" %d", &annee);
                pilote[i].nbrDateNaissance=calculNbrDate(jour, mois, annee);

                pilote[i].nn=calculerNumeroNationalFaitMaison(pilote[i].nom, pilote[i].prenom, pilote[i].nbrDateNaissance);

                fwrite (&pilote[i], 1, sizeof(Pilotes), fichierPilotes );
            }
        }
        fclose(fichierPilotes) ;
    }
    free(pilote);
}



void afficherPilotes(Pilotes *pt_pilote, int *pt_nbrPilotes){
    system("cls");
    printf("\n\n");

    int tabDateNaissance[3];
    int i;

    printf("Nombre de pilotes : %d\n\n", *pt_nbrPilotes);

    for (i=0; i<*pt_nbrPilotes; i++){
        printf("%s %s\n", pt_pilote[i].nom, pt_pilote[i].prenom);
        printf("%d podium(s)\n", pt_pilote[i].nbrPodium);
        DateEntiere(tabDateNaissance, pt_pilote[i].nbrDateNaissance);
        printf("Ne le : %d/%d/%d\n\n", tabDateNaissance[0], tabDateNaissance[1], tabDateNaissance[2]);
        //printf("nn home made : %li \n", pt_pilote[i].nn);
    }
}



void trierPilotes(Pilotes *pt_pilote, int *pt_nbrPilotes){

    system("cls");
    printf("\n\n");

    int i, j, choix;

    do{
        printf("Trier les pilotes par\n");
        printf("   1 : leur age\n");
        printf("   2 : leur nombre de podium de facon croissante\n");
        printf("   3 : leur nombre de podium de facon decroissante\n");
        printf("   4 : l ordre alphabetique de leur nom");
        printf("\nVotre choix : ");
        fflush(stdin);
        scanf("%d", &choix);
    }while(choix < 1 || choix > 4);

    switch (choix){
        case 1:
            for(i=0;i<*pt_nbrPilotes-1;i++){
                for(j=i+1;j<*pt_nbrPilotes;j++){
                    if( pt_pilote[i].nbrDateNaissance < pt_pilote[j].nbrDateNaissance){
                        echangerPilotes(&pt_pilote[i], &pt_pilote[j]);
                    }
                }
            }

            break;
        case 2:
            for(i=0;i<*pt_nbrPilotes-1;i++){
                for(j=i+1;j<*pt_nbrPilotes;j++){
                    if( pt_pilote[i].nbrPodium > pt_pilote[j].nbrPodium){
                        echangerPilotes(&pt_pilote[i], &pt_pilote[j]);
                    }
                }
            }
            break;
        case 3:
            for(i=0;i<*pt_nbrPilotes-1;i++){
                for(j=i+1;j<*pt_nbrPilotes;j++){
                    if( pt_pilote[i].nbrPodium < pt_pilote[j].nbrPodium){
                        echangerPilotes(&pt_pilote[i], &pt_pilote[j]);
                    }
                }
            }
            break;
        case 4:
            for(i=0;i<*pt_nbrPilotes-1;i++){
                for(j=i+1;j<*pt_nbrPilotes;j++){
                    if(strcmp(pt_pilote[i].nom, pt_pilote[j].nom) > 0){
                        echangerPilotes(&pt_pilote[i], &pt_pilote[j]);
                    }
                }
            }
            break;
        default:
            break;
    }

    printf("\n\nPilotes tries :\n\n");
}



void echangerPilotes(Pilotes *pilote1, Pilotes *pilote2){
    Pilotes temp_pilote = *pilote1;
    *pilote1 = *pilote2;
    *pilote2 = temp_pilote;
}



void rechercherPilotes(Pilotes *pt_pilote, int *pt_nbrPilotes){

    system("cls");
    printf("\n\n");

    int choix, nbrPodium, i, resultatRecherche=0;
    char nomOuPrenom[25];
    Pilotes * temp_pilote= NULL;

    do{
        printf("Voulez vous rechercher un pilote par");
        printf("\n   1 : son nom ou son prenom");
        printf("\n   2 : son nombre de podium");
        printf("\n\nVotre choix : ");
        fflush(stdin);
        scanf("%d", &choix);
    }while(choix < 1 || choix > 2);

    switch (choix){
        case 1:
            printf("\n\nEntrez un nom ou un prenom : ");
            fflush(stdin);
            scanf("%s", nomOuPrenom);

            for (i=0; i<*pt_nbrPilotes; i++){
                if(strcmp(nomOuPrenom, pt_pilote[i].nom) == 0 || strcmp(nomOuPrenom, pt_pilote[i].prenom) == 0){ //on regarde combien de pilotes correspondent
                    ++resultatRecherche;
                }
            }

            temp_pilote=malloc(resultatRecherche*(sizeof(Pilotes))); //allocation d'un tableau de struct Pilotes en fct du nbr de pilotes trouves
            resultatRecherche=0; //remise à zero du compteur de pilotes correspondants pr pouvoir s'en servir pr enregistrer dans temp_pilote les pilotes correspondants

            for (i=0; i<*pt_nbrPilotes; i++){
                if(strcmp(nomOuPrenom, pt_pilote[i].nom) == 0 || strcmp(nomOuPrenom, pt_pilote[i].prenom) == 0){
                    ++resultatRecherche;
                    temp_pilote[resultatRecherche-1]=pt_pilote[i];
                }
            }
            break;

        case 2:
            printf("\n\nEntrez le nombre de podium : ");
            fflush(stdin);
            scanf("%d", &nbrPodium);
            for (i=0; i<*pt_nbrPilotes; i++){
                if(nbrPodium == pt_pilote[i].nbrPodium){
                    ++resultatRecherche;
                }
            }

            temp_pilote=malloc(resultatRecherche*(sizeof(Pilotes)));
            resultatRecherche=0;

            for (i=0; i<*pt_nbrPilotes; i++){
                if(nbrPodium == pt_pilote[i].nbrPodium){
                    ++resultatRecherche;
                    temp_pilote[resultatRecherche-1]=pt_pilote[i];
                }
            }
            break;
    }

    if(resultatRecherche!=0){
        afficherPilotes(temp_pilote, &resultatRecherche);
    }
    else{
        printf("\nAucun pilote correspondant n a ete trouve.\n");
    }

    free (temp_pilote);
}



void modifierPilotes(Pilotes *pt_pilote, int *pt_nbrPilotes){

    system("cls");
    printf("\n\n");


    int choix, i, resultatRecherche=0, jour, mois, annee;
    char nom[15], prenom[25];


    printf("\nVoulez-vous un rappel des pilotes actuellement enregistres (1/0) ? ");
    fflush(stdin);
    scanf("%d", &choix);
    if(choix){
        afficherPilotes(pt_pilote, pt_nbrPilotes);
    }
    printf("------------------------------------------------\n");


    printf("\n\nEntrez le nom du pilote que vous voulez modifier : ");
    fflush(stdin);
    scanf("%s", nom);
    printf("Entrez son prenom : ");
    fflush(stdin);
    scanf("%s", prenom);


    for (i=0; i<*pt_nbrPilotes; i++){
        if((strcmp(nom, pt_pilote[i].nom) == 0)&&(strcmp(prenom, pt_pilote[i].prenom) == 0)){
            printf("\nEntrez les nouvelles donnees de %s %s :", nom, prenom);
            printf("\n   Nom ? ");
            fflush(stdin);
            scanf("%s", pt_pilote[i].nom);
            printf("   Prenom ? ");
            fflush(stdin);
            scanf("%s", pt_pilote[i].prenom);
            printf("   Nombre de podium obtenu(s) (3 premiers) ? ");
            fflush(stdin);
            scanf("%d", &pt_pilote[i].nbrPodium);
            printf("   Date de naissance ? ");
                printf("\n      Jour : ");
                fflush(stdin);
                scanf("%d", &jour);
                printf("      Mois : ");
                fflush(stdin);
                scanf(" %d", &mois);
                printf("      Annee : ");
                fflush(stdin);
                scanf(" %d", &annee);
                pt_pilote[i].nbrDateNaissance=calculNbrDate(jour, mois, annee);

            ++resultatRecherche;
        }
    }
    if(resultatRecherche==0){printf("\nAucun pilote correspondant n a ete trouve.\n");}


    if(resultatRecherche==1){
        fichierPilotes = fopen(FICBINAIREPILOTES, "wb");
        if (fichierPilotes == NULL){
            printf("%s", strerror(errno));
            exit(99);
        }
        else{
            for(i=0; i<*pt_nbrPilotes; i++){
                fwrite (&pt_pilote[i], 1, sizeof(Pilotes), fichierPilotes );
            }
        }
        fclose(fichierPilotes) ;
    }
}
