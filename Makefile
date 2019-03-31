OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -g -w -O3
EXE 	 := bisca


all: main

main: $(OBJ)/Baralho.o $(OBJ)/Jogo.o $(OBJ)/trab1.o
	gcc $(OBJ)/*.o -o bisca -lm $(CFLAGS)

$(OBJ)/Baralho.o: $(SRC)/Baralho.c $(INC)/Baralho.h
	gcc -c $(CFLAGS) "$(SRC)/Baralho.c" -o "$(OBJ)/Baralho.o"

$(OBJ)/Jogo.o: $(SRC)/Jogo.c $(INC)/Jogo.h
	gcc -c $(CFLAGS) "$(SRC)/Jogo.c" -o "$(OBJ)/Jogo.o"

$(OBJ)/trab1.o: trab1.c
	gcc -c $(CFLAGS) trab1.c -o "$(OBJ)/trab1.o"

run:
	./$(EXE)

voado: all run

val:
	valgrind --leak-check=full -v ./$(EXE)

clean:
	-rm $(OBJ)/*.o
	-rm $(EXE)
