#ifndef OUTILSARBRE_H_INCLUDED
#define OUTILSARBRE_H_INCLUDED
#include "arbre.h"
#include "noeud.h"
#include "outilsTableHachage.h"

void transplanter(Arbre**, Noeud**,Noeud**);
Noeud* minimumArbre(Noeud*);
//void afficherArbreIteratif(Arbre*);
void afficherArbreRecursif(Noeud*);

#endif // OUTILSARBRE_H_INCLUDED