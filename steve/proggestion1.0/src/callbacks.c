#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "gestionhotel.h"


	extern hotel tab1[100],tab_dispo[100];
	extern struct reservationhotel tab2[100];
	extern int nb_hotel,nb_hotel_resv,nb_hotel_dispo,creation_colonne1,creation_colonne2;
	extern reservationhotel recherche;
	
	//quand le user va se connecter j'aurais sa cni
	
	extern char *cni_connect;
	extern int nb_resv_user;
	
	//lid de le reservation qui sera sélectionée
	extern int id_resev_selec;
	
	//resoudre le pb de rafraichissment
	extern GtkListStore *store1;
	extern GtkListStore *store2;

	//la date
	extern int jour_local;
	extern int mois_local;
	extern int annee_local;



/*************************************************************************************************************************/
void on_buttonreservationhotel_clicked(GtkWidget *objet,gpointer user_data)
{

    recherche.arrive.jour = 0;
    recherche.arrive.mois = 0;
    recherche.arrive.annee = 0;
	//pour que les colomuns saffichent
	creation_colonne1 = 0;
	creation_colonne2 = 0;

	GtkWidget *fenetrehotel,*fenetrechoix;
	
	fenetrechoix = lookup_widget(objet,"choixreservation");
	gtk_widget_destroy(fenetrechoix);
	
	fenetrehotel = create_reservationhotel();
	gtk_widget_show(fenetrehotel);


}

void on_buttonrechercherh_clicked(GtkWidget *objet,gpointer user_data)
{	


	//recuperons la date systeme

    recherche.dt_res.jour = jour_local;
    recherche.dt_res.mois = mois_local;
    recherche.dt_res.annee = annee_local;
    
    //controlons le calendrier
    GtkWidget *aidedate1;
    aidedate1 = lookup_widget(objet,"labelerreurdate");
    int test_date_valide;
    

    
    //je teste si la date est valide
    test_date_valide = is_date_valide(recherche.dt_res,recherche.arrive);
    
    if(!test_date_valide){
    	//if(store1 != NULL)
    		gtk_list_store_clear(store1);
    	gtk_label_set_markup(GTK_LABEL(aidedate1),"<span foreground = \"#FF0000\" weight=\"bold\">*Sélectionnez une date valide!!!</span>");
    }
    else{//si tout va bien on lui affiche les recherches
    
    //on enleve tout potentiel message d'erreur
    gtk_label_set_text(GTK_LABEL(aidedate1),"");
    
		GtkWidget *combobox1;
		GtkWidget *combobox2;
		GtkWidget *combobox3;
		GtkWidget *input1,*input2,*input3,*aide1;

		int i;

		
		char prixmax[10],standing[6],pension[10];
		int Prixmax;

		
		input2 = lookup_widget (objet,"nbnuit");
		input3 = lookup_widget (objet,"nbchambre");

		combobox1 = lookup_widget(objet,"comboboxregion");
		combobox2 = lookup_widget(objet,"comboboxpension");
		combobox3 = lookup_widget(objet,"nbetoile");

		input1 = lookup_widget (objet,"entryprixmax");
		

		//j'enregistre dans des chaines de caracteres ensuite je vais les convertir en int pour exploiter
		strcpy(prixmax,gtk_entry_get_text(GTK_ENTRY(input1)));
		
		//eviter coredumped
		if(strcmp(prixmax,"") == 0){
			recherche.prix = 1000;
		}
		else{
			Prixmax = atoi(prixmax);
			recherche.prix = Prixmax;
		}

		
		recherche.nb_nuit = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));
		recherche.nb_chambre = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
		recherche.standing = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(combobox3));
		
		if (gtk_combo_box_get_active (GTK_COMBO_BOX(combobox1)) != -1 )
			strcpy(recherche.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
		else
			strcpy(recherche.region,"tunisie");
		
		
		//occupons nous de la pension
		
		recherche.pension = 1; // par defaut la pension est complète
		if (gtk_combo_box_get_active(GTK_COMBO_BOX(combobox2)) == 0){
			strcpy(pension,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
			recherche.pension = 0;
		}
		

		// l'id cest le nombre d'éléments dans le fichier hotel reservé avec l'id connecté
		recherche.id = nb_resv_user;
		
		//nous cherchons le nombre d'hotel dispo en fonction des critères
		nb_hotel_dispo = tab_hotels_dispo(tab1,nb_hotel,tab_dispo,recherche);
		
		//nous implementons le signal row-activated
		GtkWidget *treeview;
		treeview = lookup_widget(objet,"treeview1");
		g_signal_connect(treeview, "row-activated", (GCallback) view_onRowActivated, NULL);
		//je cree les colonnes une seule fois
		if(creation_colonne1 == 0){
			GtkCellRenderer *renderer;
			GtkTreeViewColumn *column;
					
			renderer = gtk_cell_renderer_pixbuf_new();
			column = gtk_tree_view_column_new_with_attributes(" Apercu",renderer,"pixbuf",IMG,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
		
			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes(" Region",renderer,"text",REGION,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
			
			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOM,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
			
			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes(" Standing",renderer,"text",STANDING,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
			
			renderer = gtk_cell_renderer_text_new();
			column = gtk_tree_view_column_new_with_attributes(" Prix",renderer,"text",PRIX,NULL);
			gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
			
			creation_colonne1++;
		}
				  

		
		//affichage du treeview
		view_search_hotel(tab_dispo,nb_hotel_dispo,GTK_TREE_VIEW(treeview),store1,recherche.pension);

		//affichage des indications au clients
		aide1 = lookup_widget(objet,"labelaide1");
		gtk_label_set_text(GTK_LABEL(aide1),"*Double-cliquez sur une\nligne pour l'a sélectionée");
	}
}



/*oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/
void on_buttonretourh_clicked(GtkWidget *objet,gpointer user_data)
{
	GtkWidget *fenetrehotel,*fenetrechoix;
	
	fenetrehotel = lookup_widget(objet,"reservationhotel");
	gtk_widget_destroy(fenetrehotel);
	
	fenetrechoix = create_choixreservation();
	gtk_widget_show(fenetrechoix);

}
/*oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/
//fonction qui permet la selection d'une ligne
void view_onRowActivated (GtkWidget *objet,gpointer user_data){
	
	//avant toute chose je vide le message d'erreur si il etait la
	GtkWidget *aide1;
	aide1 = lookup_widget(objet,"labelerreurhotel");
	gtk_label_set_text(GTK_LABEL(aide1),"");
	
	//je commence le vrai taff...
    GtkWidget *treeview,*aide2;
    char msg[100] = "l'Hotel ";
	treeview = lookup_widget(objet,"treeview1");

	GtkTreeSelection *selection;
    GtkTreeModel     *model;
    GtkTreeIter       iter;
 

  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
  gtk_tree_selection_set_mode (selection,GTK_SELECTION_SINGLE);
  
  if (gtk_tree_selection_get_selected(selection, &model, &iter))
  {
    gchar *name;
    int prix;
    gchar *standing,*region;

	//lorqu'une ligne est cliquée on commence a construire la reservation
    gtk_tree_model_get (model, &iter,REGION,&region,NOM,&name,PRIX,&prix,STANDING,&standing,-1);
    strcpy(recherche.nom,name);
    strcpy(recherche.region,region);
	recherche.prix = prix*recherche.nb_nuit*recherche.nb_chambre;
	recherche.standing = strlen(standing);
	
    g_print ("standing: %d\n",recherche.prix);
    
    aide2 = lookup_widget(objet,"labelaide2");
    strcat(msg,recherche.nom);
    strcat(msg," a été sélectionée cliquez sur reserver");
	gtk_label_set_text(GTK_LABEL(aide2),msg);

    g_free(name);
    g_free(standing);
    g_free(region);
  }

  }
 
/*oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/ 
  void on_buttonreserverh_clicked(GtkWidget *objet,gpointer user_data)
{
	int a;
	GtkWidget *treeview,*aide2;

	treeview = lookup_widget(objet,"treeview1");
	

	GtkTreeSelection *selection;
    	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
	
	a = my_tree_selection_count_selected_rows (selection);
	
	if(a == 1){
		int i,d;
		strcpy(recherche.CNI,cni_connect);
		recherche.id++;
		
		//ajout de la reservation a tab2
		tab2[nb_hotel_resv] = recherche;
		
		//je diminue le nombre de chambre
		for(i=0;i<nb_hotel;i++){
			if(strcmp(tab1[i].region,recherche.region) == 0 && strcmp(tab1[i].nom,recherche.nom) == 0 )
			{
				tab1[i].nb_chambre[recherche.pension] -= recherche.nb_chambre;
				d = i;
			}
				
		}
		
		//on augmente le nb de reservation totale et le nombre de reservation de l'user connecté
		nb_hotel_resv++;
		nb_resv_user++;
		g_print("tes reserv   %d",nb_resv_user);

		//uppload file
		uploaddatahotel("hotel.txt",tab1,nb_hotel);
		uploaddatareservhotel("hotelreserver.txt",tab2,nb_hotel_resv);
		
		g_print ("chambre restante: %d\n",tab1[d].nb_chambre[recherche.pension]);

	
		aide2 = lookup_widget(objet,"labelerreurhotel");
		gtk_label_set_markup(GTK_LABEL(aide2),"<span foreground = \"#FF0000\" weight=\"bold\">*Reservation reussite!!!</span>");
			
	}
	
	//si il n'a rien sélectionné
	else{
		aide2 = lookup_widget(objet,"labelerreurhotel");
		gtk_label_set_markup(GTK_LABEL(aide2),"<span foreground = \"#FF0000\" weight=\"bold\">*Sélectionnez un hotel !!!</span>");
	}
   
}


/*******************************************************************************************************************************/

//tout sur la fenetre mes reservation
/*************************************************************************************************/
void on_buttonafficherreservation_clicked(GtkWidget *objet,gpointer user_data)
{
	//pour que les colomuns saffichent
	creation_colonne1 = 0;
	creation_colonne2 = 0;
	
	//creation de la fenentre
	GtkWidget *fenetrereserv,*fenetrechoix;
	
	fenetrechoix = lookup_widget(objet,"choixreservation");
	gtk_widget_destroy(fenetrechoix);
	
	fenetrereserv = create_mesreservations();
	gtk_widget_show(fenetrereserv);
}

  
 

void on_buttonupdateresev_clicked(GtkWidget *objet,gpointer user_data)
{
	int a;
	GtkWidget *treeview,*aide2;

	treeview = lookup_widget(objet,"treeview3");
	

	GtkTreeSelection *selection;
    	selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
	
	a = my_tree_selection_count_selected_rows (selection);
	
	if(a == 1){
		GtkWidget *fenetremodif,*fenetrechoix;
	
		fenetrechoix = lookup_widget(objet,"mesreservations");
		gtk_widget_destroy(fenetrechoix);
	
		fenetremodif = create_windowmodification();
		gtk_widget_show(fenetremodif);
		
		g_print("ok");
	}
	
	//si il n'a rien sélectionné
	else{
		aide2 = lookup_widget(objet,"labelerreurreservation");
		gtk_label_set_markup(GTK_LABEL(aide2),"<span foreground = \"#FF0000\" weight=\"bold\">*Selectionnez une Reservation!!!</span>");
	}
		recherche.arrive.jour = 0;
	recherche.arrive.mois = 0;
	recherche.arrive.annee = 0;

}
/*******************************************************************************************/
//fenetre de modification

void
on_buttonmodifierannuler_clicked(GtkWidget *objet,gpointer user_data)
{
	GtkWidget *fenetremodif,*fenetrechoix;
	
	fenetremodif = lookup_widget(objet,"windowmodification");
	gtk_widget_destroy(fenetremodif);
	
	fenetrechoix = create_choixreservation();
	gtk_widget_show(fenetrechoix);

}


void
on_buttonmodifieconf_clicked(GtkWidget *objet,gpointer user_data)
{	
    GtkWidget *aidedate1;
    aidedate1 = lookup_widget(objet,"label53");
    int test_date_valide;
    

    
    //je teste si la date est valide
    test_date_valide = is_date_valide(recherche.dt_res,recherche.arrive);
    
    if(!test_date_valide){
    	//if(store1 != NULL)
    		gtk_list_store_clear(store1);
    	gtk_label_set_markup(GTK_LABEL(aidedate1),"<span foreground = \"#FF0000\" weight=\"bold\">*Selectionnez une date valide!!!</span>");
    }
    else{
    	GtkWidget *input1,*input2,*combobox;
	char pension[10];

	input1 = lookup_widget (objet,"spinbuttonmodifienbnuit");
	input2 = lookup_widget (objet,"spinbuttonmodifienbchambre");
	combobox = lookup_widget(objet,"comboboxmodifipension");
	
	recherche.nb_nuit = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input1));
	recherche.nb_chambre = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input2));

	//occupons nous de la pension
	recherche.pension = 1; // par defaut la pension est complète
	if (gtk_combo_box_get_active(GTK_COMBO_BOX(combobox)) == 0){
		strcpy(pension,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
		recherche.pension = 0;
	}
	
	//on modifie dans le tableau
	update_reserv_hotel(id_resev_selec,cni_connect,recherche,tab2,nb_hotel_resv);

	//uppload file
	uploaddatareservhotel("hotelreserver.txt",tab2,nb_hotel_resv);
	g_print("dansle file");
	
	//a la fin on retourne
	GtkWidget *fenetremodif,*fenetrechoix;
	
	fenetremodif = lookup_widget(objet,"windowmodification");
	gtk_widget_destroy(fenetremodif);
	
	fenetrechoix = create_choixreservation();
	gtk_widget_show(fenetrechoix);
    }
	


}
/********************************************************************************************/
/*ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/

void on_buttonretourr_clicked(GtkWidget *objet,gpointer user_data)
{
	GtkWidget *fenetrereserv,*fenetrechoix;
	
	fenetrereserv = lookup_widget(objet,"mesreservations");
	gtk_widget_destroy(fenetrereserv);
	
	fenetrechoix = create_choixreservation();
	gtk_widget_show(fenetrechoix);

}

/*ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/
void on_buttonsupprimerreserv_clicked(GtkWidget *objet,gpointer user_data)
{
	int a;
	GtkWidget *treeview,*aide2;

	treeview = lookup_widget(objet,"treeview3");
	

	GtkTreeSelection *selection;
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
	
	a = my_tree_selection_count_selected_rows (selection);
	
	if(a == 1){
	
		
		GtkWidget *fenetresup,*fenetrechoix;
	
		fenetrechoix = lookup_widget(objet,"mesreservations");
		gtk_widget_destroy(fenetrechoix);
	
		fenetresup = create_windowsuppresion ();
		gtk_widget_show(fenetresup);
		

	}
	
	//si il n'a rien sélectionné
	else{
		aide2 = lookup_widget(objet,"labelerreurreservation");
		gtk_label_set_markup(GTK_LABEL(aide2),"<span foreground = \"#FF0000\" weight=\"bold\">*Selectionnez une Reservation!!!</span>");
}
}
/*ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/

void on_buttonpayer_clicked(GtkWidget *objet,gpointer user_data)
{
	int a;
	GtkWidget *treeview,*aide2;

	treeview = lookup_widget(objet,"treeview3");
	

	GtkTreeSelection *selection;
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
	
	a = my_tree_selection_count_selected_rows (selection);
	
	if(a == 1){
		g_print("ok");
	}
	
	//si il n'a rien sélectionné
	else{
		aide2 = lookup_widget(objet,"labelerreurreservation");
		gtk_label_set_markup(GTK_LABEL(aide2),"<span foreground = \"#FF0000\" weight=\"bold\">*Selectionnez une Reservation!!!</span>");
	}


}

/*ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/
void on_buttonaffichemesresev_clicked(GtkWidget *objet,gpointer user_data)
{

	//affichage des reservations
	GtkWidget *treeview;
	treeview = lookup_widget(objet,"treeview3");
	g_signal_connect(treeview, "row-activated", (GCallback) view_onRowActivated_resv, NULL);
	
	//je cree les colonnes une seule fois
	if(creation_colonne2 == 0){
		GtkCellRenderer *renderer;
		GtkTreeViewColumn *column;
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Id",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Date de reservation",renderer,"text",DATE2,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Date d'arrivé",renderer,"text",DATERES,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Region",renderer,"text",REGION2,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Nom",renderer,"text",NOM2,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Standing",renderer,"text",STANDING2,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Nb chambre",renderer,"text",NBNUIT2,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Nb nuit",renderer,"text",NBCHAMBRE2,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes(" Prix",renderer,"text",PRIX2,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(treeview),column);
		
		
		creation_colonne2++;
	}
		
	
	//affichage du treeview
	view_reserv_hotel(cni_connect,tab2,nb_hotel_resv,GTK_TREE_VIEW(treeview),store2);

}


/*oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/
//fonction qui permet la selection d'une ligne de reservation
void view_onRowActivated_resv(GtkWidget *objet,gpointer user_data){

	//avant toute chose je vide le message d'erreur si il etait la
	GtkWidget *aide1;
	aide1 = lookup_widget(objet,"labelerreurreservation");
	gtk_label_set_text(GTK_LABEL(aide1),"");	
	
    GtkWidget *treeview,*aide2;
    char msg[] = "**Ligne sélectionée vous pouvez maintenant payer,modifier ou supprimer";
    char number[4];
	treeview = lookup_widget(objet,"treeview3");

	GtkTreeSelection *selection;
    GtkTreeModel     *model;
    GtkTreeIter       iter;
 

  selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
  gtk_tree_selection_set_mode (selection,GTK_SELECTION_SINGLE);
  
  if (gtk_tree_selection_get_selected(selection, &model, &iter))
  {

	//lorqu'une ligne est cliquée on recupère son id pour gerer la suppression et la modification
    gtk_tree_model_get (model, &iter,ID,&id_resev_selec,-1);
    
    g_print ("standing: %d\n",id_resev_selec);
    
    aide2 = lookup_widget(objet,"labelaideresv");
	gtk_label_set_text(GTK_LABEL(aide2),msg);

  }

  }
 
 
/*oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/


/******************************************************************************************************************************************/

void
on_buttonreservationvol_clicked(GtkWidget *objet,gpointer user_data){}

void
on_retourv_clicked(GtkWidget *objet,gpointer user_data){}

void
on_rechercherv_clicked(GtkWidget *objet,gpointer user_data){}

void
on_reserverv_clicked(GtkWidget *objet,gpointer user_data){}


void
on_reservationhotel_destroy(GtkWidget *objet,gpointer user_data){}

void
on_choixreservation_destroy(GtkWidget *objet,gpointer user_data){}

void
on_reservationvol_destroy(GtkWidget *objet,gpointer user_data){}
/******************************************************************************************************************************************/
void
on_mesreservations_destroy(GtkWidget *objet,gpointer user_data){
	/*uploaddatahotel("/home/fosso/Projects/reservation1/file/hotel.txt",tab1,nb_hotel);
	uploaddatareservhotel("/home/fosso/Projects/reservation1/file/hotelreserver.txt",tab2,nb_hotel_resv);
	gtk_main_quit();*/
}
/************************************************************************************************************/



//pop up suppression
/*********************************************************************************************************************************/
void
on_windowsuppresion_destroy(GtkWidget *objet,gpointer user_data)
{
	/*GtkWidget *fenetresup,*fenetrechoix;
	
	fenetresup = lookup_widget(objet,"windowsuppresion");
	gtk_widget_destroy(fenetresup);
	
	fenetrechoix = create_choixreservation();
	gtk_widget_show(fenetrechoix);*/

}


void
on_buttonconfsup_clicked(GtkWidget *objet,gpointer user_data)
{
	GtkWidget *r1,*r2;
	int resultat1,resultat2;
	
	r1 = lookup_widget(objet,"radiobutton1");
	r2 = lookup_widget(objet,"radiobutton2");
	
	/*gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (r1), FALSE);
    gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (r2), TRUE);*/
    
    g_signal_connect (GTK_TOGGLE_BUTTON (r1), "toggled", G_CALLBACK (button_toggled_cb), NULL);
    g_signal_connect (GTK_TOGGLE_BUTTON (r2), "toggled", G_CALLBACK (button_toggled_cb), NULL);
    
    resultat1 = button_toggled_cb(r1);
    resultat2 = button_toggled_cb(r2);
    
	if(resultat1){
		g_print("il veut supprimer");
		
		//fontion qui supprime
		delete_reserv_hotel(id_resev_selec,cni_connect,&nb_resv_user,tab2,&nb_hotel_resv);
	
		//uppload file
		uploaddatareservhotel("hotelreserver.txt",tab2,nb_hotel_resv);
	}
		
		
	if(resultat2)
		g_print("il ne veut pas supprimer");
		
	//après tout on retourne	
	GtkWidget *fenetresup,*fenetrechoix;
	
	fenetresup = lookup_widget(objet,"windowsuppresion");
	gtk_widget_destroy(fenetresup);
	
	fenetrechoix = create_choixreservation();
	gtk_widget_show(fenetrechoix);

}









void
on_buttonconfirmerpayement_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonretourpayement_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{

}

/****************************************************************************************/
void
on_calendarreservation1_day_selected(GtkWidget *objet,gpointer user_data)
{
	//calender
	GtkWidget * calendrier;
	calendrier = lookup_widget(objet,"calendarreservation1");
	gtk_calendar_get_date (GTK_CALENDAR (calendrier),&recherche.arrive.annee,&recherche.arrive.mois,&recherche.arrive.jour);
	recherche.arrive.mois++;
	g_print("%d %d %d\n",recherche.arrive.jour,recherche.arrive.mois,recherche.arrive.annee);

}


void
on_calendarreservation2_day_selected(GtkWidget *objet,gpointer user_data)
{
	//calender
	GtkWidget * calendrier;
	calendrier = lookup_widget(objet,"calendarreservation2");
	gtk_calendar_get_date (GTK_CALENDAR (calendrier),&recherche.arrive.annee,&recherche.arrive.mois,&recherche.arrive.jour);
	recherche.arrive.mois++;
	g_print("%d %d %d\n",recherche.arrive.jour,recherche.arrive.mois,recherche.arrive.annee);

}

