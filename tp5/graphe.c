#include "graphe.h"
#include "liste.h"
#include "outilsListe.h"
#include "cellule.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "file.h"

Liste* creerListesAdjacences(char* nomFichier){
	Liste** liste = NULL;
	FILE *fichier = fopen(nomFichier,"r");
	
	int indice;
	int valeur;
	int nbrSommet;
	char mot[100];
	int oriente;
	
	if(fichier != NULL){
		fscanf(fichier,"%s %d",mot,&nbrSommet);

		
		liste = malloc(sizeof(Liste) * nbrSommet);
		
		int i;
		for(i=0;i<nbrSommet;i++){
			liste[i]=creerListe();
		}
			
		fscanf(fichier,"%s %d",mot,&oriente);
		fscanf(fichier,"%s %d",mot,&valeur);
		fscanf(fichier,"%s %d",mot,&valeur);
		fscanf(fichier,"%s",mot);

		
		
		Cellule* c1 = NULL;
		Cellule* c2 = NULL;
		i=0;
		for(i;i<23;i++){
			fscanf(fichier,"%d %d",&indice,&valeur);
			
			if(c1 != NULL && c2!=NULL && indice == c1->cle && valeur == c2->cle)
				break;
				
			c1 = creerCellule(indice);
			c2 = creerCellule(valeur);
			
			inserer(liste[indice],c2);
			
			if(oriente==0)
				inserer(liste[valeur],c1);
		}		
	}
	fclose(fichier);
	return liste;
}

void afficherListesAdjacences(Graphe* graphe){
	printf("Liste d'adjacences :\n");
	if(graphe->listeAdj != NULL){
		int i=0;
		int nombre=0;
		for(i;i<graphe->nbrSommet;i++){
			Cellule* c = graphe->listeAdj[i]->tete;
			printf("Liste %d :\t",i);
			while(c != NULL){
				printf("%d",c->cle);
				c=c->successeur;
				
				if(c!=NULL)
					printf(" - ");
			}
			printf("\n");
		}
	}
	printf("\n");
}

int* creerMatriceAdjacences(char* nomFichier){
	int** matrice = NULL;
	
	FILE *fichier = fopen(nomFichier,"r");

	int indice;
	int valeur;
	int nbrSommet;
	char mot[100];
	if(fichier != NULL){
		fscanf(fichier,"%s %d",mot,&nbrSommet);
		
		int i;
		matrice = (int*)malloc(sizeof(int*) * nbrSommet);
		
		for(i=0;i<nbrSommet;i++){
			matrice[i]= (int*) calloc(nbrSommet,sizeof(int));
		}
			
		fscanf(fichier,"%s %d",mot,&valeur);
		fscanf(fichier,"%s %d",mot,&valeur);
		fscanf(fichier,"%s %d",mot,&valeur);
		fscanf(fichier,"%s",mot);

		for(i=0;i<23;i++){
			fscanf(fichier,"%d %d",&indice,&valeur);
			matrice[indice][valeur]=1;
			matrice[valeur][indice]=1;
		}
	}
	fclose(fichier);
	return matrice;
}

void afficherMatriceAdjacences(Graphe* graphe){
	printf("Matrice d'adjacences : \n");
	int i,j;
	for(i=0;i<graphe->nbrSommet;i++){
		for(j=0;j<graphe->nbrSommet;j++){
			printf("%d ",graphe->matriceAdj[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

Graphe* creerGraphe(char* nomFichier){
	int i;
	Graphe* graphe = malloc(sizeof(Graphe));
	
	FILE *fichier = fopen(nomFichier,"r");
	
	int nbrSommet;
	int oriente;
	int value;
	int complet;
	char mot[100];
	
	fscanf(fichier,"%s %d",mot,&nbrSommet);
	fscanf(fichier,"%s %d",mot,&oriente);
	fscanf(fichier,"%s %d",mot,&value);
	fscanf(fichier,"%s %d",mot,&complet);
	
	graphe->nbrSommet = nbrSommet;
	graphe->oriente = oriente;
	graphe->value = value;
	graphe->complet = complet;
	
	graphe->listeAdj = creerListesAdjacences(nomFichier);
	graphe->matriceAdj = creerMatriceAdjacences(nomFichier);

	graphe->tabSommet = (Sommet*) malloc(sizeof(Sommet) * graphe->nbrSommet);

	for(i=0;i<graphe->nbrSommet;i++){
		graphe->tabSommet[i] = creerSommet();
		graphe->tabSommet[i]->cle=i;
	}
	
	fclose(fichier);
	
	return graphe;
}

void detruireGraphe(Graphe** graphe){
	(*graphe)->nbrSommet = 0;
	(*graphe)->oriente = 0;
	(*graphe)->value = 0;
	(*graphe)->complet = 0;
	(*graphe)->listeAdj = NULL;
	(*graphe)->matriceAdj = NULL;
	detruireTableauSommet((*graphe)->tabSommet);
	free((*graphe)->listeAdj);
	free((*graphe)->matriceAdj);
	free(*graphe);
}

Sommet* creerSommet(){
	Sommet* sommet;
	sommet = malloc(sizeof(Sommet));

	sommet->couleur='b';
	sommet->pere = NULL;
	sommet->distance = 0;
	sommet->debut=0;
	sommet->fin=0;

	return sommet;
}

void detruireTableauSommet(Sommet** sommet){
	(*sommet)=NULL;
	free(*sommet);
}


void parcoursLargeur(Graphe* g, Sommet* s){
	int i;
	for(i=0;i<g->nbrSommet;i++){
		g->tabSommet[i]->distance=10000;
		g->tabSommet[i]->couleur='b';
		g->tabSommet[i]->pere=NULL;
	}
	s->distance = 0;
	s->couleur = 'g';
	File* f = creerFile(g->nbrSommet);

	enfiler(f,s);

	while(!fileVide(f)){
		Sommet* u = defiler(f);

		Cellule* j = g->listeAdj[u->cle]->tete;

		for(j; j != NULL; j = j->successeur){
			if (g->tabSommet[j->cle]->couleur == 'b'){
				g->tabSommet[j->cle]->couleur='g';
				g->tabSommet[j->cle]->distance = u->distance + 1;
				g->tabSommet[j->cle]->pere = u;
				enfiler(f,g->tabSommet[j->cle]);
			}
		}
		u->couleur = 'n';
	}
	detruireFile(f);
}

void afficherChemin(Graphe* g, Sommet* origine){

	printf("Parcours en largeur du graphe a partir du sommet %d :\n",origine->cle);
	int i;
	for(i=0;i<g->nbrSommet;i++){
		printf("Sommet %i :\t%d\n",i,g->tabSommet[i]->distance);
	}
	printf("\n");
}

void parcoursProfondeur(Graphe* g){
	int i, date;
	for(i=0;i<g->nbrSommet;i++){
		g->tabSommet[i]->couleur='b';
		g->tabSommet[i]->pere=NULL;
	}
	date = 0;
	for(i=0;i<g->nbrSommet;i++){
		if(g->tabSommet[i]->couleur == 'b'){
			visiterPP(g,g->tabSommet[i],&date);
		}
	}
}

void visiterPP(Graphe* g, Sommet* u, int* date){
	u->couleur='g';
	*date=*date+1;
	u->debut=*date;
	Cellule* j = g->listeAdj[u->cle]->tete;

	for(j ; j != NULL; j = j->successeur){
		if(g->tabSommet[j->cle]->couleur == 'b'){
			g->tabSommet[j->cle]->pere = u;
			visiterPP(g,g->tabSommet[j->cle],date);
		}
	}
	*date=*date+1;
	u->fin =*date;
	u->couleur = 'n';
}

void afficherParcoursProfondeur(Graphe* g){
	printf("Parcours en profondeur du graphe :\n");
	int i;
	for(i=0;i<g->nbrSommet;i++){
		printf("Sommet %i:\t debut: %d \t fin:%d\n",g->tabSommet[i]->cle,g->tabSommet[i]->debut,g->tabSommet[i]->fin);
	}
	printf("\n");
}