#include <gtk/gtk.h>

typedef struct
{  
	char id[50]; 
	char depart[20];
	char arriver[50] ; 
	int jour; 
	int mois;
	int annee;
	char duree[50] ; 
	char prix[50] ; 
	char nbrvoyageur[50] ;
	char classe[50] ;
}vol;


void ajouter(vol p);
/*void afficher(GtkWidget *plistview);*/
void afficher(GtkWidget *liste);
void modifier(char id[],char depart[], char arriver[],int jour,int mois,int annee,char duree[],char prix[],char nbrvoyageur[], char classe[]);
void supprimer(char id[]); 
 
