/*--------------------------------------------*
*            Les pile  Avec Menu              *
*                                             *
* Autor: bourkadi iliass                      *
* Facebook: www.facebook.com/iliass.bourakadi *
*                                             *
**********************************************/
#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
int main()
{
	int choix;
	pile p;
	p = NULL;
	int e;

	do
	{
		printf(" \n\n\n*** Menu de manipulation*** \n");
		printf("1-Afficher le contenu de la liste: \n");
		printf("2-Initialiser Votre Pile: \n");
		printf("3-Verifier Si La Pile Et Plaine!!\n");
		printf("4-Taille De La Pile\n");
		printf("5-Empiler\n");
		printf("6-Sommet De La Pile\n");
		printf("7-depuler \n");
		printf("8-EXIT");
		printf("Choisir un nombre de 1 à 12 : ");

		scanf("%d", &choix);

		switch (choix)
		{
		case 1 : affiche(p);
			break;
		case 2: p = init(p);
		
			printf("liste Intialiser !! ");
		
		break;
		case 3: if (et_plaine(p))
			printf("Liste Plaine\n");
		case 4: printf("La Liste Contient %d Element", taille(p));
			break;
		case 5: printf("Dnner le Element ");
			scanf("%d", &e);
			p = empiler(p, e);
			break;
		case 6: printf("la sommet et %d", sommet(p));
			break;
		case 7: p = depuler(p);
			printf("element supprimer\n");
			break;
		case 8:printf("Fin De Programme!! MERCII");

		default:("choisir un element correcrt!!");
		}


	} while (choix != 9);
	return 0;
} 

