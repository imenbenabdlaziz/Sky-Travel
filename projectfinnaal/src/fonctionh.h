#include <gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>

typedef struct
{
char id[2000];
char ville[20];
int etoiles;
char prixnuitee[30];
char chambres[30];
char nom_hotel[20];
char type_pension[1000];

}heberg;

void ajouter_heberg(heberg h);
void afficher_heberg(GtkWidget *liste);
void supprimer_heberg(char id1[]);
void modifier_heberg(heberg h);
