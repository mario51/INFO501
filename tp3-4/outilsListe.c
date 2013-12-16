#include "cellule.h"
#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

void afficherListe(Liste* liste){
	if(liste->tete != NULL){
		Cellule* c = liste->tete;
		while(c != NULL){
			if(c->predecesseur == NULL)
				printf("NULL      ");
			else
				printf("%s",c->predecesseur->cle);
			printf(" ---------- %s ---------- ",c->cle);
			if(c->successeur == NULL)
				printf("NULL      ");
			else
				printf("%s",c->successeur->cle);
			//printf("%s ---------- %s ---------- %s",c->predecesseur->cle,c->cle,c->successeur->cle);
			printf("\n");
			c=c->successeur;
		}
	}
	else
		printf("Erreur: rien a afficher!\n");
	
}

int compterListe(Liste* liste, int afficher){
	int i=0;
	if(liste->tete != NULL){
		Cellule* c = liste->tete;
		while(c!=NULL){
			i++;
			c=c->successeur;
		}
	}
	else
		i=0;
		
	if(afficher == 1)
		printf("La liste contient %d cellules\n",i);
	return i;
}