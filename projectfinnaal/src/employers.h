#include <gtk/gtk.h>

typedef struct
{
char identifiant [30];
char mot_de_passe [30];
char nom[30];
char prenom [30];
char sexe [30];
int jour ;
int mois ;
int annee;
char tel [30];
char email [30];
char adresse [30];

}personne;

void ajouter_personne(personne p);
void afficher_personne(GtkWidget *liste);
void supprimerid(char supp [30]);
void modifier_personne(personne p);
void role(personne p);
void supprimer_personne(char supp[]);
void modifier_personnee(char identifiant[], char mot_de_passe[],char adresse[]) ;
