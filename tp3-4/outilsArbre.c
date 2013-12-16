#include "outilsArbre.h"
#include "outilsTableHachage.h"
#include "noeud.h"
#include "arbre.h"
#include <stdio.h>
#include <stdlib.h>

void transplanter(Arbre** a, Noeud** u, Noeud** v){
	if((*u)->pere==NULL)
		(*a)->racine=v;
	else if((*u)==(*u)->pere->gauche)
		(*u)->pere->gauche=v;
	else
		(*u)->pere->droite=v;
	if((*v)!=NULL)
		(*v)->pere=(*u)->pere;
}

Noeud* minimumArbre(Noeud* x){
	while(x->gauche!=NULL)
		x=x->gauche;
	return x;
}

/*void afficherArbreIteratif(Arbre* arbre){
	Noeud* x = arbre->racine;
	if(x!=NULL){
		int n=20;
    	Pile* p = creerPile(n);
    	empiler(p,x);
    	while(!pileVide(p)){
    		x=depiler(p);
    		printf("%s\n",x->cle);
    		if(x->droite!=NULL)
    			empiler(p,x->droite);
    		if(x->gauche!=NULL)
    			empiler(p,x->gauche);
    	}
    	detruirePile(&p);	
	}
	
}*/

void afficherArbreRecursif(Noeud* x){
	if(x!=NULL){
		printf("%s\n",x->cle);
		afficherArbreRecursif(x->gauche);
		afficherArbreRecursif(x->droite);
	}
}