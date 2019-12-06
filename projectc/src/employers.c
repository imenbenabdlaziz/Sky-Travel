#include <stdio.h>
#include <string.h>
#include "employers.h"
#include <gtk/gtk.h>

enum
{
	IDENTIFIANT,
	MOT_DE_PASSE,
	NOM,
	PRENOM,
	SEXE,
	JOUR,
	MOIS,
	ANNEE,
	TEL,
	EMAIL,
	ADRESSE,
	COLUMNS
};

void ajouter_personne(personne p)
{

 FILE *f;
 f=fopen("employers.txt","a+");
 if(f!=NULL)
 {
 fprintf(f,"%s %s %s %s %s %d %d %d %s %s %s  \n",p.identifiant,p.mot_de_passe,p.nom,p.prenom,p.sexe,p.jour,p.mois,p.annee,p.tel,p.email,p.adresse);
 fclose(f);
 }

}

void afficher_personne(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;

char identifiant [30];
char mot_de_passe [30];
char nom [30];
char prenom [30];
char sexe [30];
char jour [30];
char mois [30];
char annee [30];
char tel [30];
char email [30];
char adresse [30];

store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("identifiant",renderer,"text",IDENTIFIANT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mot_de_passe",renderer,"text",MOT_DE_PASSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",SEXE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("mois",renderer,"text",MOIS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("annee",renderer,"text",ANNEE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("tel",renderer,"text",TEL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("email",renderer,"text",EMAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("adresse",renderer,"text",ADRESSE,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("employers.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("employers.txt","a+");
		while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",identifiant,mot_de_passe,nom,prenom,sexe,jour,mois,annee,tel,email,adresse)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,IDENTIFIANT,identifiant,MOT_DE_PASSE,mot_de_passe,NOM,nom,PRENOM,prenom,SEXE,sexe,JOUR,jour,MOIS,mois,ANNEE,annee,TEL,tel,EMAIL,email,ADRESSE,adresse,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void supprimer (char supp[30] )
{
FILE *f;
FILE *f1;
personne p;
f=fopen("/home/chiheb/Projects/projectc/src/employers.txt","r");
f1=fopen("/home/chiheb/Projects/projectc/src/file.txt","a+");
while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",p.identifiant,p.mot_de_passe,p.nom,p.prenom,p.sexe,&p.jour,&p.mois,&p.annee,p.tel,p.email,p.adresse)!=EOF)
{
	if (strcmp(p.identifiant,supp)!=0)	
	fprintf(f1,"%s %s %s %s %s %d %d %d %s %s %s  \n",p.identifiant,p.mot_de_passe,p.nom,p.prenom,p.sexe,p.jour,p.mois,p.annee,p.tel,p.email,p.adresse);
}
fclose(f);
fclose(f1);
remove("/home/chiheb/Projects/projectc/src/employers.txt");
rename("/home/chiheb/Projects/projectc/src/file.txt","/home/chiheb/Projects/projectc/src/employers.txt");
}


void modifier_personne(personne p)
{
char identifiant1 [30];
char mot_de_passe1 [30];
char nom1 [30];
char prenom1 [30];
char sexe1 [30];
int jour1 ;
int mois1 ;
int annee1 ;
char tel1 [30];
char email1 [30];
char adresse1 [30];

FILE *f;
FILE *f1;
int test=-1;



f=fopen("/home/chiheb/Projects/projectc/src/employers.txt","r");
f1=fopen("/home/chiheb/Projects/projectc/src/file.txt","a+");
while(fscanf(f,"%s %s %s %s %s %d %d %d %s %s %s\n",identifiant1,mot_de_passe1,nom1,prenom1,sexe1,&jour1,&mois1,&annee1,tel1,email1,adresse1)!=EOF)
{
	if (strcmp(p.identifiant,identifiant1)==0)	
	fprintf(f1,"%s %s %s %s %s %d %d %d %s %s %s  \n",p.identifiant,p.mot_de_passe,p.nom,p.prenom,p.sexe,p.jour,p.mois,p.annee,p.tel,p.email,p.adresse);
else
fprintf(f1,"%s %s %s %s %s %d %d %d %s %s %s  \n",identifiant1,mot_de_passe1,nom1,prenom1,sexe1,jour1,mois1,annee1,tel1,email1,adresse1);	
}

fclose(f);
fclose(f1);
remove("/home/chiheb/Projects/projectc/src/employers.txt");
rename("/home/chiheb/Projects/projectc/src/file.txt","/home/chiheb/Projects/projectc/src/employers.txt");
}







