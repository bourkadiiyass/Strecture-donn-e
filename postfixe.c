
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "util.h"
#include "pile.h"
#include "postfixe.h"
pile *postfixe(pile *sommet , char type,int nb){
     int nb1,nb2;
     switche(type){
                   case 'N':
                        dommet= depile(sommet,nb);
                        break;
                        case '+':
                             sommet = depile(sommet,&nb2);
                             sommet = depile(sommet,&nb1);
                             nb=nb1+nb2;
                             sommet = empile(sommet,nb);
                             break;
                             case '-':
                             sommet = depile(sommet,&nb2);
                             sommet = depile(sommet,&nb1);
                             nb=nb1-nb2;
                             sommet = empile(sommet,nb);
                             break;
                             case '*':
                             sommet = depile(sommet,&nb2);
                             sommet = depile(sommet,&nb1);
                             nb=nb1*nb2;
                             sommet = empile(sommet,nb);
                             break;
                             case '/':
                             sommet = depile(sommet,&nb2);
                             sommet = depile(sommet,&nb1);
                             if(nb2!=0){
                             nb=nb1/nb2;
                             sommet = empile(sommet,nb);}
                             else {printf("erreur logique \n");
                             exit(1);}
                             break;}
                             return sommet;
