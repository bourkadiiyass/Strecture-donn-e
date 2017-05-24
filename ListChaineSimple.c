/*********************************************
*         LIST Chainée Simple                *
*                                            *
*  Autor: Iliass Bourkadi                    *
*  https://facebook.com/iliass.bourakadi     *
*                                            *
*********************************************/

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
int ajout(list *l, int val);
int suprime(list *l, int val);
int estVide(list l);
void afficheList(list l);

main()
{
    list l;

    initialise(&l);
    printf("insertion les valeurs...\n");
    Sleep(500);
    ajout(&l, 123);
    ajout(&l, 40);
    Sleep(500);
    printf("\n\n afficher les valeurs...");
    afficheList(l);
    Sleep(500);
    printf("\n\nSuprition des valeurs...");
    Sleep(500);
    suprime(&l, 40);
    Sleep(500);
    printf("\n\naffichée les valeurs aprés suprition...");
    afficheList(l);
}

void initialise(list *l)
{
    l->debut = NULL;
    l->fin = NULL;
}

int ajout(list *l, int val)
{
    struct element *aux;
    aux = (struct element *) malloc(sizeof(struct element));
    if(aux == NULL)
        return faux;
    aux->val = val;
    aux->suivant = NULL;
    if(l->debut == NULL)
        l->debut = aux;
    if(l->fin != NULL)
        l->fin->suivant = aux;
    l->fin = aux;
    return vrai;
}
int suprime(list *l, int val)
{
    struct element *aux, *preced, *courant;
    if(l->debut->val == val)
    {
        aux = l->debut;
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
            preced->suivant = courant->suivant;
            free(aux);
            l->fin = courant;
            return vrai;
        }
        else
            return faux;
    }
}
int estVide(list l)
{
    if(l.debut == NULL)
        return vrai;
    return faux;
}
void afficheList(list l)
{
    printf("\n\n");
    while(l.debut != NULL)
    {
        printf("%d ", l.debut->val);
        l.debut = l.debut->suivant;
    }
}
