/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interfacere.h"
#include "support.h"
#include "gestionhotel.h"

//toutes mes variables globales
	hotel tab1[100],tab_dispo[100];
	struct reservationhotel tab2[100];
	int nb_hotel,nb_hotel_resv,nb_hotel_dispo,creation_colonne1 = 0,creation_colonne2 = 0;
	reservationhotel recherche;
	
	//quand le user va se connecter j'aurais sa cni
	
	char *cni_connect = "cnitest";
	int nb_resv_user = 0;
	
	//lid de le reservation qui sera sélectionée
	int id_resev_selec = 0;
	
	//resoudre le pb de rafraichissment
	GtkListStore *store1 = NULL;
	GtkListStore *store2 = NULL;
	
	int jour_local;
	int mois_local;
	int annee_local;


int main (int argc, char *argv[])
{

	//je charge dabord mes data
		nb_hotel = download_data_hotel("hotel.txt",tab1);
		nb_hotel_resv = download_data_resv_hotel("hotelreserver.txt",tab2);
		nb_resv_user = calcul_nb_resv_user(cni_connect,tab2,nb_hotel_resv);
		
	//je recupère la date systeme
	time_t timestamp; 
    struct tm * t; 
  
    timestamp = time(NULL); 
    t = localtime(&timestamp); 
	
    printf("%d/%d/%d\n", t->tm_mday,t->tm_mon + 1, 1900 + t->tm_year);
    jour_local = t->tm_mday;
    mois_local = t->tm_mon + 1;
    annee_local = 1900 + t->tm_year;
		
  GtkWidget *reservationhotel;
  GtkWidget *choixreservation;
  GtkWidget *reservationvol;
  GtkWidget *mesreservations;
  GtkWidget *windowsuppresion;
  GtkWidget *windowmodification;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */

  choixreservation = create_choixreservation ();
  gtk_widget_show (choixreservation);
  
  
  

  gtk_main ();
  return 0;
}

