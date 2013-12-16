#include "liste.h"
#include "tableHachage.h"
#include "outilsTableHachage.h"
#include "cellule.h"
#include <stdio.h>
#include <stdlib.h>

TableHachage* creerTableHachage(int taille){
	TableHachage* table = malloc(sizeof(table));
	table->listes= malloc(sizeof(Liste)*taille);
	table->taille= taille;

	int i;
	for(i=0;i<taille;i++){
		table->listes[i]=creerListe();
	}

	//table->listes[1]= creerListe();
	
	return table; 
}

void detruireTableHachage(TableHachage** tableHachage){
	(*tableHachage)->listes= NULL;
	(*tableHachage)->taille=0;
	free((*tableHachage)->listes);
	(*tableHachage)=NULL;
	free(*tableHachage);
}

void insererHachage(TableHachage* table, char* mot/*, int tailleMot*/){
	unsigned long i;
	i=convertirChEntier(mot/*,tailleMot*/);
	//printf("%o\n",i);
	i=hachage(table,i);
	//printf("%o\n",i);
	inserer(table->listes[i],creerCellule(mot));
}

Cellule* rechercherHachage(TableHachage* table, char* mot/*, int tailleMot*/){
	int i;
	i=hachage(table,convertirChEntier(mot/*,tailleMot*/));
	return rechercher(table->listes[i],mot);
}

void supprimerHachage(TableHachage* table, char* mot/*, int tailleMot*/){
	int i;
	i=hachage(table,convertirChEntier(mot/*,tailleMot*/));
	Cellule* c = rechercher(table->listes[i],mot);
	if (c != NULL)
		supprimer(table->listes[i],c);
	else
		printf("Mot innexistant dans la liste.\n");
}

