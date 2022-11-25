#include <stdio.h>
#include <string.h>
#include"BureauVote.h"
int main()
{
   bv bva= {1267,458,"ariana","ecole_elghazela",250,10}, bvb= {1113,676,"gabes","ecole_elhidaya",125,6}, bvc={};

   float vb;
   float tn;
   float te;



   int x=ajouter("bv.txt", bva);
 	 if(x==1)
        
         	 printf ("\nAjout de bureau de vote avec succés\n");
	else 
		 printf ("\nEchec d'ajout\n");

		


   bvc=chercher("bv.txt",1267);
	if(bvc.idbureau==-1)
      	    {printf("\nintrouvable\n");
 	     return 0; }       
	else  
            {printf("\nTrouvable:\n");
             printf("idbureau:%d \n idagent:%d \n ville:%s \n adresse:%s \n capacitebureau:%d \n nombreobservateur:%d\n" , bva.idbureau, bva.idagent, 		     bva.ville, bva.adresse, bva.capacitebureau, bva.nombreobservateur);}



    x=supprimer("bv.txt",1267 );
   	   if(x==1)
        	 printf("\nSuppression de bureau de vote avec succés\n");
           else printf("\nEchec de suppression\n");
                


      


 x=modifier("bv.txt",1213,bvb );
    if(x==1)
       { printf("\n Modification de bureau de vote avec succés");}
    else 
       { printf("\n Echec de modification\n");}
    


     taux ("obs.txt" ,&tn, &te);
          printf("Taux d'observateurs nationaux: %f \n",tn);
          printf("Taux d'observateurs étrangers: %f \n",te);
    
     vb=TVB( "Liste_electorale.txt");
     printf("Taux de votes blancs: %f \n",vb);

return 0;

}


