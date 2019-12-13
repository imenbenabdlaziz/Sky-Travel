#include <stdio.h>
#include <string.h>
#include "reclamation.h"
#include <gtk/gtk.h>


void ajouter_reclamation(reclamation c)
{

 FILE *f;
 f=fopen("src/reclamation.txt","a+");
 if(f!=NULL)
 {
fprintf(f,"%s %s %d %d %d %s \n",c.id,c.type,c.jour,c.mois,c.annee,c.rec);
 fclose(f);
 }

}

void afficher_reclamation(GtkWidget *liste)
{

enum
{	ID,
	TYPE ,
	JOUR,
	MOIS,
	ANNEE,
	REC,
};

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[30];
char type[30];
char jour[20];
char mois[20];
char annee[20];
char rec[30];

store =NULL;

FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("rec",renderer,"text",REC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store=gtk_list_store_new(6,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("src/reclamation.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("src/reclamation.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s\n",id,type,jour,mois,annee,rec)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ID,id,TYPE,type,JOUR,jour,MOIS,mois,ANNEE,annee,REC,rec,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
}
void supprimer_reclamation(char id[])
{
reclamation c;
FILE *f;
FILE *f1;
f=fopen("src/reclamation.txt","r+");
f1=fopen("src/reclamationtemp.txt","w+");
if((f!=NULL) && (f1!=NULL))
{while(fscanf(f,"%s %s %d %d %d %s \n",c.id,c.type,&c.jour,&c.mois,&c.annee,c.rec)!=EOF)
{
if(strcmp(id,c.id)!=0)
fprintf(f1,"%s %s %d %d %d %s \n",c.id,c.type,c.jour,c.mois,c.annee,c.rec);
}
}
fclose(f);
fclose(f1);
remove("src/reclamation.txt");
rename("src/reclamationtemp.txt","src/reclamation.txt"); 
}
void ajouter_repense(char id[],char rep[])
{

 FILE *f;
 f=fopen("src/repense.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s \n",id,rep);
 
 }
fclose(f);
}
enum
{	ID1,
	REP1,
	COLUMNS1
};



void afficher_repense(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
reclamation c;
char id[100];
char rep[100];
store =NULL;

FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("rep",renderer,"text",REP1,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	

	
	store=gtk_list_store_new(COLUMNS1,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("src/repense.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("src/repense.txt","a+");
		while(fscanf(f,"%s %s \n",id,rep)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ID1,id,REP1,rep,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
}

void reche (char mat[20]){
reclamation c;
FILE *f;
FILE *f1;
char a[20];
f=fopen("src/reclamation.txt","r");
f1=fopen("src/temp.txt","a+");
while (fscanf(f,"%s %s %d %d %d %s \n",a,c.type,&c.jour,&c.mois,&c.annee,c.rec)!=EOF)
	{
if(strcmp(mat,a)==0)
fprintf(f1,"%s %s %d %d %d %s \n",a,c.type,c.jour,c.mois,c.annee,c.rec);
	}
fclose(f);
fclose(f1);
rename("src/temp.txt","src/reclamationsrech.txt");

}

void afficher_reche(GtkWidget *liste)
{

enum
{	ID,
	TYPE ,
	JOUR,
	MOIS,
	ANNEE,
	REC,
};

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char id[30];
char type[30];
char jour[20];
char mois[20];
char annee[20];
char rec[30];

store =NULL;

FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",ID,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("type",renderer,"text",TYPE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("date",renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("rec",renderer,"text",REC,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	store=gtk_list_store_new(6,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("src/reclamationsrech.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("src/reclamationsrech.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s\n",id,type,jour,mois,annee,rec)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,ID,id,TYPE,type,JOUR,jour,MOIS,mois,ANNEE,annee,REC,rec,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

}
}

