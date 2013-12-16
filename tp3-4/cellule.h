#ifndef CELLULE_H_INCLUDED
#define CELLULE_H_INCLUDED

typedef struct Cel{
  char* cle;
  struct Cel* predecesseur;
  struct Cel* successeur;
} Cellule ;

Cellule* creerCellule(char**);
void detruireCellule(Cellule**);

#endif // CELLULE_H_INCLUDED