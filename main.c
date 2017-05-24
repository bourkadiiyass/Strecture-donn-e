#include "pile.h"



void TRUC(int i, int n, element * T)
{
    int j;
    element temp;
    if (i==n)
    {
        for (j = 0; j < n; ++j) {
            Afficher(T[j]);
        }
        printf("\n");
    }
    else
        for (j = i; j <= n; ++j) {
            temp=T[i-1];
            T[i-1]=T[j-1];
            T[j-1]=temp;
            TRUC(i+1, n, T);
            temp=T[i-1];
            T[i-1]=T[j-1];
            T[j-1]=temp;
        }
}


void TRUCTrace(int i, int n, element * T, int tabu)
{
    int j;
    int t;
    for (t=0; t<tabu; t++) printf("\t");
    printf("TRUC(%d, %d, T)\n", i, n);
    element temp;
    if (i==n)
    {
        for (t = 0; t < tabu; t++) printf("\t");
        for (j = 0; j < n; ++j) {
            Afficher(T[j]);
        }
        printf("\n");
    }
    else
        for (j = i; j <= n; ++j) {
            temp=T[i-1];
            T[i-1]=T[j-1];
            T[j-1]=temp;
            TRUCTrace(i+1, n, T, tabu+1);
            temp=T[i-1];
            T[i-1]=T[j-1];
            T[j-1]=temp;
        }
    for (t=0; t<tabu; t++) printf("\t");
    printf("Fin\n");
}



void TRUC2(int i, int n, element * T)
{
    int j, k;
    element temp;

    pile_t * pile = Init((n - i) * 2);
    j=i;
    do
    {
        while (i<n)
        {
            temp = T[i - 1];
            T[i - 1] = T[j - 1];
            T[j - 1] = temp;

            Empiler(pile, i);
            Empiler(pile, j);
            i++;
            j=i;
        }

        for (k = 0; k < n; ++k)
            Afficher(T[k]);
        printf("\n");
        do
        {
            j= Depiler(pile);
            i= Depiler(pile);

            temp = T[i - 1];
            T[i - 1] = T[j - 1];
            T[j - 1] = temp;

            j++;
        } while (j>n && !EstVide(pile));

    } while (j<=n || !EstVide(pile));
    LibererPile(pile);
}




int main() {

    /*int i = 0, res;
    pile_t * PileTest;
    PileTest = Init(8);
    printf("Pile Vide = %d\n\n",estVide(PileTest));
    for(i = 0; i<5;i++)
    {
        res = Empiler(PileTest,i);
    }
    afficherPile(PileTest);
    printf("Pile Vide = %d\n\n",estVide(PileTest));
    for(i = 0; i<2;i++)
    {
        res = Depiler(PileTest);
    }
    AfficherPile(PileTest);
    printf("Pile Vide = %d\n\n",EstVide(PileTest));
    LibererPile(PileTest);
    return 0;*/

    int T[]={4, 5, 6, 7, 8};

    TRUCTrace(1, 3, T, 0);
    TRUC2(1, 5, T);
    return 0;
}