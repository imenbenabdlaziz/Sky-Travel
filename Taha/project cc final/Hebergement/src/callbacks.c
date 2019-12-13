#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <gtk/gtkclist.h>
#include <gdk/gdkkeysyms.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"


void
on_ajouterh_clicked               (GtkWidget       *objet,
                                   gpointer   user_data)
{
heberg h;
GtkWidget *spinbutton1;
GtkWidget *etoiles;
GtkWidget *input1,*combobox3,*input3,*combobox2,*combobox1,*input6;
GtkWidget *hebergement1;
GtkWidget *input0;

GtkWidget *output,*output2,*output3,*output10;
char empty[]="\0";
output=lookup_widget(objet,"erreur");
output2=lookup_widget(objet,"erreur2");
output3=lookup_widget(objet,"erreur3");
output10=lookup_widget(objet,"label46");


hebergement1=lookup_widget(objet,"hebergement1");
input1=lookup_widget(objet,"identier");
combobox3=lookup_widget(objet,"combobox3");
input0=lookup_widget(objet,"spinbutton1");
h.etoiles=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (spinbutton1));
input3=lookup_widget(objet,"prixnuitee");
combobox2=lookup_widget(objet,"combobox2");
combobox1=lookup_widget(objet,"combobox1");
input6=lookup_widget(objet,"type_pension");

strcpy(h.identier,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(h.ville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));
h.etoiles=gtk_spin_button_get_value_as_int(GTK_ENTRY(input0));
strcpy(h.prixnuitee,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(h.chambres,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
strcpy(h.nom_hotel,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(h.type_pension,gtk_entry_get_text(GTK_ENTRY(input6)));
if(strcmp(h.identier,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output),"Ce champ est obligatoire");

}

else if(strcmp(h.prixnuitee,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output2),"Ce champ est obligatoire");

}
else if(strcmp(h.type_pension,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output3),"Ce champ est obligatoire");

}

else
{
ajouter_heberg(h);

gtk_label_set_text(GTK_LABEL(output10),"Ajout effectué avec succés..");
}

}







void
on_afficherh_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *hebergement1;
GtkWidget *treeview1h;


hebergement1=lookup_widget(objet,"hebergement1");


treeview1h=lookup_widget(hebergement1,"treeview1h");

afficher_heberg(treeview1h);
}






void
on_retourh_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *hebergement1;

hebergement1=lookup_widget(objet,"hebergement1");

gtk_widget_destroy(hebergement1);
hebergement1=create_hebergement1();
gtk_widget_show(hebergement1);


}






void
on_supprimerh_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *hebergement1;
GtkWidget *supprimer1;
GtkWidget *output3;
char identier1[2000];
GtkWidget *input7;
input7=lookup_widget(objet,"identier1");
output3=lookup_widget(objet,"label47");
strcpy(identier1,gtk_entry_get_text(GTK_ENTRY(input7)));
supprimer_heberg(identier1);
gtk_label_set_text(GTK_LABEL(output3),"La supression s'est effectuée avec succes.");
}


void
on_modifierh_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
char identier1[3000];
GtkWidget *modifierheb;
modifierheb= create_modifierheb();
gtk_widget_show(modifierheb);

}


void
on_modifierf_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
char identier1[3000];
heberg h1;
GtkWidget *modspinbutton;
GtkWidget *etoiles;
GtkWidget *input1,*combobox3,*input3,*combobox2,*combobox1,*input6;

GtkWidget *input0;
GtkWidget *modcombobox;
GtkWidget *modcomboboxh;
GtkWidget *modcomboboxa;
GtkWidget *modifiers;
GtkWidget *output70;



input1=lookup_widget(objet,"modidentier");
combobox3=lookup_widget(objet,"modcomboboxa");
input0=lookup_widget(objet,"modspinbutton");
h1.etoiles=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON (modspinbutton));
input3=lookup_widget(objet,"modprix");
combobox2=lookup_widget(objet,"modcombobox");
combobox1=lookup_widget(objet,"modcomboboxh");
input6=lookup_widget(objet,"modpension");
output70=lookup_widget(objet,"label48");

strcpy(h1.identier,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(h1.ville,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox3)));
h1.etoiles=gtk_spin_button_get_value_as_int(GTK_ENTRY(input0));
strcpy(h1.prixnuitee,gtk_entry_get_text(GTK_ENTRY(input3)));
strcpy(h1.chambres,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox2)));
strcpy(h1.nom_hotel,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox1)));
strcpy(h1.type_pension,gtk_entry_get_text(GTK_ENTRY(input6)));
modifier_heberg(h1);
gtk_label_set_text(GTK_LABEL(output70),"Votre hotel est mis à jour.");



}


void
on_validerh_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

heberg h;
GtkWidget *input1,*output1,*output4,*output6;
GtkWidget *modifier;
char ididentier[33];
char modprix[300];
char modpension[300];


output1=lookup_widget(objet,"modidentier");
output4=lookup_widget(objet,"modprix");
output6=lookup_widget(objet,"modpension");
input1=lookup_widget(objet,"ididentier");
strcpy(ididentier,gtk_entry_get_text(GTK_ENTRY(input1)));
FILE *f;
	f=fopen("utilisateur.txt","r");
	if(f!=NULL)
{
while(fscanf(f,"%s %s  %d %s %s %s %s \n",h.identier,h.ville,&h.etoiles,h.prixnuitee,h.chambres,h.nom_hotel,h.type_pension)!=EOF)
{
	if (strcmp(h.identier,ididentier)==0)
{
gtk_entry_set_text (GTK_ENTRY (output1),h.identier);
gtk_entry_set_text (GTK_ENTRY (output4),h.prixnuitee);
gtk_entry_set_text (GTK_ENTRY (output6),h.type_pension);

}
}
}





}


void
on_refresh1_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *hebergement1;
GtkWidget *treeview1h;

hebergement1=lookup_widget(objet,"hebergement1");

gtk_widget_destroy(hebergement1);
hebergement1=create_hebergement1();
gtk_widget_show(hebergement1);

treeview1h=lookup_widget(hebergement1,"treeview1h");

afficher_heberg(treeview1h);
}


void
on_deconnexiontaha_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{

}





void
on_reclamationtaha_clicked             (GtkWidget      *objet,
                                        gpointer         user_data)
{

}

