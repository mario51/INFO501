#ifndef ARBRE_H_INCLUDED
#define ARBRE_H_INCLUDED
#include "noeud.h"
//#include "outilsArbre.h"

typedef struct{
  Noeud* racine;
} Arbre ;

Arbre* creerArbre();
void detruireArbre(Arbre**);
void insererArbre(Arbre*,Noeud*);
Noeud* rechercherArbre(Arbre*,char*);
void supprimerArbre(Arbre*,Noeud*);


#endif // ARBRE_H_INCLUDED