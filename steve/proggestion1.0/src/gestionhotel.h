#ifndef GESTIONHOTEL_H_INCLUDED
#define GESTIONHOTEL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <gtk/gtk.h>
#define taillemax 20

enum{
	IMG,
	REGION,
	NOM,
	STANDING,
	PRIX,
	COLUMNS
};

enum{
	ID,DATE2,DATERES,REGION2,NOM2,STANDING2,NBCHAMBRE2,NBNUIT2,PRIX2,COLUMNS2	
};
typedef struct date date;
struct date{
    int jour;
    int mois;
    int annee;
};

typedef struct hotel hotel;
struct hotel{
	int id;
	char nom[taillemax];
	char region[taillemax];
	int standing;
	int nb_chambre[2]; // dans la premiere case on a le nb de chambre en 1/2 pension et dans la seconde l nb de chamb.. en complète
	int prix[2]; // meme chose avec le nb de chambre

};

// /home/fosso/Projects/reservation/file/hotelreserver.txt
// /home/fosso/Projects/reservation/file/hotel.txt



struct reservationhotel{
	int id;
	char CNI[20];
	date dt_res;
	char nom[taillemax];
	char region[taillemax];
	int nb_nuit;
	int nb_chambre;
	int standing;
	int pension; //0 - 1/2 pension et 1 - complete
	date arrive;
	int prix;
};
typedef struct reservationhotel reservationhotel;

//j'aurais besoin des structures vols et hotels ainsi que des fichiers correspondant

//chargement des tab de reservation
int download_data_hotel(char file[],hotel tab[]);//retourne tous les hotels
int download_data_resv_hotel(char file[],reservationhotel tab[]);//retourne le nombre de reservation d'hotel

//modification des fichiers de reservations
void uploaddatahotel(char file[],hotel tab[],int n); //met a jour le fichier  des hotels
void uploaddatareservhotel(char file[],reservationhotel tab[],int n); //met a jour le fichier de reservation des hotels

//fonctions de verifications
int ver_chambres_dispo(hotel h1,hotel tab[],int n);//verifie les chambres dispo

//remplissage des tab de reservation dispo suivant les critères
int tab_hotels_dispo(hotel tab1[],int n1,hotel tab2[],reservationhotel h1);//tab1 contient tous les hotels,tab2 contiendra les hotels suivant les criteres stockés dans h1(h1.prix = prix_max,h1.nom = "")


// CROUD reservation
void add_reserv_hotel(reservationhotel r1,reservationhotel tab[],int *taille);

void delete_reserv_hotel(int id,char cni_connect[],int *nb_resv_user,reservationhotel tab[],int *taille);

void update_reserv_hotel(int id,char cni_connect[],reservationhotel recherche,reservationhotel tab[],int taille);

void view_reserv_hotel(char cni_connect[], reservationhotel tab[],int n,GtkTreeView  *liste,GtkListStore *store);
void view_search_hotel(hotel tab[],int n,GtkTreeView *liste,GtkListStore *store,int pension);
/****************************/
/****************************/
//petite fonction
int calcul_nb_resv_user(char cni_connect[],reservationhotel tab[],int n);
//*********************************************************************************************************************************/
//reception du numéro de la ligne
//ces fonction me permettent plutot de savoir si une ligne est selectionné ou non.utiliser pour la sécurité
int my_tree_selection_count_selected_rows (GtkTreeSelection *selection);
static void count_foreach_helper (GtkTreeModel *model,
                        GtkTreePath  *path,
                        GtkTreeIter  *iter,
                        gpointer      userdata);
//a = my_tree_selection_count_selected_rows (selection);
/**********************************************************************************************************************************/
//le pop up
int button_toggled_cb (GtkWidget *button);

//la date
int is_date_valide(date now,date arrive);


#endif // GESTIONHOTEL_H_INCLUDED
