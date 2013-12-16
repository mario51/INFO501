CC = gcc -Wall -O3
OBJETS = main.o cellule.o liste.o outilsListe.o tableHachage.o outilsTableHachage.o noeud.o arbre.o outilsArbre.o

main : $(OBJETS)
	$(CC) -o main $(OBJETS) -lm

main.o : main.c cellule.h liste.h outilsListe.h tableHachage.h outilsTableHachage.h noeud.h arbre.h outilsArbre.h
	$(CC) -c main.c

cellule.o : cellule.c cellule.h
	$(CC) -c cellule.c

liste.o : liste.c liste.h
	$(CC) -c liste.c

outilsListe.o : outilsListe.c outilsListe.h
	$(CC) -c outilsListe.c

tableHachage.o : tableHachage.c tableHachage.h
	$(CC) -c tableHachage.c

outilsTableHachage.o : outilsTableHachage.c outilsTableHachage.h
	$(CC) -c outilsTableHachage.c

noeud.o : noeud.c noeud.h
	$(CC) -c noeud.c

arbre.o : arbre.c arbre.h
	$(CC) -c arbre.c

outilsArbre.o : outilsArbre.c outilsArbre.h
	$(CC) -c outilsArbre.c

clean :
	rm main $(OBJETS)
