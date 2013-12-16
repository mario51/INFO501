#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"

Cellule* creerCellule(int valeur){

	Cellule* cellule = malloc(sizeof(cellule));
	cellule->cle=valeur;
	cellule->predecesseur = NULL;
	cellule->successeur = NULL;

	return cellule;
}

void detruireCellule(Cellule** cellule){
	(*cellule)->predecesseur=NULL;
	(*cellule)->successeur=NULL;
	(*cellule)=NULL;
	free(*cellule);
}