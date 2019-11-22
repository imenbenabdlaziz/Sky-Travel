#ifndef GESTIONCOMPTE_H_INCLUDED
#define GESTIONCOMPTE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 20

struct date{
    int jour;
    int mois;
    int annee;
};
typedef struct date date;

struct employe{
    char nom[taille];
    char prenom[taille];
    char email[taille];
    date naissance;
    date recrutement;
    char CNI[taille];
    char etat_civile;
    char addresse[taille];
    char numeroDeTel[taille];
    char nationalite[taile];
    int role;
};
typedef struct employe employe;

int downloaddata(char file_name[],employe tab[]);//retourne le nombre demployé
void uploaddata(char file_name[],employe tab[]);
int verifieConnection(char user[],char password[],login tab[],int taille);//retourne le role de lemployé(soit un simple employé soit un admin)
void ajouteremploye(employe e1,login tab[],int *taille);
void supprimeremploye(char CNI[],login tab[],int *taille);
void modifieremploye(char CNI[],login tab[],int *taille);

#endif // GESTIONCOMPTE_H_INCLUDED
