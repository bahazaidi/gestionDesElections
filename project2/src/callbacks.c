#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "utilisateur.h"
#include "election.h"
#include <string.h>
int x=2;
utilisateurs t;
void
on_button_anl1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *signUp;
  GtkWidget *dashboard;
signUp=lookup_widget(GTK_WIDGET(button),"signUp"); // search for the action of the button 
gtk_widget_destroy(signUp);
dashboard=create_dashboard();
gtk_widget_show (dashboard);
}


void
on_button_eng1_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *signUp;
  GtkWidget *dashboard;
GtkWidget*nom;
GtkWidget*prenom;
GtkWidget*sexe;
GtkWidget*numDeTel;
GtkWidget*mdp;
GtkWidget*age;
GtkWidget*confmdp;
GtkWidget*region;
GtkWidget*cin;
GtkWidget*role;
nom=lookup_widget(button,"entry_nom");
prenom=lookup_widget(button,"entry_prenom");

numDeTel=lookup_widget(button,"entry_numTel");
mdp=lookup_widget(button,"entry_mdp");
confmdp=lookup_widget(button,"entry_confmdp");
region=lookup_widget(button,"entry_region");
cin=lookup_widget(button,"entry_cin");
role=lookup_widget(button,"entry_role");
age=lookup_widget(button,"entry_age");
utilisateurs u;

strcpy(u.nom,gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(u.prenom,gtk_entry_get_text(GTK_ENTRY(prenom)));
u.numtel=atoi(gtk_entry_get_text(GTK_ENTRY(numDeTel)));
strcpy(u.mdp,gtk_entry_get_text(GTK_ENTRY(mdp)));
u.cin=atoi(gtk_entry_get_text(GTK_ENTRY(cin)));

strcpy(u.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
strcpy(u.region,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));
u.age=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(age));

if(x==1)
{strcpy(u.sexe,"Femelle");}
else if(x==2)
{strcpy(u.sexe,"Male");}


ajouter(u);
}


void
on_modifier_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard_modif;
GtkWidget *dashboard; 
GtkWidget *output1;
GtkWidget *output2;
char nom[10]="test";
char prenom[10]="test";
utilisateurs p;
dashboard=lookup_widget(GTK_WIDGET(button),"dashboard"); // search for the action of the button 
//gtk_widget_destroy(dashboard);
dashboard_modif=create_dashboard_modif();
gtk_widget_show (dashboard_modif);
output1=lookup_widget(dashboard_modif,"modif_nom");
output2=lookup_widget(dashboard_modif,"modif_prenom");
long val=123;
p=chercher("utilisateur.txt", val);
gtk_entry_set_text(output1,p.nom);
gtk_entry_set_text(output2,p.prenom);


}


void
on_supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_afficher_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
GtkWidget *dashboard_affiche;
dashboard=lookup_widget(GTK_WIDGET(button),"dashboard");
gtk_widget_destroy(dashboard);
dashboard_affiche=create_dashboard_affiche();
gtk_widget_show (dashboard_affiche);
}


void
on_prec_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *signUp;
  GtkWidget *dashboard;
dashboard=lookup_widget(GTK_WIDGET(button),"dashboard");
gtk_widget_destroy(dashboard);
signUp=create_signUp ();
gtk_widget_show (signUp);



}


void
on_ajouter_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *signUp;
GtkWidget *dashboard;
dashboard=lookup_widget(GTK_WIDGET(button),"dashboard");
gtk_widget_destroy(dashboard);
signUp = create_signUp ();
 gtk_widget_show (signUp);
}


void on_ajouter_election_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *nouvelle_election;
  GtkWidget *creation_election;
creation_election=lookup_widget(GTK_WIDGET(button),"creation_election"); // search for the action of the button 
gtk_widget_destroy(creation_election);
nouvelle_election=create_nouvelle_election ();
gtk_widget_show (nouvelle_election);
}



void on_modifier_election_clicked (GtkWidget *button, gpointer user_data)
{
	GtkWidget *creation_election;
	GtkWidget *modifier_election;	
creation_election=lookup_widget(GTK_WIDGET(button),"creation_election"); // search for the action of the button 
gtk_widget_destroy(creation_election);
modifier_election=create_modifier_election();
gtk_widget_show (modifier_election);
}

void
on_supprimer_election_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_enregistrer3_clicked         (GtkWidget       *button,
                                        gpointer         user_data)
{
  GtkWidget *nouvelle_election;
  GtkWidget *creation_election;
GtkWidget*input1;
GtkWidget*input2;
GtkWidget*input3;
GtkWidget*input4;
GtkWidget*input5;
input1=lookup_widget(button,"entry_id");
input2=lookup_widget(button,"entry_date_election");
input3=lookup_widget(button,"spinbutton_nbc");
input4=lookup_widget(button,"entry_municipalite2");
input5=lookup_widget(button,"spinbutton_nbh");
election e;
e.id=atoi(gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(e.date,gtk_entry_get_text(GTK_ENTRY(input2)));
strcpy(e.municipalite,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input4)));
e.nbh=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
e.nbc=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input3));
ajouter1("election.txt",e);

nouvelle_election=lookup_widget(GTK_WIDGET(button),"nouvelle_election"); // search for the action of the button 
gtk_widget_destroy(nouvelle_election);
creation_election=create_creation_election();
gtk_widget_show (creation_election);
  



}
/*
GtkWidget *nom, *prenom, *cin, *tel, *mdp, *cmdp;
GtkWidget *signUp, *age, *role, *region;
GtkWidget *sexe;
GtkWidget *label1;
GtkWidget *existe; 

int a=1;
signUp=lookup_widget(GTK_WIDGET(button),"signUp");
//label=lookup_widget(Ajoutertroupeau,"labelremplir");
//label1=lookup_widget(Ajoutertroupeau,"labelconfirm");
//existe=lookup_widget(Ajoutertroupeau,"labelexiste");

age=lookup_widget(GTK_WIDGET(button),"entry_age");
cin=lookup_widget(GTK_WIDGET(button),"entry_cin");
nom=lookup_widget(GTK_WIDGET(button),"entry_nom");
prenom=Lookup_widget(GTK_WIDGET(button),"entry_prenom");
role=lookup_widget(GTK_WIDGET(button),"entry_role");
region=lookup_widget(GTK_WIDGET(button),"entry_region");

if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(role))==NULL)
{strcpy(t.role,"");}
else
{strcpy(t.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));}

if(gtk_combo_box_get_active_text(GTK_COMBO_BOX(region))==NULL)
{strcpy(t.region,"");}
else
{strcpy(t.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(region)));}




t.age = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(age));
if(x==1)
{strcpy(t.sexe,"Femelle");}
else if(x==2)
{strcpy(t.sexe,"Male");}

if(strcmp(t.type,"")==0 || strcmp(t.id,"")==0)
{
        gtk_widget_show(label);
        a=0;
}
/*else 
        {gtk_widget_hide(label);}
if(a==1 && exist_tr(t.id)==1)
        { gtk_widget_show (existe); }
if(a==1 && y!=1 && exist_tr(t.id)==0) 
            {gtk_widget_show(label1);
             gtk_widget_hide (existe);}
if(a==1 && y==1 && exist_tr(t.id)==0)
        {ajouter(t);
         gtk_widget_destroy(signUp);}
*/



void
on_button_annuler3_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *nouvelle_election;
GtkWidget *creation_election;
nouvelle_election=lookup_widget(GTK_WIDGET(button),"nouvelle_election"); // search for the action of the button 
gtk_widget_destroy(nouvelle_election);
creation_election=create_creation_election();
gtk_widget_show (creation_election);
}


void
on_btn_eng_syp_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_btn_annuler_sup_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_conf_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_reset_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yz_AR_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yz_supp_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yz_modif_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_yz_Prec_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_annuler22_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_entry_f_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=1;}
}


void
on_entry_m_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
{x=2;}
}


void
on_anl_modif_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
GtkWidget *dashboard_modif;
dashboard_modif=lookup_widget(GTK_WIDGET(button),"dashboard_modif");
gtk_widget_destroy(dashboard_modif);
dashboard=create_dashboard();
gtk_widget_show (dashboard);


}


void
on_eng_modif_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_btn_retour_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *dashboard;
GtkWidget *dashboard_affiche;
dashboard_affiche=lookup_widget(GTK_WIDGET(button),"dashboard_affiche");
gtk_widget_destroy(dashboard_affiche);
dashboard=create_dashboard();
gtk_widget_show (dashboard);
}


void
on_id_anl_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_id_cnx_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
char mot1[10];
char mot2[10];
GtkWidget *esp_admin;
GtkWidget *identification;
GtkWidget *input1;
GtkWidget *input2;
input1=lookup_widget(button,"entry25");
input2=lookup_widget(button,"entry26");
strcpy(mot1,gtk_entry_get_text(GTK_ENTRY(input1)));
strcpy(mot2,gtk_entry_get_text(GTK_ENTRY(input2)));
identification=lookup_widget(GTK_WIDGET(button),"identification");
if (control_admin(mot1,mot2)==1)
{
gtk_widget_destroy(identification);
esp_admin=create_esp_admin();
gtk_widget_show (esp_admin);
}
}

void
on_gest_util_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *esp_admin;
GtkWidget *dashboard;
esp_admin=lookup_widget(GTK_WIDGET(button),"esp_admin");
gtk_widget_destroy(esp_admin);
dashboard=create_dashboard();
gtk_widget_show (dashboard);
}


void
on_gest_elec_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *esp_admin;
GtkWidget *creation_election;
esp_admin=lookup_widget(GTK_WIDGET(button),"esp_admin");
gtk_widget_destroy(esp_admin);
creation_election=create_creation_election();
gtk_widget_show (creation_election);
}


void
on_gest__list_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gest_recl_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_gest_bur_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_anl_mdf_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *creation_election;
GtkWidget *modifier_election;
modifier_election=lookup_widget(GTK_WIDGET(button),"modifier_election");
gtk_widget_destroy(modifier_election);
creation_election=create_creation_election();
gtk_widget_show (creation_election);
}

