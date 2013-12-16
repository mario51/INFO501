#include "noeud.h"
#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>
#include "outilsArbre.h"

Arbre* creerArbre(){
	Arbre* arbre = malloc(sizeof(arbre));
	arbre->racine = NULL;
	return arbre;
}

void detruireArbre(Arbre** arbre){
	detruireNoeud((*arbre)->racine);
	(*arbre)->racine=NULL;
	(*arbre)=NULL;
	free(*arbre);
}

void insererArbre(Arbre* arbre, Noeud* noeud){
	Noeud* x = NULL;
	Noeud* y = NULL;
	x = arbre->racine;
	while(x != NULL){
		y = x;
		if(strcmp(noeud->cle,x->cle)<0)
			x=x->gauche;
		else
			x=x->droite;
	}
	noeud->pere=y;
	if(y==NULL)
		arbre->racine=noeud;
	else if(strcmp(noeud->cle,y->cle)<0)
		y->gauche=noeud;
	else
		y->droite=noeud;
}

Noeud* rechercherArbre(Arbre* arbre,char* mot){
	Noeud* x = arbre->racine;
	while(x!=NULL && strcmp(x->cle,mot)!=0){
		if(strcmp(mot,x->cle)<0)
			x=x->gauche;
		else
			x=x->droite;
	}
	return x;	
}

void supprimerArbre(Arbre* a,Noeud* z){
	if(z->gauche==NULL)
		transplanter(&a,&z,&z->droite);
	else if(z->droite==NULL)
		transplanter(&a,&z,&z->gauche);
	else{
		Noeud* y = minimumArbre(z->droite);
		if(y->pere != z){
			transplanter(&a,&y,&y->droite);
			y->droite=z->droite;
			y->droite->pere=y;
		}
		transplanter(&a,&z,&y);
		y->gauche=z->gauche;
		y->gauche->pere=y;
	}
}