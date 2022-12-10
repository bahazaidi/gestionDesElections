#include "election.h"
#include <string.h>
int ajouter1 (char* filename,election e)
{
 FILE* f=fopen(filename,"a");
if(f!=NULL)
{
fprintf(f,"%d %s %s %d %d \n"
,e.id,e.date,e.municipalite,e.nbh,e.nbc);
fclose(f);
return(1);
}
else
return(0);
}

/*int modifier1(char*filename,int id,election nouv)
{
int tr=0;
election e;
FILE* f=fopen("election.txt","r");
FILE* f2=fopen("nouv.txt","a");
if(f!=NULL && f2!=NULL)
{
while (fscanf(f,"%d %s %s %d %d\n",&e.id,e.date,e.municipalite,&e.nbh,&e.nbc)!=EOF)
{
	if(e.id==id)
        {
		fprintf(f2,"%d %s %s %d %d\n",id,nouv.date,nouv.municipalite,nouv.nbh,nouv.nbc);
            tr=1;
}

else
fprintf(f2,"%d %s %s %d %d\n",e.id,e.date,e.municipalite,e.nbh,e.nbc);
}

}
fclose(f);
fclose(f2);
remove("election.txt");
rename("nouv.txt","election.txt");
return(tr);
}
int supprimer1(char*filename,int id)
{
int tr=0;
election e;
FILE *f=fopen(filename,"r");
FILE*f2=fopen("nouv.txt","w");
if(f!=NULL && f2!=NULL)
{
while(fscanf(f,"%d %s %s %d %d\n",&e.id,e.date,e.municipalite,&e.nbh,&e.nbc)!=EOF)
{
if (e.id==id)
tr=1;
else 
fprintf(f2,"%d %s %s %d %d\n",e.id,e.date,e.municipalite,e.nbh,e.nbc);
}
}
fclose(f);
fclose(f2);
remove(filename);
rename("nouv.txt",filename);
return(tr);
}
election chercher1(char* filename,int id)
{
election e;
int tr;
FILE* f=fopen(filename,"r");
if(f!=NULL)
{
while(tr==0 && fscanf(f,"%d %s %s %d %d\n",&e.id,e.date,e.municipalite,&e.nbh,&e.nbc)!=EOF)
{
	if (e.id==id)
		tr=1; 

}
}
fclose(f);
if(tr==0)
e.id=-1;
return(e);
	
}

float TPE (char*filename)
{int nbe,nbv;
float s ,nbv1;
utilisateurs p;

FILE *f=fopen(filename,"r");

if(f!=NULL)
{nbe=0;
nbv=0;
while(fscanf(f,"%s %s %d %s %ld %ld %s %s %s %s %d \n",p.nom,p.prenom,&p.age,p.sexe,&p.cin,&p.numtel ,p.mdp,p.confirmmdp,p.role,p.region,&p.v)!=EOF)
{
if(p.v!=-1)
nbv+=1;
if(strcmp(p.role,"electeur")==0)
nbe+=1;
}
}

fclose(f);
nbv1=(float) nbv;

s=(nbv1/nbe)*100;
return (s);
}
float TPHF(char*filename,float*h)
{int nbf , nbh,nbv;
float s;
utilisateurs p;

FILE *f=fopen(filename,"r");

if(f!=NULL)
{nbv=0;
nbf=0;
nbh=0;

while(fscanf(f,"%s %s %d %s %ld %ld %s %s %s %s %d \n",p.nom,p.prenom,&p.age,p.sexe,&p.cin,&p.numtel ,p.mdp,p.confirmmdp,p.role,p.region,&p.v)!=EOF)
{
if(p.v!=-1)
nbv+=1;
if(strcmp(p.sexe,"m")==0 &&p.v!=-1)
nbh+=1;
else if( strcmp(p.sexe,"m")!=0 &&p.v!=-1)
nbf+=1;
}
}
fclose(f);
*h=((float)nbh/nbv)*100;
s=((float)nbf/nbv)*100;
return(s);
}
*/

int control_admin(char *c ,char *g)
{

if(strcmp(c,"12345678")==0 && strcmp(g,"12345678")==0)
{
return(1);
}
else 
return(0);
}











