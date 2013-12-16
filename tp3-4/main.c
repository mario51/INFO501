#include <stdio.h>
#include <stdlib.h>
#include "cellule.h"
#include "liste.h"
#include "outilsListe.h"
#include "tableHachage.h"
#include "noeud.h"
#include "arbre.h"
#include "outilsArbre.h"
#include <math.h>
#include "outilsTableHachage.h"
#include <string.h>
#include <time.h>


int main(){

	int saisieType = -1;
	int saisieDico = -1;
	char saisieFile[100];
	int saisieTaille = -1;
	clock_t t1, t2;
	float temps;
	char motFichier[50];
	char nomFichier[50];
	int nbrMots = 0;
	FILE* fichier = NULL;
	
	printf("--------------\n");
	printf("Choix du type:\n1 = Liste chainee, Table Hachage, Arbre binaires de recherche\n2 = Demonstration avec les dicos et tous les types\n");
	printf("--------------\nVotre choix : ");

	scanf("%d",&saisieType);
	
	if(saisieType == 2){ // Demo
		printf("Choix du dico :\n1 = texte1.txt\n2 = texte2.txt\n3 = dico_france-quebec.txt\n4 = histoire_quebec.txt\n5 = dico_ae.txt\n6 = dico.txt\nVotre choix : ");
		scanf("%d",&saisieDico);
		
		printf("Taille de la table de hachage : ");
		scanf("%d",&saisieTaille);
		
		printf("\n\n");
		
		switch(saisieDico){
			case 1:
				fichier = fopen("texte1.txt","r");
				break;
			case 2:
				fichier = fopen("texte2.txt","r");
				break;
			case 3:
				fichier = fopen("dico_france-quebec.txt","r");
				break;
			case 4:
				fichier = fopen("histoire_quebec.txt","r");
				break;
			case 5:
				fichier = fopen("dico_ae.txt","r");
				break;
			case 6:
				fichier = fopen("dico.txt","r");
				break;
		}
		
		Liste* liste = creerListe();

		t1 = clock();
		while(fscanf(fichier,"%s",motFichier) != NULL){
			Cellule* c = rechercher(liste,motFichier);
			if(c==NULL){
				inserer(liste,creerCellule(motFichier));
			}

			if(feof(fichier)){
				break;
			}
			nbrMots++;
		}
		t2 = clock();
		temps = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("Le fichier contient %d mots au total.\n",nbrMots);
		printf("Le fichier contient %d mots différents\n",compterListe(liste,0));
		printf("Temps d'execution par une liste chainee : %f sec\n",temps);
		fclose(fichier);
		detruireListe(&liste);
		
		
		TableHachage* tableHachage = creerTableHachage(saisieTaille);
		fichier = NULL;
		switch(saisieDico){
			case 1:
				fichier = fopen("texte1.txt","r");
				break;
			case 2:
				fichier = fopen("texte2.txt","r");
				break;
			case 3:
				fichier = fopen("dico_france-quebec.txt","r");
				break;
			case 4:
				fichier = fopen("histoire_quebec.txt","r");
				break;
			case 5:
				fichier = fopen("dico_ae.txt","r");
				break;
			case 6:
				fichier = fopen("dico.txt","r");
				break;
		}
		
		t1 = clock();
		while(fscanf(fichier,"%s",motFichier) != NULL){
			insererHachage(tableHachage,motFichier);

			if(feof(fichier)){
				break;
			}
		}
		t2 = clock();
		temps = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("Temps d'execution par une table de hachage : %f sec\n",temps);
		fclose(fichier);
		detruireTableHachage(&tableHachage);
		
		
		Arbre* arbre = creerArbre();
		fichier = NULL;
		switch(saisieDico){
			case 1:
				fichier = fopen("texte1.txt","r");
				break;
			case 2:
				fichier = fopen("texte2.txt","r");
				break;
			case 3:
				fichier = fopen("dico_france-quebec.txt","r");
				break;
			case 4:
				fichier = fopen("histoire_quebec.txt","r");
				break;
			case 5:
				fichier = fopen("dico_ae.txt","r");
				break;
			case 6:
				fichier = fopen("dico.txt","r");
				break;
		}
		
		t1 = clock();
		while(fscanf(fichier,"%s",motFichier) != NULL){
			Noeud* noeud = rechercherArbre(arbre,motFichier);
			if(noeud == NULL){
				Noeud* n = creerNoeud(motFichier);
				insererArbre(arbre,n);
			}
			
			if(feof(fichier)){
				break;
			}
		}
		t2 = clock();
		temps = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("Temps d'execution par un arbre binaire de recherche : %f sec\n",temps);
		fclose(fichier);
		detruireArbre(&arbre);
	}
	else if(saisieType == 1){ // Liste
		printf("Entrez le nom du fichier : ");
		scanf("%s",nomFichier);
		
		printf("Taille de la table de hachage : ");
		scanf("%d",&saisieTaille);
		
		printf("\n\n");
		
		
		Liste* liste = creerListe();

		fichier = fopen(nomFichier,"r");
		t1 = clock();
		while(fscanf(fichier,"%s",motFichier) != NULL){
			Cellule* c = rechercher(liste,motFichier);
			if(c==NULL){
				inserer(liste,creerCellule(motFichier));
			}
			
			nbrMots++;
			
			if(feof(fichier)){
				break;
			}		
		}
		t2 = clock();
		temps = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("Le fichier contient %d mots au total.\n",nbrMots);
		printf("Le fichier contient %d mots différents\n",compterListe(liste,0));
		printf("Temps d'execution par une liste chainee : %f sec\n",temps);
		fclose(fichier);
		detruireListe(&liste);
		
		
		TableHachage* tableHachage = creerTableHachage(saisieTaille);
		fichier = fopen(nomFichier,"r");
		t1 = clock();
		while(fscanf(fichier,"%s",motFichier) != NULL){
			insererHachage(tableHachage,motFichier);

			if(feof(fichier)){
				break;
			}
		}
		t2 = clock();
		temps = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("Temps d'execution par une table de hachage : %f sec\n",temps);
		fclose(fichier);
		detruireTableHachage(&tableHachage);
		
		
		Arbre* arbre = creerArbre();
		fichier = fopen(nomFichier,"r");
		t1 = clock();
		while(fscanf(fichier,"%s",motFichier) != NULL){
			Noeud* noeud = rechercherArbre(arbre,motFichier);
			if(noeud == NULL){
				Noeud* n = creerNoeud(motFichier);
				insererArbre(arbre,n);
			}
			
			if(feof(fichier)){
				break;
			}
		}
		t2 = clock();
		temps = (float)(t2-t1)/CLOCKS_PER_SEC;
		printf("Temps d'execution par un arbre binaire de recherche : %f sec\n",temps);
		fclose(fichier);
		detruireArbre(&arbre);		
	}
	
	return 0;
}