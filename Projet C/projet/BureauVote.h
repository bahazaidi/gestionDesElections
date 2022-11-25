#ifndef BUREAUVOTE_H_INCLUDED
#define BUREAUVOTE_H_INCLUDED
#include <stdio.h>
typedef struct
{
	int idbureau ;
	int idagent;
	char ville[30];
	char adresse[100];
	int capacitebureau ;
	int nombreobservateur ;
} bv;


typedef struct  {
  int jour ;
  int mois;
  int annee;
}Date;

typedef struct {
 char nom [20];
 char prenom[20];
 Date date;
 int cin;
 int login;
 int mdp;
 char sexe [7];
 char nationalite [20];
} observateur;

typedef struct {
 Date date;
 int  num;
 int id ;
 char nationalite [20];
 int vote;
} liste_electorale;
 


int ajouter(char *, bv);
int modifier( char *, int, bv);
int supprimer(char *, int);
bv chercher(char *,int );
void taux (char *filename ,float * tn,float * te);
float TVB(char* filename);



#endif // BUREAUVOTE_H_INCLUDED
