#include <stdio.h>
#include "utilisateur.h"


int ajouter(utilisateurs p)
{
    FILE *f=fopen("utilisateur.txt", "a");
    if(f!=NULL)
    { p.v=-1;
        fprintf(f,"%s %s %d %s %ld %ld %s %s %s %s %d %d\n",p.nom,p.prenom,p.age,p.sexe,p.cin,p.numtel,p.mdp,p.confirmmdp,p.role,p.region,p.bureauDeVote,p.v);
        fclose(f);
        return 1;
    }
    else return 0;
}
utilisateurs p;

int modifier(char*utilisateur,long cin, utilisateurs nouv)
{
    utilisateurs p;
    FILE * f=fopen("utilisateur.txt", "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %d %s %ld %ld %s %s %s  %s%d%d\n",p.nom,p.prenom,&p.age,p.sexe,&p.cin,&p.numtel,p.mdp,p.confirmmdp,p.role,p.region,&p.bureauDeVote,&p.v)!=EOF)
{
if(p.cin!=cin)
        fprintf(f2,"%s %s %d %s %ld %ld %s %s %s %s\n ",p.nom,p.prenom,p.age,p.sexe,p.cin,p.numtel,p.mdp,p.confirmmdp,p.role,p.region);
else

  fprintf(f2,"%s %s %d %s %ld %ld %s %s %s %s%d\n",nouv.nom,nouv.prenom,nouv.age,nouv.sexe,nouv.cin,nouv.numtel,nouv.mdp,nouv.confirmmdp,nouv.role,nouv.region,nouv.bureauDeVote);

   }
        fclose(f);
        fclose(f2);
remove("utilisateur.txt");
rename("aux.txt", "utilisateur.txt");
        return 1;
    }

}

int supprimer(char*utilisateur,long cin)
{
    utilisateurs p;
    FILE * f=fopen("utilisateur.txt", "r");
    FILE * f2 =fopen("aux.txt", "w");
    if(f==NULL || f2==NULL)
return 0;
else
    {
while(fscanf(f,"%s %s %d %s %ld %ld %s %s %s %s %d %d\n",p.nom,p.prenom,&p.age,p.sexe,&p.cin,&p.numtel,p.mdp,p.confirmmdp,p.role,p.region,&p.bureauDeVote,&p.v)!=EOF)
{
if(p.cin!=cin)
        fprintf(f2,"%s %s %d %s %ld %ld %s %s %s %s %d %d\n",p.nom,p.prenom,p.age,p.sexe,p.cin,p.numtel,p.mdp,p.confirmmdp,p.role,p.region,p.bureauDeVote,p.v);

}
        fclose(f);
        fclose(f2);
remove("utilisateur.txt");
rename("aux.txt", "utilisateur.txt");
        return 1;
    };
};


utilisateurs chercher(char *utilisateur, long cin )
{
 int search;
utilisateurs p;

    FILE * f=fopen("utilisateur.txt", "r");
search=0;
 if(f!=NULL )
    {
while(search==0 && fscanf(f,"%s %s %d %s %ld %ld %s %s %s %s %d %d\n",p.nom,p.prenom,&p.age,p.sexe,&p.cin,&p.numtel,p.mdp,p.confirmmdp,p.role,p.region,&p.bureauDeVote,&p.v)!=EOF)
{if(p.cin==cin)
search=1;
}
}
fclose(f);
if(search==0)
p.cin=-1;
return p;

}
float agemoyen(char *utilisateur){
    FILE * f=fopen("utilisateur.txt", "r");
int sommeAge,nombreParticipant;
float ageMoyen;
nombreParticipant=0;
sommeAge=0;
while(fscanf(f,"%s %s %d %s %ld %ld %s %s %s %s %d %d\n",p.nom,p.prenom,&p.age,p.sexe,&p.cin,&p.numtel,p.mdp,p.confirmmdp,p.role,p.region,&p.bureauDeVote,&p.v)!=EOF){

sommeAge+=p.age;
if(p.v!=-1){nombreParticipant+=1;}
}
ageMoyen=sommeAge/nombreParticipant;

return (ageMoyen);
}
int nombreElecteurParBureau(char *utilisateur,int numbur){
FILE *f=fopen("utilisateur.txt", "r");
int nomPartParBur;
nomPartParBur=0;
while(fscanf(f,"%s %s %d %s %ld %ld %s %s %s %s %d %d\n",p.nom,p.prenom,&p.age,p.sexe,&p.cin,&p.numtel,p.mdp,p.confirmmdp,p.role,p.region,&p.bureauDeVote,&p.v)!=EOF){
if(p.bureauDeVote==numbur){
	nomPartParBur+=1;
}
}
return(nomPartParBur);
}
