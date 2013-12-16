#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"
#include <stdbool.h>
#include "file.h"

int main(){

	char nomFichier[100];
	int numSommet = -1;
	
	printf("Entrez le nom du fichier : ");
	scanf("%s",nomFichier);
	printf("Entrez le sommet de depart : ");
	scanf("%d",&numSommet);
	printf("\n\n");

	Graphe* graphe = creerGraphe(nomFichier);
	
	afficherListesAdjacences(graphe);
	afficherMatriceAdjacences(graphe);
	
	parcoursLargeur(graphe, graphe->tabSommet[numSommet]);
	afficherChemin(graphe,graphe->tabSommet[numSommet]);
	
	parcoursProfondeur(graphe);
	afficherParcoursProfondeur(graphe);
	
	detruireGraphe(&graphe);

	return 0;
}