#ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED

typedef struct Cel{
  int cle;
  struct Cel* predecesseur;
  struct Cel* successeur;
} Cellule ;

Cellule* creerCellule(int);
void detruireCellule(Cellule**);

#endif // CELLULE_H_INCLUDED