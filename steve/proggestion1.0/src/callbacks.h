#include <gtk/gtk.h>



void
on_buttonreservationvol_clicked(GtkWidget *objet,gpointer user_data);

void
on_buttonafficherreservation_clicked (GtkWidget *objet,gpointer user_data);

void
on_buttonreservationhotel_clicked   (GtkWidget *objet,gpointer user_data);

void
on_retourv_clicked(GtkWidget *objet,gpointer user_data);

void
on_rechercherv_clicked(GtkWidget *objet,gpointer user_data);

void
on_reserverv_clicked(GtkWidget *objet,gpointer user_data);

void
on_buttonreserverh_clicked(GtkWidget *objet,gpointer user_data);

void
on_buttonrechercherh_clicked(GtkWidget *objet,gpointer user_data);

void
on_buttonretourh_clicked(GtkWidget *objet,gpointer user_data);

void
view_onRowActivated (GtkWidget *objet,gpointer user_data);

void
on_buttonupdateresev_clicked(GtkWidget *objet,gpointer user_data);

void
on_buttonretourr_clicked(GtkWidget *objet,gpointer user_data);

void
on_buttonsupprimerreserv_clicked(GtkWidget *objet,gpointer user_data);

void
on_buttonpayer_clicked(GtkWidget *objet,gpointer user_data);

void
on_buttonaffichemesresev_clicked (GtkWidget *objet,gpointer user_data);

void view_onRowActivated_resv(GtkWidget *objet,gpointer user_data);

void
on_reservationhotel_destroy(GtkWidget *objet,gpointer user_data);

void
on_choixreservation_destroy(GtkWidget *objet,gpointer user_data);

void
on_reservationvol_destroy(GtkWidget *objet,gpointer user_data);

void
on_mesreservations_destroy(GtkWidget *objet,gpointer user_data);


void
on_windowsuppresion_destroy(GtkWidget *objet,gpointer user_data);

void
on_buttonconfsup_clicked(GtkWidget *objet,gpointer user_data);

void
on_buttonmodifierannuler_clicked(GtkWidget *objet,gpointer user_data);

void
on_buttonmodifieconf_clicked(GtkWidget *objet,gpointer user_data);

//calender
void
on_buttonconfirmerpayement_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonretourpayement_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_calendarreservation1_day_selected(GtkWidget *objet,gpointer user_data);

void
on_calendarreservation2_day_selected(GtkWidget *objet,gpointer user_data);
