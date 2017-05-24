/*--------------------------------------------*
*   Circle List Singly Implementation         *
*                                             *
* Autor: bourkadi iliass                      *
* Facebook: www.facebook.com/iliass.bourakadi *
*                                             *
**********************************************/

#include <stdio.h>
#include <stdlib.h>

#define vrai 1
#define faux 0

struct element
{
    int val;
    struct element *suivant;
};

typedef struct
{
    struct element *debut;
    struct element *fin;
} listCS;

void initialiseListCS(listCS *l);
int ajouteListCS(listCS *l, int val);
int suprimerListCS(listCS *l, int val);
void afficheListCS(listCS l);
int estVide(listCS l);

main()
{
    listCS l;
    initialiseListCS(&l); //creation list
    //insertion val dans la list
    ajouteListCS(&l, 23);
    ajouteListCS(&l, 12);
    ajouteListCS(&l, 16);
    ajouteListCS(&l, 78);
    //affiche list avec valeurs
    afficheListCS(l);
    printf("\nDebut: %d", l.debut->val);
    printf("\nFin: %d", l.fin->val);
    printf("\n\nSuprition 12\n\n");
    suprimerListCS(&l, 12);
    afficheListCS(l);
    printf("\nDebut: %d", l.debut->val);
    printf("\nFin: %d", l.fin->val);
    printf("\n\nSuprition 78\n\n");
    suprimerListCS(&l, 78);
    afficheListCS(l);
    printf("\nDebut: %d", l.debut->val);
    printf("\nFin: %d", l.fin->val);
    printf("\n\nSuprition 23\n\n");
    suprimerListCS(&l, 23);
    afficheListCS(l);
    printf("\nDebut: %d", l.debut->val);
    printf("\nFin: %d", l.fin->val);
    printf("\n\nSuprition 16\n\n");
    suprimerListCS(&l, 16);
    if(estVide(l))
        printf("List Vide");
}

void initialiseListCS(listCS *l)
{
    l->debut = NULL;
    l->fin = NULL;
}
int ajouteListCS(listCS *l, int val)
{
    struct element *aux;
    aux = (struct element*) malloc(sizeof(struct element));
    if(aux == NULL)
        return faux;
    if(l->debut == NULL)
    {
        aux->val = val;
        l->debut = aux;
        l->fin = aux;
        aux->suivant = l->debut;
        return vrai;
    }
    aux->val = val;
    l->fin->suivant = aux;
    aux->suivant = l->debut;
    l->fin = aux;
    return vrai;
}

int suprimerListCS(listCS *l, int val)
{
    struct element *aux, *courant, *precedent;
    if(l->debut->val == val)
    {
        aux = l->debut;
        if(l->debut == l->fin)
        {
            l->debut = NULL;
            l->fin = NULL;
        }
        else
        {
            l->debut = l->debut->suivant;
            l->fin->suivant = l->debut;
        }
        free(aux);
        return vrai;
    }
    else
    {
        precedent = l->debut;
        courant = l->debut->suivant;
        while(courant != l->debut && courant->val != val)
        {
            precedent = courant;
            courant = courant->suivant;
        }
        if(courant != l->debut)
        {
            aux = courant;
            precedent->suivant = courant->suivant;
            if(l->fin == courant)
                l->fin = precedent;
            free(aux);
            return vrai;
        }
    }
    return faux;
}

int estVide(listCS l)
{
    if(l.debut == NULL)
        return vrai;
    return faux;
}

void afficheListCS(listCS l)
{
    struct element *aux;
    if (!estVide(l))
    {
        aux = l.debut;
        if (aux != l.fin)
        {
            do
            {
                printf("%d->%d ", aux->val, aux->suivant->val);
                aux = aux->suivant;
            }
            while (aux != l.debut);
        }
        else
            printf("%d-> PROPRIO ", aux->val);
    }
}
