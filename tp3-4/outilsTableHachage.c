#include "liste.h"
#include "tableHachage.h"
#include "outilsListe.h"
#include "outilsTableHachage.h"
#include "cellule.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void afficherTableHachage(TableHachage* table){
	int i;

	for (i = 0; i < table->taille; i++)
	{
		printf("Liste: %d\n",i);
		afficherListe(table->listes[i]);
		printf("\n---------------------------------------------------------------------\n\n");
	}
}

/*int convertirChEntier(char** mot, int taille){
	int i;
	int total;
	total = 0;
	for (i = 0; i < taille; i++)
	{
		//printf("%c : %d\n",mot[i],(int)mot[i]);
		total = total + (int)mot[i] * pow(128,taille-1-i);
	}
	return total;
}*/

unsigned long convertirChEntier(char* mot){
	int i;
	unsigned long total;
	total = 0;
	for (i = 0; i < strlen(mot); i++)
	{
		//printf("%c\n",mot[i]);
		total = total + (int)mot[i] * pow(128,strlen(mot)-1-i);
	}
	return total;
}

int hachage(TableHachage* table, unsigned long valeur){
	return valeur % table->taille;
}

void compterTableHachage(TableHachage* table){
	int i=0;
	int total=0;
	for(i;i<table->taille;i++){
		printf("Liste %d : ",i);
		total += compterListe(table->listes[i]);
	}
	printf("Nombre total de mots dans la table de hachage: %d\n", total);
}