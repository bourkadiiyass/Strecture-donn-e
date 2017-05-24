
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "utile.h"
int verifnbr(char* c,int *nb){
    int i=0;
    *nb=0;
    while(c[i]!='\0'){
                      if((c[i]>='0')&&(c[i]<='9'))
                                                  *nb=(*nb) * 10 + c[i] - '0';
                                                  else if(c[i]==' ')
                                                  { *nb=(*nb)*-1;
                                                  return 1;}
                                                  else
                                                  return 0;
                                                  i++;
                                                  }
                                                  return 1;
                                                  }
int verifop(char *c){
    if(strlen(c)==1)
                    if((c[0]=='+')|(c[0]=='-')|(c[0]=='*')|(c[0]=='/'))
                                                                       returne 1 ;
                                                                       else 
                                                                       return 0;
                                                                       }
char lirenbop(int *nb){
     char c[20]
     printf("saisie un nombre ou un operation \n");
     scanf("%s",&c);
     if(verifop(c))
     return c[0];
     else
         if (verifnbr(c))
         return 'N';
         else
         return '.';
         }
         
                                                  
