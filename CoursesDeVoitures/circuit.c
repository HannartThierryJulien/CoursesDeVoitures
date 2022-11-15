#include "circuit.h"


FILE * fichierCircuits = NULL;


void ajouterCircuits(){

    system("cls");
    printf("\n\n");

    int nbrCircuitsAAjouter, i;
    Circuits * circuit = NULL;

    printf("Combien de circuits voulez vous ajouter ? ");
    scanf("%d", &nbrCircuitsAAjouter);
    printf("\n");

    if(nbrCircuitsAAjouter>0){

        circuit = malloc(nbrCircuitsAAjouter*(sizeof(Circuits)));

        fichierCircuits = fopen(FICBINAIRECIRCUITS, "ab");
        if (fichierCircuits == NULL){
            printf("%s", strerror(errno));
            exit(99);
        }
        else{
            for(i=0; i<nbrCircuitsAAjouter; i++){
                printf("\nCircuit %d - Completez ces champs :\n", i+1);
                printf("   Nom ? ");
                fflush(stdin);
                scanf("%s", circuit[i].nom);
                printf("   Pays ? ");
                fflush(stdin);
                scanf("%s", circuit[i].pays);
                printf("   Longueur en km et au metre pres (ex : 5,793) ? ");
                fflush(stdin);
                scanf("%f", &circuit[i].longueur);

                fwrite (&circuit[i], 1, sizeof(Circuits), fichierCircuits );
            }
        }
        fclose(fichierCircuits) ;
    }
    free(circuit);
}



void afficherCircuits(Circuits *pt_circuit, int *pt_nbrCircuits){

    system("cls");
    printf("\n\n");

    int i;

    printf("Nombre de circuits : %d\n\n", *pt_nbrCircuits);

    for (i=0; i<*pt_nbrCircuits; i++){
        printf("\nNom : %s \n", pt_circuit[i].nom);
        printf("Pays : %s \n", pt_circuit[i].pays);
        printf("Longueur : %.3f KM \n", pt_circuit[i].longueur);
    }
}



void trierCircuits(Circuits *pt_circuit, int *pt_nbrCircuits){

    system("cls");
    printf("\n\n");

    int i, j, choix;

    do{
        printf("Trier les circuits par leur longueur de facon\n");
        printf("   1 : croissante\n");
        printf("   2 : decroissante\n");
        printf("\nVotre choix : ");
        fflush(stdin);
        scanf("%d", &choix);
    }while(choix < 1 || choix > 2);

    switch (choix){
        case 1:
            for(i=0;i<*pt_nbrCircuits-1;i++){
                for(j=i+1;j<*pt_nbrCircuits;j++){
                    if(pt_circuit[i].longueur > pt_circuit[j].longueur){
                        echangerCircuits(&pt_circuit[i], &pt_circuit[j]);
                    }
                }
            }
            break;
        case 2:
            for(i=0;i<*pt_nbrCircuits-1;i++){
                for(j=i+1;j<*pt_nbrCircuits;j++){
                    if(pt_circuit[i].longueur < pt_circuit[j].longueur){
                        echangerCircuits(&pt_circuit[i], &pt_circuit[j]);
                    }
                }
            }
            break;
        default:
            break;
    }

    printf("\n\nCircuits tries :\n\n");
}



void echangerCircuits(Circuits *circuit1, Circuits *circuit2){
    Circuits temp_circuit = *circuit1;
    *circuit1 = *circuit2;
    *circuit2 = temp_circuit;
}



void rechercherCircuits(Circuits *pt_circuit, int *pt_nbrCircuits){ //fct15

    system("cls");
    printf("\n\n");

    int choix, i, resultatRecherche=0;
    char nom[25], pays[20];
    Circuits * temp_circuit = NULL;

    do{
        printf("Voulez vous rechercher un circuit par");
        printf("\n   1 : son nom");
        printf("\n   2 : le pays dans lequel il est situe");
        printf("\n\nVotre choix : ");
        fflush(stdin);
        scanf("%d", &choix);
    }while(choix < 1 || choix > 2);

    switch (choix){
        case 1:
            printf("\n\nEntrez un nom : ");
            fflush(stdin);
            scanf("%s", nom);

            for (i=0; i<*pt_nbrCircuits; i++){
                if(strcmp(nom, pt_circuit[i].nom) == 0){
                    ++resultatRecherche;
                }
            }

            temp_circuit=malloc(resultatRecherche*(sizeof(Circuits)));
            resultatRecherche=0;

            for (i=0; i<*pt_nbrCircuits; i++){
                if(strcmp(nom, pt_circuit[i].nom) == 0){
                    ++resultatRecherche;
                    temp_circuit[resultatRecherche-1]=pt_circuit[i];
                }
            }
            break;

        case 2:
            printf("\n\nEntrez le nom d un pays : ");
            fflush(stdin);
            scanf("%s", pays);

            for (i=0; i<*pt_nbrCircuits; i++){
                if(strcmp(pays, pt_circuit[i].pays) == 0){
                    ++resultatRecherche;
                }
            }

            temp_circuit=malloc(resultatRecherche*(sizeof(Circuits)));
            resultatRecherche=0;

            for (i=0; i<*pt_nbrCircuits; i++){
                if(strcmp(pays, pt_circuit[i].pays) == 0){
                    ++resultatRecherche;
                    temp_circuit[resultatRecherche-1]=pt_circuit[i];
                }
            }
            break;

        default:
            break;
    }

    if(resultatRecherche!=0){
        afficherCircuits(temp_circuit, &resultatRecherche);
    }
    else{
        printf("\nAucun circuit correspondant n a ete trouve.\n");
    }

    free (temp_circuit);
}



void modifierCircuits(Circuits *pt_circuit, int *pt_nbrCircuits){

    system("cls");
    printf("\n\n");


    int choix, i, resultatRecherche=0;
    char nom[25];


    printf("\nVoulez-vous un rappel des circuits actuellement enregistres (1/0) ? ");
    fflush(stdin);
    scanf("%d", &choix);
    if(choix){
        afficherCircuits(pt_circuit, pt_nbrCircuits);
    }
    printf("------------------------------------------------\n");


    printf("\n\nEntrez le nom du circuit que vous voulez modifier : ");
    fflush(stdin);
    scanf("%s", nom);


    for (i=0; i<*pt_nbrCircuits; i++){
        if(strcmp(nom, pt_circuit[i].nom) == 0){
            printf("\nEntrez les nouvelles donnees du circuit %s :", nom);
            printf("\n   Nom ? ");
            fflush(stdin);
            scanf("%s", pt_circuit[i].nom);
            printf("   Pays ? ");
            fflush(stdin);
            scanf("%s", pt_circuit[i].pays);
            printf("   Longueur en km et au metre pres (ex : 5,793) ? ");
            fflush(stdin);
            scanf("%f", &pt_circuit[i].longueur);

            ++resultatRecherche;
        }
    }
    if(resultatRecherche==0){printf("\nAucun circuit correspondant n a ete trouve.\n");}


    if(resultatRecherche==1){
        fichierCircuits = fopen(FICBINAIRECIRCUITS, "wb");
        if (fichierCircuits == NULL){
            printf("%s", strerror(errno));
            exit(99);
        }
        else{
            for(i=0; i<*pt_nbrCircuits; i++){
                fwrite (&pt_circuit[i], 1, sizeof(Circuits), fichierCircuits );
            }
        }
        fclose(fichierCircuits) ;
    }
}
