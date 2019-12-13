#include<gtk/gtk.h>
#include<string.h>
typedef struct
{
int j;
int m;
int a;
}dat;

typedef struct
{
char nom[100];
char prenom[100];
dat d;
char adresse[100];
char email[100];
char pays[100];
char sexe[100];
char motdepasse[100];
}client;
void modifier_clients(char nom1[],char prenom1[], char pays1[],int j,int m,int a,char sexe1[],char adresse1[],char email1[], char motdepasse1[]);
void modifier_users(char email[], char motdepasse[]);
void inscription(client c);
void supprimer(char email1[]);
void supprimer1(char email1[]);
void afficherclient(char id[],char nom[]);
void afficher_reclamations(GtkWidget *liste);
void reclamations_clients(char email1[]);
int verifier (char login[], char password[]);

