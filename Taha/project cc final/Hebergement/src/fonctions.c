#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>
enum
{
	IDENTIER,
	VILLE,
	ETOILES,
	PRIXNUITEE,
	CHAMBRES,
	NOM_HOTEL,
	TYPE_PENSION,
	COLUMNS
};

void ajouter_heberg(heberg h)
{

 FILE *f;
 f=fopen("utilisateur.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %d %s %s %s %s  \n",h.identier,h.ville,h.etoiles,h.prixnuitee,h.chambres,h.nom_hotel,h.type_pension);
 fclose(f);
 }

}

void afficher_heberg(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identier [30];
char ville [30];
int  etoiles;
char prixnuitee [30];
char chambres [30];
char nom_hotel [30];
char type_pension [30];
store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("identier",renderer,"text",IDENTIER,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("ville",renderer,"text",VILLE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("etoiles",renderer,"text",ETOILES,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prixnuitee",renderer,"text",PRIXNUITEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("chambres",renderer,"text",CHAMBRES,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom_hotel",renderer,"text",NOM_HOTEL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type_pension",renderer,"text",TYPE_PENSION,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("utilisateur.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("utilisateur.txt","a+");
		while(fscanf(f,"%s %s %d %s %s %s %s  \n",identier,ville,&etoiles,prixnuitee,chambres,nom_hotel,type_pension)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,IDENTIER,identier,VILLE,ville,ETOILES,etoiles,PRIXNUITEE,prixnuitee,CHAMBRES,chambres,NOM_HOTEL,nom_hotel,TYPE_PENSION,type_pension,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}
void supprimer_heberg(char identier1[]){
heberg h;
FILE *f_heberge;
FILE *f_heberge1;

int r;
int n;
f_heberge=fopen("utilisateur.txt","r");
f_heberge1=fopen("utilisateur1.txt","w");
if (f_heberge!=NULL){
    if(f_heberge1!=NULL){
while(fscanf(f_heberge,"%s %s %d %s %s %s %s",h.identier,h.ville,&h.etoiles,h.prixnuitee,h.chambres,h.nom_hotel,h.type_pension)!=EOF ) {
    if(strcmp(identier1,h.identier)!=0){
        fprintf(f_heberge1,"%s %s %d %s %s %s %s \n",h.identier,h.ville,h.etoiles,h.prixnuitee,h.chambres,h.nom_hotel,h.type_pension);
        r=1;
    }
}
    }
    fclose(f_heberge1);
}

fclose(f_heberge);
if (r){
	remove ("utilisateur.txt");
	rename ("utilisateur1.txt","utilisateur.txt");
	}

}
void modifier_heberg(heberg h){
int n=0;
char identier1[3000];

char modidentier[2000];
char modville[20];
int  modetoiles;
char modprix[30];
char modchambres[30];
char modnom[20];
char modpension[1000];


    FILE *f_heberg;
    FILE *f_heberg1;
f_heberg=fopen("utilisateur.txt","r");
f_heberg1=fopen("utilisateur2.txt","w");
if(f_heberg!=NULL){
    if(f_heberg1!=NULL){
while (fscanf(f_heberg,"%s %s %d %s %s %s %s",modidentier,modville,&modetoiles,modprix,modchambres,modnom,modpension,&n)!=EOF){
            if  (strcmp(h.identier,modidentier)==0){
 fprintf(f_heberg1,"%s %s %d %s %s %s %s \n",h.identier,h.ville,h.etoiles,h.prixnuitee,h.chambres,h.nom_hotel,h.type_pension,n);
            }
            else {
   fprintf(f_heberg1,"%s %s %d %s %s %s %s  \n",modidentier,modville,modetoiles,modprix,modchambres,modnom,modpension,n);
            }
        }
    }
}
fclose(f_heberg1);
fclose(f_heberg);
remove("utilisateur.txt");
rename("utilisateur2.txt","utilisateur.txt");
}


