#ifndef PROJET_C_H_INCLUDED
#define PROJET_C_H_INCLUDED
typedef struct
{
	char nom[20];
	char prenom[20];
	int age;
	char sexe[10];
	long cin;
	long numtel;
	char mdp[10];
	char confirmmdp[10];
	char role[20];
	char region[20];
	int bureauDeVote;
	int v;
	

}utilisateurs;

int ajouter(utilisateurs p);
int modifier(char *filename,long cin, utilisateurs nouv);
int supprimer(char *filename,long cin);
utilisateurs chercher(char *filename,long cin);
float agemoyen(char *filename); 
int nombreElecteurParBureau(char *filename,int numbur);

#endif

