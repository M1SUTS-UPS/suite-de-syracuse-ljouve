#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void syracuse(int Un);

int main()
{

 int Un;

 printf("u0 = ");       // on initialise u0 en demandant à l'utilisateur
 scanf("%d",&Un);

 syracuse(Un);

}




void syracuse(int Un)
{

 int p=0, Umax;
 
 FILE *fp;                       // on ouvre un fichier texte
 fp=fopen("syracuse.txt","w");
 

 
 Umax=Un;     // on initialise Umax à u0 d'abord
 
 fprintf(fp,"%d ; ", Un);       // on insère u0 dans le fichier texte
 
 
 while(Un!=1) // condition de fin de calcul, tant que Un est différent de 1
 {
  if(Un%2==0)   // si n pair
  {
   Un=Un/2;
   p+=1;
  }
  else          // si n impair
  {
   Un=3*Un+1;
   p+=1;
  }
  fprintf(fp,"%d ; ", Un);       // on insère Un dans le fichier texte
  
  if(Un>Umax)        // on récupère la valeur maximale de Un
  {
   Umax=Un;
  }
  
 }
 
 fprintf(fp,"%d", 1); 
 
 /*  Pour permettre le traitement sur python, on insère fictivement une valeur supplémentaire de 1 qu'on enlèvera ensuite   */
 
 printf("Le temps de vol obtenu est %d \n",p);  // affichage du temps de vol sur la console
 printf("L'altitude est %d\n", Umax);      // affichage de l'altitude
 
 
fclose(fp);    // fermeture du fichier texte
}






