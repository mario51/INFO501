#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"

Cellule* creerCellule(char** chaine){

	Cellule* cellule = malloc(sizeof(cellule));
	cellule->cle=(char*)malloc(sizeof(char) * 50);
	cellule->predecesseur = NULL;
	cellule->successeur = NULL;

	/*int i;
	for(i=0;i<taille;i++){
		cellule->cle[i]=chaine[i];
	}*/
	stpcpy(cellule->cle,chaine);
	return cellule;
}

void detruireCellule(Cellule** cellule){
	free((*cellule)->cle);
	(*cellule)->predecesseur=NULL;
	(*cellule)->successeur=NULL;
	(*cellule)=NULL;
	free(*cellule);
}