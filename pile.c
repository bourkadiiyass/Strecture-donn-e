#include "pile.h"



pile_t * Init(int taille) {
    pile_t *pile = NULL;

    if(taille > 0)
    {

        pile = (pile_t *) malloc(sizeof(pile_t));

        if (pile != NULL)
        {
            pile->base = (element *) malloc(sizeof(element) * taille);
            if (pile->base != NULL)
            {
                pile->taille = taille;
                pile->sommet = -1;
            }
            else
            {
                free(pile);
                pile = NULL;
            }
        }
    }
    return pile;
}



int Empiler(pile_t * pile, element val)
{
    int     res = 0;

    if(pile->taille > (pile->sommet) +1)
    {
        pile->base[(pile->sommet) +1] = val;
        res = 1;
        pile->sommet++;
    }
    return res;
}


element Depiler(pile_t * pile)
{
    pile->sommet--;
    return (pile->base)[pile->sommet+1];
}


element Sommet(pile_t * pile)
{
    return (pile->base)[pile->sommet];
}



int EstVide(pile_t * pile)
{
    return pile->sommet == -1;
}



void LibererPile(pile_t * pile)
{
    free(pile->base);
    free(pile);
}



void AfficherPile(pile_t * pile)
{
    int     i = 0;
    for(i=pile->sommet;i>=0;i--)
    {
        Afficher(pile->base[i]);
    }
    printf("\n\n");
}



void Afficher(element elmt)
{
    printf("%d ",elmt);
}
