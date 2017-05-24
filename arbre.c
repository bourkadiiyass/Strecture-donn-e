/*************************************************
*          Implimentation des Arbres             *
*                                                *
*  Autor: Bourkadi Iliass                        *
*  https://facebook.com/iliass.bourakadi         *
*                                                *
*************************************************/

#include <stdio.h>
#include <stdlib.h>

#define vrai 1
#define faux 0

struct node
{
    struct node *gauche;
    struct node *droit;
    int val;
};

typedef struct node *arbre;

void ajouterNode(arbre *t, int val);
void enorder(arbre t);
void postorder(arbre t);
void preOrder(arbre t);
int nbrNode(arbre t);
int chercheNode(arbre t, int val);
int maxNode(int a, int b);
int Hauteur(arbre t);
int HauteurNode(arbre t, int dado);

main()
{
    arbre t = NULL;
    ajouterNode(&t, 9);
    ajouterNode(&t, 11);
    ajouterNode(&t, 7);
    ajouterNode(&t, 3);
    ajouterNode(&t, 5);
    ajouterNode(&t, 1);
    ajouterNode(&t, 0);
    ajouterNode(&t, 8);
    ajouterNode(&t, 15);
    ajouterNode(&t, 13);
    ajouterNode(&t, 6);
    printf("Pre-Order: \n");
    preOrder(t);
    printf("\n\nEn-Order: \n");
    enorder(t);
    printf("\n\nPost-Order: \n");
    postorder(t);
    printf("\n\nHauteur Arbre: %d", Hauteur(t));
    printf("\nHauteur Node 8: %d", HauteurNode(t, 8));
    printf("\nNode on arbre: %d", nbrNode(t));
    if(chercheNode(t, 13))
        printf("\nCherche node 13: vrai");
    else
        printf("\nCherche node 13: faux");
}
void ajouterNode(arbre *t, int val)
{
    if(*t == NULL)
    {
        *t = (struct node *) malloc(sizeof(struct node));
        if(*t != NULL)
        {
            (*t)->gauche = NULL;
            (*t)->droit = NULL;
            (*t)->val = val;
        }
        else
        {
            printf("\nError: Memoire Insufisent!\n");
        }
    }
    else
    {
        if(val < (*t)->val)
            ajouterNode(&(*t)->gauche, val);
        else if(val > (*t)->val)
            ajouterNode(&(*t)->droit, val);
        else
        {
            printf("\nError: Node Dupliqué!\n");
        }
    }
}
void enorder(arbre t)
{
    if(t != NULL)
    {
        enorder(t->gauche);
        printf("%d ", t->val);
        enorder(t->droit);
    }
}
void postorder(arbre t)
{
    if(t != NULL)
    {
        postorder(t->gauche);
        postorder(t->droit);
        printf("%d ", t->val);
    }
}

void preOrder(arbre t)
{
    if(t != NULL)
    {
        printf("%d ", t->val);
        preOrder(t->gauche);
        preOrder(t->droit);
    }
}

int nbrNode(arbre t)
{
    if(t == NULL)
        return 0;
    return nbrNode(t->gauche) + nbrNode(t->droit) + 1;
}

int chercheNode(arbre t, int val)
{
    if(t == NULL)
        return faux;
    if(t->val == val)
        return vrai;
    return chercheNode(t->gauche, val) || chercheNode(t->droit, val);
}

int maxNode(int a, int b)
{
    if(a > b)
        return a;
    return b;
}
int Hauteur(arbre t)
{
    if(t == NULL)
        return -1;
    return 1 + maxNode(Hauteur(t->gauche), Hauteur(t->droit));
}
int HauteurNode(arbre t, int val)
{
    if(t->val == val)
        return 0;
    if(chercheNode(t->gauche, val))
        return 1 + HauteurNode(t->gauche, val);
    if(chercheNode(t->droit, val))
        return 1 + HauteurNode(t->droit, val);
    else
        return -1;
}
