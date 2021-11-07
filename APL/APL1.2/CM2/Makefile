# Compilateur
CC = gcc
# Options de compilation
CFLAGS = -Wall -ansi
# Objets à compiler
OBJECTS_C = p2.c ma_sqrt.c
OBJECTS_H = ma_sqrt.h
# Exécutable généré (Choisir entre p1, p2, p3)
EXEC = p2

# Compilation (Changer p* selon le programme a testé)
p2 : $(OBJECTS_C) $(OBJECTS_H)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJECTS_C) $(OBJECTS_H)

# Exécution du programme
run:
	./$(EXEC)

# Nettoyage de la compilation
clean:
	rm -f *.o $(EXEC)