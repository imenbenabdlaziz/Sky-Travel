#ifndef EMPLOYERS_H_INCLUDED
#define EMPLOYERS_H_INCLUDED
#include <gtk/gtk.h>


void
on_annuler_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_connexion_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_inscription_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_clicked                      (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_retour_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);




void
on_supprimer_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_modifier_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_modifierr_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_valider_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_debut_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_confirmer_clicked                   (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_sortie_clicked                      (GtkWidget       *objet,
                                        gpointer         user_data);

#endif



