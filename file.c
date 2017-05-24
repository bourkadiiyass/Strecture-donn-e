/*------------------------------------------*
*       Implementation des Files             *
*                                           *
*                                           *
*  Autor: Bourkadi Iliass                   *
*  https://facebook.com/iliass.bourakadi    *
*                                           *
********************************************/

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
} file;

void initialise(file *q);
int ajout(file *q, int val);
int suprime(file *q, int *val);
int estVide(file q);
void afficheFile(file q);

main()
{
    //Examples
    int val;
    file q;
    initialise(&q);
    ajout(&q, 1);
    ajout(&q, 2);
    ajout(&q, 3);
    ajout(&q, 4);
    afficheFile(q);
    suprime(&q, &val);
    printf("\n %d defiler\n\n", val);
    afficheFile(q);

}
void initialise(file *q)
{
    q->debut = NULL;
    q->fin = NULL;
}
int ajout(file *q, int val)
{
    struct element *aux;
    aux = (struct element*) malloc(sizeof(struct element));
    if(aux == NULL)
        return faux;
    aux->val = val;
    aux->suivant = NULL;
    if(q->debut == NULL)
        q->debut = aux;
    if(q->fin != NULL)
        q->fin->suivant = aux;
    q->fin = aux;
    return vrai;
}
int suprime(file *q, int *val)
{
    struct element *aux;
    if(q->debut == NULL)
        return faux;
    aux = q->debut;
    q->debut = aux->suivant;
    if(q->debut == NULL)
        q->fin = NULL;
    *val = aux->val;
    free(aux);
    return vrai;
}
int estVide(file q)
{
    if(q.debut == NULL)
        return vrai;
    return faux;
}
void afficheFile(file q)
{
    while(!estVide(q))
    {
        printf("%d\n", q.debut->val);
        q.debut = q.debut->suivant;
    }
}
