#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"
#include<gtk/gtkclist.h>
#include<gdk/gdkkeysyms.h>


void
on_buttoninscription_clicked           (GtkWidget       *objet,
                                        gpointer         user_data)
{
client c;
char motdepasse1[100];

GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10,*input11;
GtkWidget *windowinscription;
GtkWidget *output;
GtkWidget *output1;
GtkWidget *output2;
GtkWidget *output3;
GtkWidget *output4;
GtkWidget *output5;
char empty[]="\0";

GtkWidget *windowfelecitations;
output5=lookup_widget(objet,"erreur5");
output4=lookup_widget(objet,"erreur4");
output3=lookup_widget(objet,"erreur3");
output2=lookup_widget(objet,"erreur2");
output1=lookup_widget(objet,"erreur1");
output=lookup_widget(objet,"erreur");
input1=lookup_widget(objet,"entrynom");
input2=lookup_widget(objet,"entryprenom");
input3=lookup_widget(objet,"combobox1");
input4=lookup_widget(objet,"jour");
input5=lookup_widget(objet,"mois");
input6=lookup_widget(objet,"annee");
input7=lookup_widget(objet,"combobox2");
input8=lookup_widget(objet,"entryadresse");
input9=lookup_widget(objet,"entryemail");
input10=lookup_widget(objet,"entrymotdepasse");
input11=lookup_widget(objet,"entrymotdepasse1");
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(c.pays,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
c.d.j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
c.d.m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
c.d.a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
strcpy(c.sexe,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input7)));
strcpy(c.adresse,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(input9)));
strcpy(c.motdepasse,gtk_entry_get_text(GTK_ENTRY(input10)));
strcpy(motdepasse1,gtk_entry_get_text(GTK_ENTRY(input11)));
if(strcmp(c.nom,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output1),"Ce champ est obligatoire.");
}
else if(strcmp(c.prenom,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output2),"Ce champ est obligatoire.");
}
else if(strcmp(c.adresse,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output3),"Ce champ est obligatoire.");
}
else if(strcmp(c.email,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output4),"Ce champ est obligatoire.");
}
else if(strcmp(c.motdepasse,empty)==0)
{
gtk_label_set_text(GTK_LABEL(output5),"Ce champ est obligatoire.");
}
else if(strcmp(motdepasse1,c.motdepasse)!=0)
{
gtk_label_set_text(GTK_LABEL(output),"Les mots de passe saisis ne sont pas identiques.");
}

else
{
inscription(c);
windowinscription=lookup_widget(objet,"windowinscription");

gtk_widget_destroy(windowinscription);
windowfelecitations=create_windowfelecitations();
gtk_widget_show(windowfelecitations);
}

}


void
on_buttonretour_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowacceuil, *windowinscription;
windowinscription=lookup_widget(objet,"windowinscription");

gtk_widget_destroy(windowinscription);
windowacceuil=create_windowacceuil();
gtk_widget_show(windowacceuil);
}



void
on_buttoninscription1_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowacceuil, *windowinscription;
windowacceuil=lookup_widget(objet,"windowacceuil");

gtk_widget_destroy(windowacceuil);
windowinscription=create_windowinscription();
gtk_widget_show(windowinscription);
}


void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *windowacceuil;
window1=lookup_widget(objet,"window1");

gtk_widget_destroy(window1);
windowacceuil=create_windowacceuil();
gtk_widget_show(windowacceuil);
}


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{

GtkWidget *window1;
GtkWidget *windowacceuil;
windowacceuil=lookup_widget(objet,"windowacceuil");

gtk_widget_destroy(windowacceuil);
window1=create_window1();
gtk_widget_show(window1);

}






void
on_button6_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{


GtkWidget *window1;
GtkWidget *windowfelecitations;
GtkWidget *windowinscription;

windowfelecitations=lookup_widget(objet,"windowfelecitations");
windowinscription=lookup_widget(objet,"windowinscription");
gtk_widget_destroy(windowfelecitations);

gtk_widget_destroy(windowinscription);
window1=create_window1();
gtk_widget_show(window1);

}












void
on_meconnecter_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *window1;
GtkWidget *windowespaceclient;
GtkWidget *input1;
GtkWidget *input2;
GtkWidget *output,*output2,*output3,*output4,*output5,*output6,*output7,*output8,*output9,*output10,*output11;
GtkWidget *treeview1201;
char id[100];
char mdp[100];


int x;
char nom[100];
char prenom[100];
char date[100];
char mail[100];
int jour;
int annee;
int mois;
char pays[100];
char sexe[100];
char adresse[100];
char motdepasse[100];
FILE *f;
FILE *tmp2;
input1=lookup_widget(objet,"entrylogin");
input2=lookup_widget(objet,"entrypassword");
output=lookup_widget(objet,"label25");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(mdp,gtk_entry_get_text(GTK_ENTRY(input2)));
x=verifier(id,mdp);
if (x!=-1)
{
window1=lookup_widget(objet,"window1");
gtk_widget_destroy(window1);
windowespaceclient=create_windowespaceclient();
gtk_widget_show(windowespaceclient);
reclamations_clients(id);
treeview1201=lookup_widget(windowespaceclient,"treeview1201");
afficher_reclamations(treeview1201);


output2=lookup_widget(windowespaceclient,"nomsb");
output3=lookup_widget(windowespaceclient,"prenomsb");
output4=lookup_widget(windowespaceclient,"label542");
output5=lookup_widget(windowespaceclient,"joursb");
output6=lookup_widget(windowespaceclient,"moissb");
output7=lookup_widget(windowespaceclient,"anneesb");
output8=lookup_widget(windowespaceclient,"adressesb");
output9=lookup_widget(windowespaceclient,"payssb");
output10=lookup_widget(windowespaceclient,"motdepassesb");
output11=lookup_widget(windowespaceclient,"sexesb");

f=fopen("/home/bacem/Projects/project31/src/clients.txt","r");
tmp2=fopen("/home/bacem/Projects/project31/src/tmp2.txt","w");

if(f!=NULL)
{
while(fscanf(f,"%s %s %s %d %d %d %s %s %s %s \n",nom,prenom,pays,&jour,&mois,&annee,sexe,adresse,mail,motdepasse)!=EOF)
{
if(strcmp(id,mail)==0)
{
fprintf(tmp2,"%s %s %s %d %d %d %s %s %s %s \n",nom,prenom,pays,jour,mois,annee,sexe,adresse,mail,motdepasse);

gtk_label_set_text(GTK_LABEL(output4),mail);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5),jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6),mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7),annee);
gtk_entry_set_text (GTK_ENTRY (output2),nom);
gtk_entry_set_text (GTK_ENTRY (output3),prenom);
gtk_entry_set_text (GTK_ENTRY (output8),adresse);
gtk_entry_set_text (GTK_ENTRY (output9),pays);
gtk_entry_set_text (GTK_ENTRY (output10),motdepasse);
gtk_entry_set_text (GTK_ENTRY (output11),sexe);


}



}
}
fclose(f);
fclose(tmp2);
}



else
{
gtk_label_set_text(GTK_LABEL(output),"nom d'utilisateur ou mot de passe invalides veuillez reassayer de vous connecter");
}

}


void
on_deconnexion_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowespaceclient;
GtkWidget *windowacceuil;
windowespaceclient=lookup_widget(objet,"windowespaceclient");

gtk_widget_destroy(windowespaceclient);
windowacceuil=create_windowacceuil();
gtk_widget_show(windowacceuil);
}








void
on_buttonsupprimer_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowespaceclient;
GtkWidget *windowdesactivercompte;
windowespaceclient=lookup_widget(objet,"windowespaceclient");

gtk_widget_destroy(windowespaceclient);
windowdesactivercompte=create_windowdesactivercompte();
gtk_widget_show(windowdesactivercompte);

}





void
on_button8_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *treeview1201;
GtkWidget *windowespaceclient;
GtkWidget *windowdesactivercompte;
windowdesactivercompte=lookup_widget(objet,"windowdesactivercompte");
GtkWidget *output2,*output3,*output4,*output5,*output6,*output7,*output8,*output9,*output10,*output11;

char nom[100];
char prenom[100];
char date[100];
char mail[100];
int jour;
int annee;
int mois;
char pays[100];
char sexe[100];
char adresse[100];
char motdepasse[100];
FILE*tmp2;

gtk_widget_destroy(windowdesactivercompte);
windowespaceclient=create_windowespaceclient();
gtk_widget_show(windowespaceclient);
treeview1201=lookup_widget(windowespaceclient,"treeview1201");
afficher_reclamations(treeview1201);
output2=lookup_widget(windowespaceclient,"nomsb");
output3=lookup_widget(windowespaceclient,"prenomsb");
output4=lookup_widget(windowespaceclient,"label542");
output5=lookup_widget(windowespaceclient,"joursb");
output6=lookup_widget(windowespaceclient,"moissb");
output7=lookup_widget(windowespaceclient,"anneesb");
output8=lookup_widget(windowespaceclient,"adressesb");
output9=lookup_widget(windowespaceclient,"payssb");
output10=lookup_widget(windowespaceclient,"motdepassesb");
output11=lookup_widget(windowespaceclient,"sexesb");

tmp2=fopen("/home/bacem/Projects/project31/src/tmp2.txt","r");
if(tmp2!=NULL)
{

while(fscanf(tmp2,"%s %s %s %d %d %d %s %s %s %s \n",nom,prenom,pays,&jour,&mois,&annee,sexe,adresse,mail,motdepasse)!=EOF)
{
gtk_label_set_text(GTK_LABEL(output4),mail);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output5),jour);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output6),mois);
gtk_spin_button_set_value(GTK_SPIN_BUTTON(output7),annee);
gtk_entry_set_text (GTK_ENTRY (output2),nom);
gtk_entry_set_text (GTK_ENTRY (output3),prenom);
gtk_entry_set_text (GTK_ENTRY (output8),adresse);
gtk_entry_set_text (GTK_ENTRY (output9),pays);
gtk_entry_set_text (GTK_ENTRY (output10),motdepasse);
gtk_entry_set_text (GTK_ENTRY (output11),sexe);
}
}

fclose(tmp2);

//desactiver compte vers espace client
}


void
on_buttondesactivercompte1_clicked     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *windowdesactivercompte;
GtkWidget *windowacceuil;
GtkWidget *input;
GtkWidget *input1;
GtkWidget *output;
char email1[100];
char motdepasse1[100];
int y;
client c;
input=lookup_widget(objet,"entryemail1");
input1=lookup_widget(objet,"entrymotdepasse1");
output=lookup_widget(objet,"label500");
strcpy(email1,gtk_entry_get_text(GTK_ENTRY(input)));
strcpy(motdepasse1,gtk_entry_get_text(GTK_ENTRY(input1)));
y=verifier(email1,motdepasse1);
if(y!=-1)
{
supprimer(email1);
supprimer1(email1);
windowdesactivercompte=lookup_widget(objet,"windowdesactivercompte");

gtk_widget_destroy(windowdesactivercompte);
windowacceuil=create_windowacceuil();
gtk_widget_show(windowacceuil);
}
else
{
gtk_label_set_text(GTK_LABEL(output),"Email ou mot de passe invalide.");
}

}


void
on_updatesb_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9;
GtkWidget *output;
char nom[100];
char prenom[1000];
char sexe[100];
int j;
int m;
int a;
char pays[100];
char adresse[100];
char email[100];
char motdepasse[100];
char nom1[100];
char prenom1[1000];
char sexe1[100];
int j1;
int m1;
int a1;
char pays1[100];
char adresse1[100];
char email1[100];
char motdepasse1[100];
FILE*tmp2;
input1=lookup_widget(objet,"nomsb");
input2=lookup_widget(objet,"prenomsb");
input3=lookup_widget(objet,"joursb");
input4=lookup_widget(objet,"moissb");
input5=lookup_widget(objet,"anneesb");
input6=lookup_widget(objet,"sexesb");
input7=lookup_widget(objet,"payssb");
input8=lookup_widget(objet,"adressesb");
input9=lookup_widget(objet,"motdepassesb");
output=lookup_widget(objet,"sblabel");

strcpy(nom,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(prenom,gtk_entry_get_text(GTK_ENTRY(input2)));
j=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
m=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
a=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
strcpy(sexe,gtk_entry_get_text(GTK_ENTRY(input6)));
strcpy(pays,gtk_entry_get_text(GTK_ENTRY(input7)));
strcpy(adresse,gtk_entry_get_text(GTK_ENTRY(input8)));
strcpy(motdepasse,gtk_entry_get_text(GTK_ENTRY(input9)));

tmp2=fopen("/home/bacem/Projects/project31/src/tmp2.txt","r");
if(tmp2!=NULL)
{
while(fscanf(tmp2,"%s %s %s %d %d %d %s %s %s %s \n",nom1,prenom1,pays1,&j1,&m1,&a1,sexe1,adresse1,email1,motdepasse1)!=EOF)
{ strcpy(email,email1);


modifier_clients(nom,prenom,sexe,j,m,a,pays,adresse,email,motdepasse);
modifier_users(email,motdepasse);
gtk_label_set_text(GTK_LABEL(output),"Votre profil est mis à jour.");


}
}
fclose(tmp2);
}


















