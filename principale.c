
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utile.h"
#include "pile.h"
#include "postfixe.h"
void afficherpile( pile *sommet )
{
     pile *cs ; 
     int i ;
     printf("\n ------ contenur de la pile ---------\n");
     for (cs = sommet, i=0 ; cs != NULL ; cs=cs->next ,i++)
         printf("element en position %d : %d \n ",i,cs->nb);
     printf("\n ---------- FIN------------\n");}
int main(void){
    pile *sommet;
    int nb;
    char type;
    initpile(sommet);
    do {
        type = lirenbop(&nb);
        sommet = postfixe(sommet,type,nb);
        afficherpile(sommet);
        }while ( type != '.');
        if (!pilevide(sommet))
           printf("\n Result  t : %d \n",sommet->nb);
           else
           printf("operation non vide \n ");
           
           return 0;
           }    
