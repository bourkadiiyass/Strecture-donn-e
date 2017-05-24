/*---------------------------------------*
*   Circle List Doubly Implementation    *
*                                        *
* Autor: bourkadi iliass                   *
* Facebook: www.facebook.com/iliass.bourakadi         *
*                                        *
******************************************/

#include <stdio.h>
#include <stdlib.h>

#define vrai 1
#define faut 0

struct element
{
    int val;
    struct element *avant;
    struct element *suivant;
};

typedef struct
{
    struct element *debut;
    struct element *fin;
} listC;

void initialListC(listC *l);
int estVide(listC l);
int inserListC(listC *l, int val);
int suprimListC(listC *l, int val);
void afficheListC(listC l);

main()
{
    listC l;
    initialListC(&l);
    inserListC(&l, 3);
    inserListC(&l, 5);
    inserListC(&l, 2);
    inserListC(&l, 7);
    inserListC(&l, 8);
    afficheListC(l);
    printf("\nDébut: %d", l.debut->val);
    printf("\nFin: %d", l.fin->val);
    printf("\n\nSuprition 2\n\n");
    suprimListC(&l, 2);
    afficheListC(l);
    printf("\nDébut: %d", l.debut->val);
    printf("\nFin: %d", l.fin->val);
    printf("\n\nSuprition 8\n\n");
    suprimListC(&l, 8);
    afficheListC(l);
    printf("\nDébut: %d", l.debut->val);
    printf("\nFin: %d", l.fin->val);
    printf("\n\nSuprition 3\n\n");
    suprimListC(&l, 3);
    afficheListC(l);
    printf("\nDébut: %d", l.debut->val);
    printf("\nFin: %d", l.fin->val);
    printf("\n\nSuprition 5\n\n");
    suprimListC(&l, 5);
    afficheListC(l);
    printf("\nDébut: %d", l.debut->val);
    printf("\nFin: %d", l.fin->val);
    printf("\n\nSuprition 7\n\n");
    suprimListC(&l, 7);
    if(estVide(l))
        printf("\nList Vide");

}

void initialListC(listC *l)
{
    l->debut = NULL;
    l->fin = NULL;
}

int estVide(listC l)
{
    if(l.debut == NULL)
        return vrai;
    return faut;
}

int inserListC(listC *l, int val)
{
    struct element *aux;
    aux = (struct element*) malloc(sizeof(struct element));
    aux->val = val;
    if(l->debut == NULL)
    {
        l->debut = aux;
        l->fin = aux;
        aux->avant = l->fin;
        aux->suivant = l->debut;
        return vrai;
    }
    else
    {
        aux->avant = l->fin;
        aux->suivant = l->debut;
        l->fin->suivant = aux;
        l->fin = aux;
        l->debut->avant = aux;
        return vrai;
    }
}

int suprimListC(listC *l, int val)
{
    struct element *aux, *precedent, *courant;
    if(l->debut->val == val)
    {
        if(l->debut == l->fin)
        {
            l->debut = NULL;
            l->fin = NULL;
        }
        else
        {
            aux = l->debut;
            l->debut = l->debut->suivant;
            l->debut->avant = l->fin;
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
            courant->suivant->avant = precedent;
            if(courant->suivant == l->debut)
                l->fin = precedent;
            free(aux);
            return vrai;
        }
    }
    return faut;
}

void afficheListC(listC l)
{
    struct element *aux;
    if(!estVide(l))
    {
        aux = l.debut;
        if(aux != l.fin)
        {
            do
            {
                printf("%d->%d ", aux->val, aux->suivant->val);
                aux = aux->suivant;
            } while(aux != l.debut);
        }
        else
        {
            printf("%d-> Proprio", aux->val);
        }
    }
}
