#include "general-autre.h"

int calculNbrDate(int jourEntre, int moisEntre, int anneeEntree){

    long int nbrNaissance=(anneeEntree*10000)+(moisEntre*100)+jourEntre;

    return nbrNaissance;
}



void DateEntiere(int * tabDate, long int nbrDateEntree){

    tabDate[0]=nbrDateEntree%100; //jour
    tabDate[1]=((nbrDateEntree-tabDate[0])/100)%100; //mois
    tabDate[2]=((nbrDateEntree-tabDate[1])/10000)%10000; //annee
}



int calculerNumeroNationalFaitMaison(char nomEntre[], char prenomEntre[], long int nbrDateNaissanceEntre){

    int nn=0;
    int i;

    for(i=0; i<3; i++){
        nn+=nomEntre[i];
    }

    for(i=0; i<2; i++){
        nn+=prenomEntre[i];
    }

    nbrDateNaissanceEntre+=nn;

    return nbrDateNaissanceEntre;
}
