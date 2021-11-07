##
 # Projet : Projet Tutoré 1.1 - Blocus
 # Description : Makefile
 # Auteurs : Théo CHOLLET, Tomy DA ROCHA
 # Date : 27/12/2020
 #
##

# Compilateur
CC = gcc
# Options de compilation
CFLAGS = -Wall -ansi -lgraph
# Objets à compiler
OBJECTS_C = blocus.c buttons.c cases.c display1.c display2.c display3.c display4.c grid.c player.c
OBJECTS_H = buttons.h cases.h defines.h display1.h display2.h display3.h display4.h grid.h player.h
# Exécutable généré
EXEC = blocus

# Compilation
blocus : $(OBJECTS_C) $(OBJECTS_H)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJECTS_C) $(OBJECTS_H)

# Exécution du programme
run:
	./$(EXEC)

# Nettoyage de la compilation
clean:
	rm -f *.o $(EXEC)