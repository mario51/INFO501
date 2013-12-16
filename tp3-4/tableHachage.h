#ifndef TABLEHACHAGE_H_INCLUDED
#define TABLEHACHAGE_H_INCLUDED

#include "liste.h"
#include "cellule.h"

typedef struct{
  Liste** listes;
  int taille;
} TableHachage ;

TableHachage* creerTableHachage(int);
void detruireTableHachage(TableHachage**);
void insererHachage(TableHachage*,char* /*,int*/);
Cellule* rechercherHachage(TableHachage*, char* /*, int*/);
void supprimerHachage(TableHachage*, char* /*, int*/);

#endif // TABLEHACHAGE_H_INCLUDED