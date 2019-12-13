#include<gtk/gtk.h>
#include<string.h>
typedef struct
{
char id[30];
char type[30];
int jour;
int mois;
int annee;
char rec[100];

}reclamation;

void ajouter_reclamation(reclamation c);
void afficher_reclamation(GtkWidget *liste);
void supprimer_reclamation(char id[]);
void ajouter_repense(char id[],char rep[]);
void afficher_repense(GtkWidget *liste);
void recherche (char mat[20]);
void afficher_recherche(GtkWidget *liste);
