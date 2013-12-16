#ifndef OUTILSTABLEHACHAGE_H_INCLUDED
#define OUTILSTABLEHACHAGE_H_INCLUDED
#include "tableHachage.h"
#include "cellule.h"
#include "outilsListe.h"
#include <math.h>
#include <string.h>

void afficherTableHachage(TableHachage*);
//int convertirChEntier(char**,int);
unsigned long convertirChEntier(char*);
int hachage(TableHachage*,unsigned long);
void compterTableHachage(TableHachage*);

#endif // OUTILSTABLEHACHAGE_H_INCLUDED