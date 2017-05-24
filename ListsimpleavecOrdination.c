/*************************************************
*      List Chainée Simple avec Ordination       *
*                                                *
*  Autor: Bourkadi Iliass                        *
*  https://facebook.com/iliass.bourakadi         *
*                                                *
*************************************************/

#include <stdio.h>
#include <windows.h>

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
} list;

void initialise(list *l);
int ajouter(list *l, int val);
int suprimer(list *l, int val);
int estVide(list l);
void afficherList(list l);

main()
{
    list l;
    initialise(&l);
    ajouter(&l, 4);
    ajouter(&l, 2);
    ajouter(&l, 3);
    ajouter(&l, 1);
    afficherList(l);
}
void initialise(list *l)
{
    l->debut = NULL;
    l->fin = NULL;
}
int ajouter(list *l, int val)
{
    struct element *aux, *preced, *courant;

    aux = (struct element *) malloc(sizeof(struct element));
    if(aux != NULL)
    {
        aux->val = val;
        aux->suivant = NULL;
        preced = NULL;
        courant = l->debut;
        while(courant != NULL && val > courant->val)
        {
            preced = courant;
            courant = courant->suivant;
        }
        if(preced == NULL)
        {
            aux->suivant = l->debut;
            l->debut = aux;
            return vrai;
        }
        else
        {
            preced->suivant = aux;
            aux->suivant = courant;
            return vrai;
        }
    }
    else
    {
        return faux;
    }
}
int suprimer(list *l, int val)
{
    struct element *aux, *preced, *courant;
    aux = l->debut;
    if(aux != NULL && val == aux->val)
    {
        l->debut = aux->suivant;
        free(aux);
        return vrai;
    }
    else
    {
        preced = l->debut;
        courant = l->debut->suivant;
        while(courant != NULL && courant->val != val)
        {
            preced = courant;
            courant = courant->suivant;
        }
        if(courant != NULL)
        {
            aux = courant;
            preced->suivant = aux->suivant;
            free(aux);
            l->fin = courant;
        }
        else
            return faux;
    }
}
void afficherList(list l)
{
    while(l.debut != NULL)
    {
        printf("\n%d", l.debut->val);
        l.debut = l.debut->suivant;
    }
}
