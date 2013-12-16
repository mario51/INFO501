#include <stdio.h>
#include <stdlib.h>
#include "noeud.h"

Noeud* creerNoeud(char** chaine){

	Noeud* noeud = malloc(sizeof(noeud));
	noeud->cle=(char*)malloc(sizeof(char) * 10);
	noeud->pere = NULL;
	noeud->gauche = NULL;
	noeud->droite = NULL;

	stpcpy(noeud->cle,chaine);
	return noeud;
}

void detruireNoeud(Noeud** noeud){
	(*noeud)->cle=NULL;
	free((*noeud)->cle);
	(*noeud)->pere=NULL;
	(*noeud)->gauche=NULL;
	(*noeud)->droite=NULL;
	(*noeud)=NULL;
	free(*noeud);
}