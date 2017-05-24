/*************************************************
*      List Chainée Double avec Ordination       *
*                                                *
*  Autor: Bourkadi Iliass                        *
*  https://facebook.com/iliass.bourakadi         *
*                                                *
*************************************************/

#include <stdio.h>
#include <stdlib.h>

#define vrai 1
#define faux 0

struct element
{
    int val;
    struct element *precedant;
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
void afficherList(list l, char mode);

main()
{
    list l;
    initialise(&l);
    ajouter(&l, 2);
    ajouter(&l, 0);
    ajouter(&l, 1);
    ajouter(&l, 3);
    ajouter(&l, 5);
    ajouter(&l, 4);
    printf("Afficher list avec ordination - debut to Fin \n");
    afficherList(l, 's');
    printf("\n\nAfficher list avec ordination - fin to debut\n");
    afficherList(l, 'f');
    printf("\n\nDebut: %d", l.debut->val);
    printf("\nFin: %d", l.fin->val);
    printf("\n\nsuprimer valeur de la liste -0-5-3-1-4...");
    suprimer(&l, 0);
    suprimer(&l, 5);
    suprimer(&l, 3);
    suprimer(&l, 1);
    suprimer(&l, 4);
    printf("\n\nafficher la liste aprés la suprition...\n");
    afficherList(l, 's');
    printf("\n\nDebut: %d", l.debut->val);
    printf("\nFin: %d", l.fin->val);
}
void initialise(list *l)
{
    l->debut = NULL;
    l->fin = NULL;
}

int ajouter(list *l, int val)
{
    struct element *aux, *avant, *courant;
    aux = (struct element*) malloc(sizeof(struct element));
    if(aux == NULL)
        return faux;
    aux->val = val;
    if(l->debut == NULL)
    {
        l->debut = aux;
        l->fin = aux;
        aux->suivant = NULL;
        aux->precedant = NULL;
        return vrai;
    }
    else
    {
        avant = NULL;
        courant = l->debut;
        while(courant != NULL && val > courant->val)
        {
            avant = courant;
            courant = courant->suivant;
        }
        if(avant == NULL)
        {
            aux->precedant = NULL;
            aux->suivant = courant;
            courant->precedant = aux;
            l->debut = aux;
            return vrai;
        }
        if(courant == NULL)
        {
            aux->precedant = avant;
            aux->suivant = courant;
            avant->suivant = aux;
            l->fin = aux;
            return vrai;
        }
        aux->precedant = avant;
        aux->suivant = courant;
        avant->suivant = aux;
        courant->precedant = aux;
        return vrai;
    }
}

int suprimer(list *l, int val)
{
    struct element *aux, *avant, *courant;
    if(l->debut == NULL)
        return faux;
    avant = NULL;
    courant = l->debut;
    if(courant->val == val)
    {
        aux = courant;
        courant = courant->suivant;
        if(courant == NULL)
        {
            l->debut = NULL;
            l->fin = NULL;
        }
        else
        {
            courant->precedant = NULL;
            l->debut = courant;
        }
        free(aux);
        return vrai;
    }
    while(courant != NULL && val != courant->val)
    {
        avant = courant;
        courant = courant->suivant;
    }
    aux = courant;
    avant->suivant = courant->suivant;
    if(avant->suivant == NULL)
    {
        l->fin = avant;
        free(aux);
        return vrai;
    }
    else
    {
        courant->suivant->precedant = avant;
        free(aux);
        return vrai;
    }
}
int estVide(list l)
{
    if(l.debut == NULL)
        return vrai;
    return faux;
}
void afficherList(list l, char mode)
{
    if(mode == 's')
    {
        while(l.debut != NULL)
        {
            printf("\n%d", l.debut->val);
            l.debut = l.debut->suivant;
        }
    }
    else
    {
        while(l.fin != NULL)
        {
            printf("\n%d", l.fin->val);
            l.fin = l.fin->precedant;
        }
    }
}
