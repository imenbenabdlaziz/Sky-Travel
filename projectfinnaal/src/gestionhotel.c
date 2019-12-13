#include "gestionhotel.h"

/********************************************************************************************************************/
/********************************************************************************************************************/
/********************************************************************************************************************/
/********************************************************************************************************************/
//fonction pour download les files

int download_data_hotel(char file[],hotel tab[]){
	FILE *f;
	int i;
	f = fopen(file,"r");
	
	i = 0;
	if(f != NULL){
		while(fscanf(f,"%d %s %s %d %d %d %d %d\n",&tab[i].id,tab[i].nom,tab[i].region,&tab[i].standing,&tab[i].nb_chambre[0],&tab[i].nb_chambre[1],&tab[i].prix[0],&tab[i].prix[1]) != EOF)
			i++;
	}
	fclose(f);
	return i;
}
/*oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/

int download_data_resv_hotel(char file[],reservationhotel tab[]){
	FILE *f;
	int i;
	f = fopen(file,"r");
	
	i = 0;
	if(f != NULL){
		while(fscanf(f,"%d %s %d %d %d %s %s %d %d %d %d %d %d %d %d\n",&tab[i].id,tab[i].CNI,&tab[i].dt_res.jour,&tab[i].dt_res.mois,&tab[i].dt_res.annee,tab[i].nom,tab[i].region,&tab[i].nb_nuit,&tab[i].nb_chambre,&tab[i].standing,&tab[i].pension,&tab[i].arrive.jour,&tab[i].arrive.mois,&tab[i].arrive.annee,&tab[i].prix) != EOF)
			i++;
	}
	fclose(f);
	return i;
}

/********************************************************************************************************************/
/********************************************************************************************************************/
/********************************************************************************************************************/
/********************************************************************************************************************/
//fonction pour upload les files
void uploaddatahotel(char file[],hotel tab[],int n){
	FILE *f;
	int i;
	
	f = fopen(file,"w");
	
	if(f != NULL){
		for(i=0;i<n;i++){
			fprintf(f,"%d %s %s %d %d %d %d %d\n",tab[i].id,tab[i].nom,tab[i].region,tab[i].standing,tab[i].nb_chambre[0],tab[i].nb_chambre[1],tab[i].prix[0],tab[i].prix[1]);
		}

	}
	fclose(f);

}
/*oooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/
void uploaddatareservhotel(char file[],reservationhotel tab[],int n){
	int i;
	FILE *f;
	
	f = fopen(file,"w");
	
	if(f != NULL){
		for(i=0;i<n;i++){
			fprintf(f,"%d %s %d %d %d %s %s %d %d %d %d %d %d %d %d\n",tab[i].id,tab[i].CNI,tab[i].dt_res.jour,tab[i].dt_res.mois,tab[i].dt_res.annee,tab[i].nom,tab[i].region,tab[i].nb_nuit,tab[i].nb_chambre,tab[i].standing,tab[i].pension,tab[i].arrive.jour,tab[i].arrive.mois,tab[i].arrive.annee,tab[i].prix);
		
		}
		
		
	}
	fclose(f);

}


/********************************************************************************************************************/
/********************************************************************************************************************/
/********************************************************************************************************************/
//fonction pour filtrer la recherche les files
/***************************************************************************************************************************/
int tab_hotels_dispo(hotel tab1[],int n1,hotel tab2[],reservationhotel h1){
	int i,k;
	
	k = 0;
	
	for(i=0;i<n1;i++){
		if(strcmp(h1.region,"tunisie") == 0 && tab1[i].prix[h1.pension] <= h1.prix && tab1[i].standing >= h1.standing){	
			strcpy(tab2[k].region,tab1[i].region);
			strcpy(tab2[k].nom,tab1[i].nom);
			tab2[k].standing = tab1[i].standing;
			tab2[k].prix[0] = tab1[i].prix[0];
			tab2[k].prix[1] = tab1[i].prix[1];
			tab2[k].id = tab1[i].id;
			
			k++;
		}
	}


	for(i=0;i<n1;i++){
		if(strcmp(h1.region,tab1[i].region) == 0 && tab1[i].prix[h1.pension] <= h1.prix && tab1[i].standing >= h1.standing){
			strcpy(tab2[k].region,tab1[i].region);
			strcpy(tab2[k].nom,tab1[i].nom);
			tab2[k].standing = tab1[i].standing;
			tab2[k].prix[0] = tab1[i].prix[0];
			tab2[k].prix[1] = tab1[i].prix[1];
			tab2[k].id = tab1[i].id;
			
			k++;

		}
	}

	
	return k;
}

/*************************************************************************************************************************************/


/********************************************************************************************************************/
/********************************************************************************************************************/
/********************************************************************************************************************/
//fonction d'affichage des treeview

void view_search_hotel(hotel tab[],int n,GtkTreeView *liste,GtkListStore *store,int pension){


	GtkTreeIter iter;

	
	char region[20];
	char nom[20];
	int prix[2];
	int d,d1,d2,d3,i,x;
	GdkPixbuf *image;
	

	
	//on vide d'abord le treeview
	gtk_list_store_clear(store);
	store = NULL;	
	//x = gtk_tree_view_remove_column (liste,column);
	
	
	if(store == NULL){
		
		
		store = gtk_list_store_new(COLUMNS,GDK_TYPE_PIXBUF,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT);
		
		
	  	char s[6],the_img[100];
	  	int k;
	
		for(i=0;i<n;i++){
			gtk_list_store_append(store,&iter);
			for(k = 0;k<tab[i].standing;k++)
				s[k] = '*';
				
			s[tab[i].standing] = '\0';
			
			sprintf(the_img,"/home/chiheb/Bureau/projectcc/project31/pixmaps/%d.jpg",tab[i].id);
		
			
			//printf("%d\n",ccccc);
			//pension pour selectionner le prix selon la pension
			image = gdk_pixbuf_new_from_file(the_img, NULL);
			gtk_list_store_set(store,&iter,IMG,image,REGION,tab[i].region,NOM,tab[i].nom,STANDING,s,PRIX,tab[i].prix[pension],-1);
		}
		
		g_object_unref(image);
				

			gtk_tree_view_set_model(liste,GTK_TREE_MODEL(store));
			g_object_unref(store);
				
		
	}
}
/*ooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo*/
//fonction d'affichage des reservation dun client
void view_reserv_hotel(char cni_connect[], reservationhotel tab[],int n,GtkTreeView  *liste,GtkListStore *store){
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	
	
	
	char region[20];
	char nom[20];
	int prix[2];
	int d,d1,d2,d3,i;

	
	//on vide d'abord le treeview
	gtk_list_store_clear(store);
	store = NULL;
	
	
	if(store == NULL){

		store = gtk_list_store_new(COLUMNS2,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT);
		
		
		//variable pour formater la date
	  	char ladate[30],s[6],ladate2[30];
	  	int k;
	
		for(i=0;i<n;i++){
			if(strcmp(tab[i].CNI,cni_connect) == 0){
			gtk_list_store_append(store,&iter);
			
			//gestion du standind
			for(k = 0;k<tab[i].standing;k++)
				s[k] = '*';
			s[tab[i].standing] = '\0';
			
			
			//gestion de la date
	
			sprintf(ladate,"%d/%d/%d",tab[i].arrive.jour,tab[i].arrive.mois,tab[i].arrive.annee);
			sprintf(ladate2,"%d/%d/%d",tab[i].dt_res.jour,tab[i].dt_res.mois,tab[i].dt_res.annee);
			

			
		
			//pension pour selectionner le prix selon la pension
			gtk_list_store_set(store,&iter,ID,tab[i].id,DATE2,ladate2,DATERES,ladate,REGION2,tab[i].region,NOM2,tab[i].nom,STANDING2,s,NBNUIT2,tab[i].nb_nuit,NBCHAMBRE2,tab[i].nb_chambre,PRIX2,tab[i].prix,-1);
		}
				
		}
			
				

			gtk_tree_view_set_model(liste,GTK_TREE_MODEL(store));
			g_object_unref(store);
				
		
	}
}

/*****************************************************************************************************************/
/*****************************************************************************************************************/
int calcul_nb_resv_user(char cni_connect[],reservationhotel tab[],int n){
	int i,nb_resv_user=0;
	
	for(i=0;i<n;i++){
		if(strcmp(tab[i].CNI,cni_connect) == 0)
			nb_resv_user++;
	}
	return nb_resv_user;
}
/******************************************************************************************************************************/
//fonction pour savoir si exactement une ligne a été sélectionnée
static void count_foreach_helper (GtkTreeModel *model,
                        GtkTreePath  *path,
                        GtkTreeIter  *iter,
                        gpointer      userdata)
  {
    gint *p_count = (gint*) userdata;

    g_assert (p_count != NULL);

    *p_count = *p_count + 1;
  }

int my_tree_selection_count_selected_rows (GtkTreeSelection *selection)
  {
    int count = 0;

    gtk_tree_selection_selected_foreach(selection, count_foreach_helper, &count);

    return count;
  }
/************************************************************************************************************************/
void delete_reserv_hotel(int id,char cni_connect[],int *nb_resv_user,reservationhotel tab[],int *taille){
	int i,k,j,ct ;
	
	for(i=0;i<*taille;i++){
		//on cherche tout d'abord l'élement a supprimer
		if(strcmp(tab[i].CNI,cni_connect) == 0 && tab[i].id == id ){
			(*taille)--;
			(*nb_resv_user)--;
			
			
			//decalage classique
			for(j=i;j<*taille;j++)
                tab[j] = tab[j+1];
                
            //ensuite on doit ordonner les id si ce n'etait pas la derniere reservation du user donc si id != *nb_resv_user
            g_print("id = %d\nnb_resv_user = %d\n",id-1,*nb_resv_user);
            if((id-1) != *nb_resv_user){
            	
            	ct = 1;
            	for(j=0;j<*taille;j++){
            		if(strcmp(tab[j].CNI,cni_connect) == 0){
            				tab[j].id = ct;
            				ct++;
            			}
            	}
            			 
            }
        }

		
	}
}
/************************************************************************************************************************/
void update_reserv_hotel(int id,char cni_connect[],reservationhotel recherche,reservationhotel tab[],int taille){
	int i,prix;
	for(i=0;i<taille;i++){
		if(strcmp(tab[i].CNI,cni_connect) == 0 && tab[i].id == id ){
			if(recherche.arrive.jour != 0 && recherche.arrive.mois != 0 && recherche.arrive.annee != 0){
				tab[i].arrive.jour = recherche.arrive.jour ;
				tab[i].arrive.mois =  recherche.arrive.mois ;
				tab[i].arrive.annee =  recherche.arrive.annee; 
			}
			prix = (tab[i].prix)/(tab[i].nb_chambre*tab[i].nb_nuit);
			tab[i].nb_chambre = recherche.nb_chambre;
			tab[i].nb_nuit = recherche.nb_nuit;
			tab[i].prix = prix*recherche.nb_nuit*recherche.nb_chambre;
			tab[i].pension = recherche.pension;
			
		}
	}
}
/************************************************************************************************************************/
int button_toggled_cb (GtkWidget *button){
	 if (gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON (button))){
	  	return 1;
	}
	else
		return 0;
}
/*******************************************************************************************************/
int is_date_valide(date now,date arrive){
	int d = 1 ;
	
	if(arrive.annee < now.annee)
		d = 0;
	else if(arrive.annee == now.annee){
		if(arrive.mois < now.mois)
			d = 0;
		else if(arrive.mois == now.mois){
			if(arrive.jour < now.jour || arrive.jour == now.jour)
				d = 0;
		}
		
			
	}
	
	return d;
	
}
          

