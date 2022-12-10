#ifndef ELECTION_H_INCLUDED
#define ELECTION_H_INCLUDED
#include <stdio.h>
typedef struct
{
char date[12],municipalite[13];
int id,nbh,nbc;
}election;
/*typedef struct 
{
	char nom[20];
	char prenom[20];
	int age;
	char sexe[2];
	long cin;
	long numtel;
	char mdp[10];
	char confirmmdp[10];
	char role[20];
	char region[20];
	int v;

}utilisateurs;*/
int ajouter1(char*filename,election e);
int modifier1(char*filename,int id,election e);
int supprimer1(char*filename,int id);
election chercher1(char*filename,int id);
float TPE(char*filename);
float TPHF(char*filename,float*h);

int control_admin(char *c ,char *g);
#endif//ELECTION_H_INCLUDED

