#ifndef GRAPHE_H_INCLUDED
#define GRAPHE_H_INCLUDED
#include <stdbool.h>
#include "liste.h"
#include "cellule.h"
#include "outilsListe.h"

typedef struct So{
	char* couleur;
	int distance;
	struct So* pere;
	int cle;
	int debut;
	int fin;
} Sommet ;

typedef struct{
	int nbrSommet;
	int oriente;
	int value;
	int complet;
	Liste** listeAdj;
	int** matriceAdj;
	Sommet** tabSommet;
} Graphe ;

Liste* creerListesAdjacences(char*);
void afficherListesAdjacences(Graphe*);
int* creerMatriceAdjacences(char*);
void afficherMatriceAdjacences(Graphe*);
Graphe* creerGraphe(char*);
void detruireGraphe(Graphe**);
Sommet* creerSommet();
void detruireTableauSommet(Sommet**);
void parcoursLargeur(Graphe*, Sommet*);
void afficherChemin(Graphe*,Sommet*);
void parcoursProfondeur(Graphe*);
void visiterPP(Graphe*, Sommet*, int*);
void afficherParcoursProfondeur(Graphe*);

#endif // GRAPHE_H_INCLUDED