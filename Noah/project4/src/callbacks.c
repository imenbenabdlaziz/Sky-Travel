#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "reclamation.h"




void
on_nbbutton6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reclamation_client;
GtkWidget *consulter;
GtkWidget *nbtreeview2;

Reclamation_client=lookup_widget(objet,"Reclamation_client");

gtk_widget_destroy(Reclamation_client);
consulter=lookup_widget(objet,"consulter");
consulter=create_consulter();

gtk_widget_show(consulter);
nbtreeview2=lookup_widget(consulter,"nbtreeview2");
afficher_reclamation(nbtreeview2);
}


void
on_nbbutton7_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principal1, *Reclamation_client;

gtk_widget_destroy(Reclamation_client);
principal1=create_principal1();
gtk_widget_show(principal1);
}


void
on_nbbutton8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reclamation_client, *Creer;
Creer=lookup_widget(objet,"Creer");
gtk_widget_destroy(Creer);
Reclamation_client=create_Reclamation_client();
gtk_widget_show(Reclamation_client);
}


void
on_nbbutton9_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *nbcombobox1;
GtkWidget *input;
GtkWidget *Creer;
GtkWidget *output;
reclamation c ; 
char type[100];
char rec[100];
int jour,mois,annee;
char id[100];

nbcombobox1=lookup_widget(objet,"nbcombobox1");
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(nbcombobox1)));

input=lookup_widget(objet,"nbentry3");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input)));

input=lookup_widget(objet,"nbspinbutton1");
c.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
input=lookup_widget(objet,"nbspinbutton2");
c.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
input=lookup_widget(objet,"nbspinbutton3");
c.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));

input=lookup_widget(objet,"nbentry4");
strcpy(c.rec,gtk_entry_get_text(GTK_ENTRY(input)));
ajouter_reclamation(c);
output=lookup_widget(objet,"label15");
gtk_label_set_text(GTK_LABEL(output),"Reclamation est envoyée");
}


void
on_nbbutton11_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window;
window=lookup_widget(objet,"consulter");
gtk_widget_hide(window);
window=create_modifier();
gtk_widget_show(window);

}

void
on_nbbutton12_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *window;
GtkWidget *treeview;
window=lookup_widget(button,"consulter");
gtk_widget_destroy(window);
	window=create_reponse();
	gtk_widget_show(window);
	treeview=lookup_widget(window,"nbtreeview3");
	afficher_repense(treeview);
}


void
on_nbbutton4_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;
GtkWidget *input;
GtkWidget *treeview;
char cherche[20];
input=lookup_widget(button,"nbentry1");
strcpy(cherche,gtk_entry_get_text(GTK_ENTRY(input)));
reche(cherche);
	window=lookup_widget(button,"employe");
	gtk_widget_destroy(window);
	window=create_employe();
	gtk_widget_show(window);
	treeview=lookup_widget(window,"nbtreeview1");
	afficher_reche(treeview);



}

void
on_nbbutton3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
reclamation c ;
	GtkWidget *input5 ;
	GtkWidget *window1 ;
	GtkWidget *output3;
 	
    char id[50];
  window1=lookup_widget(objet,"window1");
  input5=lookup_widget(objet,"nbentry1");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input5)));
supprimer_reclamation(id);
output3=lookup_widget(objet,"label23");
gtk_label_set_text(GTK_LABEL(output3),"Reclamation est supprimée");
}


void
on_nbbutton5_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input5,*input4;
GtkWidget *window1;
GtkWidget *output1;

char id[100];
char rep[100];
window1=lookup_widget(objet,"window1");

input5=lookup_widget(objet,"nbentry1");
input4=lookup_widget(objet,"nbentry2");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(input5)));
strcpy(rep,gtk_entry_get_text(GTK_ENTRY(input4)));

ajouter_repense(id,rep);
output1=lookup_widget(objet,"label22");
gtk_label_set_text(GTK_LABEL(output1),"La repense de reclamation est envoyée");
}


void
on_nbbutton13_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *window;
window=lookup_widget(button,"modifier");
gtk_widget_hide(window);
window=create_Reclamation_client();
gtk_widget_show(window);
}


void
on_nbbutton14_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{GtkWidget *input;
GtkWidget *output;
char a[20];
reclamation c;
input = lookup_widget(button,"nbentry5");
strcpy(c.id,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(a,gtk_entry_get_text(GTK_ENTRY(input)));
input = lookup_widget(button,"nbcombobox2");
strcpy(c.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input)));

input = lookup_widget(button,"nbspinbutton4");
c.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
input = lookup_widget(button,"nbspinbutton5");
c.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
input = lookup_widget(button,"nbspinbutton6");
c.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input));
input = lookup_widget(button,"nbentry6");
strcpy(c.rec,gtk_entry_get_text(GTK_ENTRY(input)));

FILE *f;
reclamation b;
f=fopen("src/reclamation.txt","r+");
int i;
i=0;
while(fscanf(f,"%s %s %d %d %d %s \n",b.id,b.type,&b.jour,&b.mois,&b.annee,b.rec)!=EOF){
if (strcmp(b.id,c.id)==0)
	{
	supprimer_reclamation(a);	
	ajouter_reclamation(c);
	i++;
	}
}
if (i==0)
	{output=lookup_widget(button,"label29");
gtk_label_set_text(GTK_LABEL(output),"identifiant non trouver");
}
else 	{output=lookup_widget(button,"label29");
gtk_label_set_text(GTK_LABEL(output),"modification effectuer");
}
}

void
on_nbbutton15_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *window;

window=lookup_widget(button,"reponse");
gtk_widget_destroy(window);
	window=create_Reclamation_client();
	gtk_widget_show(window);
}


void
on_nbbutton20_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *Reclamation_client;
GtkWidget *Creer;

Reclamation_client=lookup_widget(objet,"Reclamation_client");

gtk_widget_destroy(Reclamation_client);
Creer=create_Creer();

gtk_widget_show(Creer);
}


void
on_nbbutton10_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)

{
GtkWidget *Reclamation_client, *consulter;


consulter=lookup_widget(objet,"consulter");
gtk_widget_destroy(consulter);
Reclamation_client=create_Reclamation_client();
gtk_widget_show(Reclamation_client);
}

void
on_nbbutton2_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principal1, *employe;

employe=lookup_widget(objet,"employe");
gtk_widget_destroy(employe);
principal1=create_principal1();
gtk_widget_show(principal1);
}


void
on_nbbutton1_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *principal1;
GtkWidget *employe;
GtkWidget *nbtreeview1;

principal1=lookup_widget(objet,"principal1");

gtk_widget_destroy(principal1);
employe=lookup_widget(objet,"employe");
employe=create_employe();

gtk_widget_show(employe);

nbtreeview1=lookup_widget(employe,"nbtreeview1");
afficher_reclamation(nbtreeview1);
}



