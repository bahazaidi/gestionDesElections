/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *signUp;
  GtkWidget *dashboard;
  GtkWidget *creation_election;
  GtkWidget *nouvelle_election;
  GtkWidget *supprimer_election;
  GtkWidget *modifier_election;
  GtkWidget *Gestion_de_reclamation;
  GtkWidget *Ajouter_reclamation;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory (PACKAGE_DATA_DIR "/" PACKAGE "/pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  signUp = create_signUp ();
  gtk_widget_show (signUp);
  dashboard = create_dashboard ();
  gtk_widget_show (dashboard);
  creation_election = create_creation_election ();
  gtk_widget_show (creation_election);
  nouvelle_election = create_nouvelle_election ();
  gtk_widget_show (nouvelle_election);
  supprimer_election = create_supprimer_election ();
  gtk_widget_show (supprimer_election);
  modifier_election = create_modifier_election ();
  gtk_widget_show (modifier_election);
  Gestion_de_reclamation = create_Gestion_de_reclamation ();
  gtk_widget_show (Gestion_de_reclamation);
  Ajouter_reclamation = create_Ajouter_reclamation ();
  gtk_widget_show (Ajouter_reclamation);

  gtk_main ();
  return 0;
}
