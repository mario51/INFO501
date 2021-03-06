#include "cellule.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

Liste* creerListe(){
	Liste* liste = malloc(sizeof(liste));
	liste->tete = NULL;
	return liste;
}

void inserer(Liste* liste, Cellule* cellule){
	cellule->successeur = liste->tete;
	if(liste->tete != NULL){
		liste->tete->predecesseur = cellule;
	}
	liste->tete = cellule;
	cellule->predecesseur = NULL;
}

Cellule* rechercher(Liste* liste, char* mot){
	Cellule* c = NULL;
	if(liste->tete != NULL){
		c = liste->tete;
		while(c != NULL && strcmp(c->cle,mot)!=0){
			c = c->successeur;
		}
	}
	return c;
}

void supprimer(Liste* liste, Cellule* cellule){
	if(cellule->predecesseur != NULL)
		cellule->predecesseur->successeur = cellule->successeur;
	else
		liste->tete = cellule->successeur;
	if(cellule->successeur != NULL)
		cellule->successeur->predecesseur = cellule->predecesseur;
}

void detruireListe(Liste** liste){
	(*liste)=NULL;
	free(*liste);
}