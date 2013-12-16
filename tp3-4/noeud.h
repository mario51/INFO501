#ifndef NOEUD_H_INCLUDED
#define NOEUD_H_INCLUDED

typedef struct No{
  char* cle;
  struct No* pere;
  struct No* gauche;
  struct No* droite;
} Noeud ;

Noeud* creerNoeud(char**);
void detruireNoeud(Noeud**);

#endif // 	NOEUD_H_INCLUDED