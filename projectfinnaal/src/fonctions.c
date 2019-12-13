#include <stdio.h>
#include <string.h>
#include "fonctions.h"
#include <gtk/gtk.h>


/*void reclamation_clients(char email[],char email1[],char nom[],char prenom[],char dat[],char objet1[])
{
client c;
FILE *f;
FILE *tmp1;

f=fopen("reclamations.txt","r");
tmp1=fopen("tmp1.txt","a");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",email,nom,prenom,dat,objet)!=EOF)
{
if(strcmp(email1,email)!=0)
{
fprintf(tmp1,"%s %s %s %s %s \n",email,nom,prenom,dat,objet);
}
fclose(f);
fclose(tmp1);

}
}
}
*/




enum
{
	EMAIL,
	NOM,
	PRENOM,
	DAT,
	OBJET,
	COLUMNS
};



void afficher_reclamations(GtkWidget *liste)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;


char nom[30];
char prenom [30];
char dat [30];
char email [30];
char objet [30];
store =NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("email",renderer,"text",EMAIL,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("nom",renderer,"text",NOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);
	
	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",PRENOM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("dat",renderer,"text",DAT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);

	renderer=gtk_cell_renderer_text_new();
	column=gtk_tree_view_column_new_with_attributes("objet",renderer,"text",OBJET,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column);


	


	

	


	
	
	

	store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

	f=fopen("tmp1.txt","r");

	if(f==NULL)
	{
		return;
	}
	else
	
	{ 
	f=fopen("tmp1.txt","a+");
		while(fscanf(f,"%s %s %s %s %s \n",email,nom,prenom,dat,objet)!=EOF)
		{
			gtk_list_store_append(store,&iter);
			gtk_list_store_set(store,&iter,EMAIL,email,NOM,nom,PRENOM,prenom,DAT,dat,OBJET,objet,-1);
		}
	   fclose(f);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
	g_object_unref(store);
	}
}
}

void modifier_clients(char nom[],char prenom[], char pays[],int j,int m,int a,char sexe[],char adresse[],char email[], char motdepasse[]) 

{
client c;
FILE*f;
FILE*tmp; 
 
f=fopen("clients.txt","r");
tmp=fopen("tmp.txt","w");
 if(f!=NULL) 
{ 
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n",c.nom,c.prenom,c.pays,&c.d.j,&c.d.m,&c.d.a,c.sexe,c.adresse,c.email,c.motdepasse)!=EOF)	
{ 
if(strcmp(email,c.email)==0)
{fprintf(tmp,"%s %s %s %d %d %d %s %s %s %s \n",nom,prenom,pays,j,m,a,sexe,adresse,email,motdepasse);}
else
fprintf(tmp,"%s %s %s %d %d %d %s %s %s %s \n",c.nom,c.prenom,c.pays,c.d.j,c.d.m,c.d.a,c.sexe,c.adresse,c.email,c.motdepasse);
} 
}
fclose(f) ; 
fclose(tmp);
remove("clients.txt");
rename("tmp.txt","clients.txt");
}

















void modifier_users(char email[], char motdepasse[]) 

{
client c;
FILE*f;
FILE*tmp;
int role=1; 
f=fopen("users.txt","r");
tmp=fopen("tmp.txt","w");
 if(f!=NULL) 
{ 
while(fscanf(f,"%s %s %d\n",c.email,c.motdepasse,&role)!=EOF)	
{ 
if(strcmp(email,c.email)==0)
{fprintf(tmp,"%s %s %d\n",email,motdepasse,role);}
else
fprintf(tmp,"%s %s %d\n",c.email,c.motdepasse,role);
} 
}
fclose(f) ; 
fclose(tmp);
remove("users.txt");
rename("tmp.txt","users.txt");
}


void afficherclient(char id[],char nom[])
{


client c;
FILE *f;
f=fopen("clients.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n",c.nom,c.prenom,c.pays,&c.d.j,&c.d.m,&c.d.a,c.sexe,c.adresse,c.email,c.motdepasse)!=EOF)
{
if(strcmp(id,c.email)==0)
{
    strcpy(nom,c.nom);
}





}
}
fclose(f);
}





























void inscription(client c)
{
 FILE *f;
 
 f=fopen("clients.txt","a+");
 if(f!=NULL)
 {
 int role=1;
 fprintf(f,"%s %s %s %d %d %d %s %s %s %s \n",c.nom,c.prenom,c.pays,c.d.j,c.d.m,c.d.a,c.sexe,c.adresse,c.email,c.motdepasse);
 fclose(f);
 f=fopen("users.txt","a+");
 fprintf(f,"%s %s %d\n",c.email,c.motdepasse,role);
 fclose(f);
 }
}

int verifier (char login[], char password[])
{
	FILE* f;
	char nom[30];
	char motdepasse[30];
	int role;
	f=fopen("users.txt","r");
	if(f !=NULL)
	{
		while(fscanf(f,"%s %s %d\n",nom,motdepasse,&role)!=EOF)
		{
			if(strcmp(login,nom)==0)
			{
				if(strcmp(password,motdepasse)==0)
					{
						fclose(f);
						return(role);
					}
			}
		}
		fclose(f);
		return(-1);
	}
}






void supprimer(char email1[])
{
client c;
FILE *f;
FILE *tmp;
f=fopen("clients.txt","r");
tmp=fopen("tmp.txt","w");
if((f!=NULL) && (tmp!=NULL))
{
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n",c.nom,c.prenom,c.pays,&c.d.j,&c.d.m,&c.d.a,c.sexe,c.adresse,c.email,c.motdepasse)!=EOF)
{
if(strcmp(email1,c.email)!=0)
{
fprintf(tmp,"%s %s %s %d %d %d %s %s %s %s \n",c.nom,c.prenom,c.pays,c.d.j,c.d.m,c.d.a,c.sexe,c.adresse,c.email,c.motdepasse);
}
fclose(f);
fclose(tmp);
remove("clients.txt");
rename("tmp.txt","clients.txt");
}
}
}






void supprimer1(char email1[])
{
int role;
client c;
FILE *f;
FILE *tmp;
f=fopen("users.txt","r");
tmp=fopen("tmp.txt","w");
if((f!=NULL) && (tmp!=NULL))
{
while(fscanf(f,"%s %s %d\n",c.email,c.motdepasse,&role)!=EOF)
{
if(strcmp(email1,c.email)!=0)
{
fprintf(tmp,"%s %s %d\n",c.email,c.motdepasse,role);
}
fclose(f);
fclose(tmp);
remove("users.txt");
rename("tmp.txt","users.txt");
}
}
}

void reclamations_clients(char email1[])
{
client c;
FILE *f;
FILE *tmp1;
char nom[100];
char prenom[100];
char email[100];
char dat[100];
char objet1[100];
f=fopen("reclamations.txt","r");
tmp1=fopen("tmp1.txt","w");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",email,nom,prenom,dat,objet1)!=EOF)
{
if(strcmp(email1,email)==0)
{
fprintf(tmp1,"%s %s %s %s %s \n",email,nom,prenom,dat,objet1);
}


}
}
fclose(f);
fclose(tmp1);
}

