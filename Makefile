OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -g -Wall -O3


all: main

main: $(OBJ)/Baralho.o $(OBJ)/trab1.o
	gcc $(OBJ)/*.o -o trab1 -lm $(CFLAGS)

$(OBJ)/Baralho.o: $(SRC)/Baralho.c $(INC)/Baralho.h
	gcc -c $(CFLAGS) "$(SRC)/Baralho.c" -o "$(OBJ)/Baralho.o"

$(OBJ)/trab1.o: trab1.c
	gcc -c $(CFLAGS) trab1.c -o "$(OBJ)/trab1.o"

run:
	./trab1

val:
	valgrind --leak-check=full -v ./trab1

clean:
	-rm $(OBJ)/*.o
	-rm trab1
