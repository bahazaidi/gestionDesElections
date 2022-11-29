
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "BureauVote.h"

int ajouter(char * filename, bv bva)
{
    FILE * f=fopen(filename, "a");
    if(f!=NULL && bva.idbureau!=0)
    {
        fprintf(f,"%d %d %s %s %d %d\n",bva.idbureau,bva.idagent,bva.ville,bva.adresse,bva.capacitebureau,bva.nombreobservateur);
        fclose(f);
        return 1;
    }
    else 
        return 0;
}


bv chercher(char * filename, int id)
{
    bv bv1;
    int tr=0;
    FILE * f=fopen(filename, "r");
    if(f!=NULL)
    {
        while(tr==0  &&  fscanf(f,"%d %d %s %s %d %d  \n",&bv1.idbureau,&bv1.idagent,bv1.ville,bv1.adresse,&bv1.capacitebureau,&bv1.nombreobservateur)!=EOF)
        {

            if(bv1.idbureau== id)
                tr=1;
        }
    }
    fclose(f);
    if(tr==0)
        bv1.idbureau=-1;
    return bv1;

}



int supprimer(char * filename, int idbureau)
{
    int tr=0;
    bv bv1;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %d %d\n",&bv1.idbureau,&bv1.idagent,bv1.ville,bv1.adresse,&bv1.capacitebureau,&bv1.nombreobservateur)!=EOF)
        {
            if(bv1.idbureau== idbureau)
                tr=1;
            else
                fprintf(f2,"%d %d %s %s %d %d\n",bv1.idbureau,bv1.idagent,bv1.ville,bv1.adresse,bv1.capacitebureau,bv1.nombreobservateur);
        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;
}



int modifier( char * filename, int idbureau, bv nouv )
{
    int tr=0;
    bv bv1 ;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%d %d %s %s %d %d",&bv1.idbureau,&bv1.idagent,bv1.ville,bv1.adresse,&bv1.capacitebureau,&bv1.nombreobservateur)!=EOF)
        {printf("ver1");
            if(bv1.idbureau== idbureau)

               { fprintf(f2,"%d %d %s %s %d %d\n",nouv.idbureau,nouv.idagent,nouv.ville,nouv.adresse,nouv.capacitebureau,nouv.nombreobservateur);
                tr=1;
               }

            else
                fprintf(f2,"%d %d %s %s %d %d\n",bv1.idbureau,bv1.idagent,bv1.ville,bv1.adresse,bv1.capacitebureau,bv1.nombreobservateur);

        }
    }
    fclose(f);
    fclose(f2);
    remove(filename);
    rename("nouv.txt", filename);
    return tr;

}


void taux (char *filename ,float *tn,float *te)
{
    int nb_t=0;
    int nb_e=0;
    char nati[30]="tunisien";
    observateur ob;
    FILE *f=fopen(filename,"r");
    if(f!=NULL)
  {
        while (fscanf(f,"%d %d %d %s %s  %d %s %d %s %d ",&ob.date.jour,&ob.date.mois,&ob.date.annee,ob.nom,ob.prenom,&ob.cin,ob.nationalite,&ob.login,ob.sexe,&ob.mdp)!= EOF)
       {

            if(strcmp(ob.nationalite,nati)==0)
                {
                nb_t++;
                }
            else {
                nb_e++;
                }
        }
   }
    

 *tn=((nb_t*1.0)/((nb_t+nb_e)*1.0))*100;
 *te=((nb_e*1.0)/((nb_t+nb_e)*1.0))*100;

fclose(f);

}

float TVB(char * filename)
{ int nb_votes=0;
  int nb_votes_blanc=0;
  float tvb;
liste_electorale LE ;
FILE *f=fopen(filename, "r");
 if(f!=NULL) 
{  while(fscanf(f,"%d %d %d %d %s %d %d \n",&LE.date.jour,&LE.date.mois,&LE.date.annee,&LE.num,LE.nationalite,&LE.id,&LE.vote)!=EOF)
	{  
	if (LE.vote==0) 
         { nb_votes_blanc++;}
	if ((LE.vote==1)||(LE.vote==0))  
             { nb_votes++;}
}
}
	tvb=(float)(nb_votes_blanc*1.0)/ (nb_votes*1.0);
	fclose(f);
	return tvb;
	}



