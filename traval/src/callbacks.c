#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "gest.h"

void
on_button1n_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutervol;
GtkWidget *gestionvol;
ajoutervol= create_ajoutervol();
gtk_widget_show (ajoutervol);
gestionvol= lookup_widget(objet_graphique,"gestionvol");
gtk_widget_hide(gestionvol);

}


void
on_button2n_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *ajoutervol;
GtkWidget *gestionvol;
ajoutervol= create_ajoutervol();
gtk_widget_show (ajoutervol);
gestionvol= lookup_widget(objet_graphique,"gestionvol");
gtk_widget_hide(gestionvol);
}


void
on_button3n_clicked                    (GtkWidget      *objet_graphique,
                                        gpointer         user_data)
{
gtk_main_quit();
}


void
on_button4_clicked                     (GtkWidget        *objet_graphique,
                                        gpointer         user_data)
{
	vol p;
	
	GtkWidget *input1,*input2,*input3,*input4,*input5,*input6,*input7,*input8,*input9,*input10;
	GtkWidget *ajoutervol;

	ajoutervol=lookup_widget(objet_graphique,"ajoutervol");
	
	input1=lookup_widget(objet_graphique,"entry7");
	input2=lookup_widget(objet_graphique,"entry1");
	input3=lookup_widget(objet_graphique,"entry2");
	input4=lookup_widget(objet_graphique,"entry3");
	input5=lookup_widget(objet_graphique,"entry4");
	input6=lookup_widget(objet_graphique,"entry5");
	
	GtkWidget *spinbutton1;
	GtkWidget *spinbutton2;
	GtkWidget *spinbutton3;
	GtkWidget *combobox1;
	
	

	spinbutton1=lookup_widget(objet_graphique, "spinbutton1");
	spinbutton2=lookup_widget(objet_graphique, "spinbutton2");
	spinbutton3=lookup_widget(objet_graphique, "spinbutton3");
	combobox1=lookup_widget(objet_graphique, "combobox1");

        p.jour=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton1));
	p.mois=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton2));
	p.annee=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON(spinbutton3));
	
	strcpy(p.classe,gtk_combo_box_get_active_text (GTK_COMBO_BOX(combobox1)));
	/*p.jour=JJ;
	p.mois=MM;
	p.annee=AA;*/

	strcpy(p.id,gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(p.depart,gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(p.arriver,gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(p.duree,gtk_entry_get_text(GTK_ENTRY(input4)));
	strcpy(p.nbrvoyageur,gtk_entry_get_text(GTK_ENTRY(input5)));
	strcpy(p.prix,gtk_entry_get_text(GTK_ENTRY(input6)));
	ajouter(p);
     
}



void
on_treeview1_row_activated             (GtkWidget     *objet_graphique,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *idn ,*departn,*arrivern,*journ,*moisn,*anneen,*dureen,*nbrvoyageurn,*prixn,*classen,*modifvol,*gestionvol,*treeview;
char *id,*depart,*arriver,*duree,*nbrvoyageur,*prix,*classe;
int *jour,*mois,*annee;
	modifvol=create_modifvol();
	treeview=lookup_widget(objet_graphique,"treeview1");
	gestionvol=lookup_widget(objet_graphique,"gestionvol");
	idn=lookup_widget(modifvol,"entry14");
	departn=lookup_widget(modifvol,"entry8");
	arrivern=lookup_widget(modifvol,"entry9");
	dureen=lookup_widget(modifvol,"entry10");
	nbrvoyageurn=lookup_widget(modifvol,"entry13");
	prixn=lookup_widget(modifvol,"entry11");

	

	journ=lookup_widget(modifvol,"spinbutton4");
	moisn=lookup_widget(modifvol,"spinbutton5");
 	anneen=lookup_widget(modifvol,"spinbutton6");
	classen=lookup_widget(modifvol,"combobox2");
	
	
	GtkTreeIter iter;
	GtkTreeModel *model=gtk_tree_view_get_model (GTK_TREE_VIEW(treeview));
	gtk_tree_model_get_iter(model,&iter,path);
	gtk_tree_model_get (model,&iter,0,&id,1,&depart,2,&arriver,3,&jour,4,&mois,5,&annee,6,&duree,7,&nbrvoyageur,8,&prix,9,&classe,-1);
	printf("%s %s %s %d %d %d %s %s %s %s",id,depart,arriver,&jour,&mois,&annee,duree,nbrvoyageur,prix,classe);
	gtk_entry_set_text(GTK_ENTRY (idn),_(id));
	gtk_entry_set_text(GTK_ENTRY (departn),_(depart));
        gtk_entry_set_text(GTK_ENTRY (arrivern),_(arriver));
	 gtk_entry_set_text(GTK_ENTRY (dureen),_(duree));
	 gtk_entry_set_text(GTK_ENTRY (nbrvoyageurn),_(nbrvoyageur));
	 gtk_entry_set_text(GTK_ENTRY (prixn),_(prix));
	 gtk_combo_box_append_text(GTK_COMBO_BOX (classen),_(classe));
	/*gtk_spin_button_set_value_as_int(GTK_SPIN_BUTTON(journ),jour);
	gtk_spin_button_set_value_as_int(GTK_SPIN_BUTTON (moisn),mois);
	gtk_spin_button_set_value_as_int(GTK_SPIN_BUTTON (anneen),annee);
*/
	gtk_widget_hide(gestionvol);
	gtk_widget_show(modifvol);
}


void
on_button5_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id,*depart,*arriver,*jour,*mois,*annee,*duree,*current,*nbrvoyageur,*prix,*classe,*gestionvol,*modifvol,*List_View;
	gchar idk[20],departk[20],arriverk[20],dureek[20],nbrvoyageurk[20],prixk[20],classek[20];
	gint jourk,moisk,anneek;

	modifvol=lookup_widget(objet_graphique,"modifvol");
	id=lookup_widget(objet_graphique,"entry14");
	depart=lookup_widget(objet_graphique,"entry8");
	arriver=lookup_widget(objet_graphique,"entry9");
	duree=lookup_widget(objet_graphique,"entry10");
	nbrvoyageur=lookup_widget(objet_graphique,"entry13");
	prix=lookup_widget(objet_graphique,"entry11");

	
	jour=lookup_widget(objet_graphique,"spinbutton4");
	mois=lookup_widget(objet_graphique,"spinbutton5");
	annee=lookup_widget(objet_graphique,"spinbutton6");
	
	classe=lookup_widget(objet_graphique,"combobox2");
	strcpy(idk,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(departk,gtk_entry_get_text(GTK_ENTRY(depart)));
	strcpy(arriverk,gtk_entry_get_text(GTK_ENTRY(arriver)));
	strcpy(dureek,gtk_entry_get_text(GTK_ENTRY(duree)));
	strcpy(nbrvoyageurk,gtk_entry_get_text(GTK_ENTRY(nbrvoyageur)));
	strcpy(prixk,gtk_entry_get_text(GTK_ENTRY(prix)));
	jourk=gtk_spin_button_get_value_as_int(jour);
	moisk=gtk_spin_button_get_value_as_int(mois);
	anneek=gtk_spin_button_get_value_as_int(annee);
	strcpy(classek,gtk_combo_box_get_active_text(GTK_COMBO_BOX(classe)));
	
	modifier(idk,departk,arriverk,jourk,moisk,anneek,dureek,nbrvoyageurk,prixk,classek);
	gestionvol=create_gestionvol();
	gtk_widget_show (gestionvol);
	current=lookup_widget(objet_graphique,"modifvol");
	gtk_widget_hide(current);
	List_View=lookup_widget(gestionvol,"treeview1");
	afficher(List_View);
}


void
on_button6_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *id,*depart,*arriver,*jour,*mois,*annee,*duree,*current,*nbrvoyageur,*prix,*classe,*gestionvol,*modifvol,*List_View;
	gchar idk[20],departk[20],arriverk[20],dureek[20],nbrvoyageurk[20],prixk[20],classek[20];
	gint jourk,moisk,anneek;

	
	id=lookup_widget(objet_graphique,"entry14");
	depart=lookup_widget(objet_graphique,"entry8");
	arriver=lookup_widget(objet_graphique,"entry9");
	duree=lookup_widget(objet_graphique,"entry10");
	nbrvoyageur=lookup_widget(objet_graphique,"entry13");
	prix=lookup_widget(objet_graphique,"entry11");

	
	jour=lookup_widget(objet_graphique,"spinbutton4");
	mois=lookup_widget(objet_graphique,"spinbutton5");
	annee=lookup_widget(objet_graphique,"spinbutton6");
	
	classe=lookup_widget(objet_graphique,"combobox2");
	strcpy(idk,gtk_entry_get_text(GTK_ENTRY(id)));
	strcpy(departk,gtk_entry_get_text(GTK_ENTRY(depart)));
	strcpy(arriverk,gtk_entry_get_text(GTK_ENTRY(arriver)));
	strcpy(dureek,gtk_entry_get_text(GTK_ENTRY(duree)));
	strcpy(nbrvoyageurk,gtk_entry_get_text(GTK_ENTRY(nbrvoyageur)));
	strcpy(prixk,gtk_entry_get_text(GTK_ENTRY(prix)));
	jourk=gtk_spin_button_get_value_as_int(jour);
	moisk=gtk_spin_button_get_value_as_int(mois);
	anneek=gtk_spin_button_get_value_as_int(annee);
	strcpy(classek,gtk_combo_box_get_active_text(GTK_COMBO_BOX(classe)));
	
	supprimer(idk);
	gestionvol=create_gestionvol();
	gtk_widget_show (gestionvol);
	current=lookup_widget(objet_graphique,"modifvol");
	gtk_widget_hide(current);
	List_View=lookup_widget(gestionvol,"treeview1");
	afficher(List_View);
}




void
on_button7_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

	GtkWidget *ajoutervol;
	GtkWidget *gestionvol;
	GtkWidget *treeview1;

	ajoutervol=lookup_widget(objet_graphique, "ajoutervol");

	gtk_widget_hide(ajoutervol);
	
	gestionvol=create_gestionvol();

	gtk_widget_show_all(gestionvol);

	treeview1=lookup_widget(gestionvol,"treeview1");
	afficher(treeview1);
}


void
on_buttonreclamationimen_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

}



