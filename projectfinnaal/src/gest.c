#include <string.h>
#include "gest.h"
#include "interfacev.h"

#include <stdio.h>
#include <gtk/gtk.h>
#include <stdlib.h>


enum
{	ID,
	DEPART,
	ARRIVEE,
	JOUR,
	MOIS,
	ANNEE,
	DUREE,
	PRIX,
	NBRVOYAGEUR,
	CLASSE,
	COLUMNS

};

void ajouter(vol p)
{
FILE*f;
f=fopen("ajt.txt","a+");
if(f!=NULL)
{fprintf(f,"%s %s %s %d %d %d %s %s %s %s\n",p.id,p.depart,p.arriver,p.jour,p.mois,p.annee,p.duree,p.prix,p.nbrvoyageur,p.classe);

fclose(f);}
}

void afficher(GtkWidget *liste)
{
	GtkCellRenderer *renderer;

	GtkTreeViewColumn *column;
	
	GtkTreeIter iter;

	GtkListStore *store;

	char id [40];
	char depart[40];
	char arriver[40];
	int jour;
	int mois;
	int annee;
	char duree[40];
	char prix[40];
	char nbrvoyageur[40];
	char classe[40];

	store=NULL;

	FILE *f;

	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("id vol", renderer, "text", ID, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Ville de depart", renderer, "text", DEPART, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Ville d'arrivee", renderer, "text", ARRIVEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);


		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("jour", renderer, "text", JOUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
		
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("mois", renderer, "text", MOIS, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("annee", renderer, "text",ANNEE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Duree de vol", renderer, "text", DUREE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("prix du vol", renderer, "text", PRIX, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("nombre des voyageurs", renderer, "text", NBRVOYAGEUR, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

		

		renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("Classe", renderer, "text", CLASSE, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);



	
		store=gtk_list_store_new (COLUMNS, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_INT,G_TYPE_INT,G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
		f = fopen("ajt.txt","r");
		if(f==NULL)
		{
			return;
		}
		else
		{ f = fopen("ajt.txt","a+");
			while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s\n",id,depart,arriver,&jour,&mois,&annee,duree,prix,nbrvoyageur, classe)!= EOF)
		{
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter,ID,id,DEPART,depart, ARRIVEE,arriver, JOUR,jour,MOIS,mois,ANNEE,annee,DUREE, duree,PRIX, prix,NBRVOYAGEUR, nbrvoyageur ,CLASSE, classe,-1);
		}
		fclose(f);
		gtk_tree_view_set_model (GTK_TREE_VIEW(liste), GTK_TREE_MODEL (store)); 
		g_object_unref(store);
		}
		
}
}
 
      
void modifier(char id[],char depart[], char arriver[],int jour,int mois,int annee,char duree[],char prix[],char nbrvoyageur[], char classe[]) 

{
vol p;
FILE*f;
FILE*tmp; 
 
f=fopen("ajt.txt","r");
tmp=fopen("tmp.txt","w");
 if(f!=NULL) 
{ 
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n",p.id,p.depart,p.arriver,&p.jour,&p.mois,&p.annee,p.duree,p.prix,p.nbrvoyageur,p.classe)!=EOF)	
{ 
if(strcmp(id,p.id)==0)
{fprintf(tmp,"%s %s %s %d %d %d %s %s %s %s \n",id,depart,arriver,jour,mois,annee,duree,prix,nbrvoyageur,classe);}
else
fprintf(tmp,"%s %s %s %d %d %d %s %s %s %s \n",p.id,p.depart,p.arriver,p.jour,p.mois,p.annee,p.duree,p.prix,p.nbrvoyageur,p.classe);
} 
}
fclose(f) ; 
fclose(tmp);
remove("ajt.txt");
rename("tmp.txt","ajt.txt");
}


void supprimeri(char id[]) 

{
vol p;
FILE*f;
FILE*tmp; 
 
f=fopen("ajt.txt","r");
tmp=fopen("tmp.txt","w");
 if(f!=NULL) 
{ 
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n",p.id,p.depart,p.arriver,&p.jour,&p.mois,&p.annee,p.duree,p.prix,p.nbrvoyageur,p.classe)!=EOF)	
{ 
if(strcmp(id,p.id)!=0)
{

fprintf(tmp,"%s %s %s %d %d %d %s %s %s %s \n",p.id,p.depart,p.arriver,p.jour,p.mois,p.annee,p.duree,p.prix,p.nbrvoyageur,p.classe);

}


} 
}
fclose(f) ; 
fclose(tmp);
remove("ajt.txt");
rename("tmp.txt","ajt.txt");
}


