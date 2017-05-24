

#define les_pile_projet


#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef int element;

void Afficher(element elmt);

typedef struct {
    int taille;
    int sommet;
    element * base;
} pile_t;

pile_t * Init(int taille);

int Empiler(pile_t *pile, element val);

element Depiler(pile_t *pile);

int EstVide(pile_t *pile);

void LibererPile(pile_t *pile);

element Sommet(pile_t *pile);

void AfficherPile(pile_t *pile);



