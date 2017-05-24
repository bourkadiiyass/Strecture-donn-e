/*********************************************
*         LIST Chainée Double                *
*                                            *
*  Autor: Iliass Bourkadi                    *
*  https://facebook.com/iliass.bourakadi     *
*                                            *
*********************************************/

#include <stdio.h>
#include <stdlib.h>

#define vrai 1
#define faux 0

struct element
{
    int val;
    struct element *precedent;
    struct element *suivant;
};
typedef struct
{
    struct element *debut;
    struct element *fin;
} list;

void initialise(list *l);
int ajout(list *l, int val);
int suprimer(list *l, int val);
int estVide(list l);
void afficherlist(list l, char mode);

main()
{
    list l;
    initialise(&l);
    ajout(&l, 33);
    ajout(&l, 23);
    ajout(&l, 12);
    ajout(&l, 40);
    ajout(&l, 30);
    afficherlist(l, 's');
    printf("\n");
    suprimer(&l, 33);
    suprimer(&l, 23);
    suprimer(&l, 12);
    suprimer(&l, 40);
    suprimer(&l, 30);
    afficherlist(l, 's');
}
void initialise(list *l)
{
    l->debut = NULL;
    l->fin = NULL;
}
int ajout(list *l, int val)
{
    struct element *aux;
    aux = (struct element*) malloc(sizeof(struct element));
    if(aux == NULL)
        return faux;
    aux->val = val;
    if(l->debut == NULL)
    {
        aux->suivant = NULL;
        aux->precedent = NULL;
        l->debut = aux;
        l->fin = aux;
        return vrai;
    }
    aux->suivant = NULL;
    aux->precedent = l->fin;
    l->fin->suivant = aux;
    l->fin = aux;
    return vrai;
}
int suprimer(list *l, int val)
{
    struct element *aux, *avant, *courant;
    if(l->debut->val == val)
    {
        aux = l->debut;
        if(l->debut->suivant == NULL)
        {
            l->debut = NULL;
            l->fin = NULL;
        }
        else
        {
            l->debut = aux->suivant;
            l->debut->precedent = aux->precedent;
        }
        free(aux);
        return vrai;
    }
    else
    {
        avant = l->debut;
        courant = l->debut->suivant;
        while(courant != NULL && courant->val != val)
        {
            avant = courant;
            courant = courant->suivant;
        }
        if(courant != NULL)
        {
            aux = courant;
            avant->suivant = courant->suivant;
            if(courant->suivant != NULL)
            {
                courant->suivant->precedent = courant->precedent;
            }
            else
            {
                l->fin = avant;
            }
            free(aux);
            return vrai;
        }
    }
    return faux;
}
int estVide(list l)
{
    if(l.debut == NULL)
        return vrai;
    return faux;
}
void afficherlist(list l, char mode)
{
    struct element *aux;
    if(!estVide(l))
    {
        if(mode == 's')
        {
            aux = l.debut;
            while(aux != NULL)
            {
                printf("\n%d", aux->val);
                aux = aux->suivant;
            }
        }
        else
        {
            aux = l.fin;
            while(aux != NULL)
            {
                printf("\n%d", aux->val);
                aux = aux->precedent;
            }
        }
    }
}
