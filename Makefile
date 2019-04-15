OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -lm -g -Wall -O3
EXE 	 := bisca


all: main

# Cria objetos de todos os arquivos de código-fonte para então linká-los no executável final
main: $(OBJ)/Baralho.o $(OBJ)/Jogo.o $(OBJ)/trab1.o
	gcc $(OBJ)/*.o -o bisca $(CFLAGS)

$(OBJ)/Baralho.o: $(SRC)/Baralho.c $(INC)/Baralho.h
	gcc -c $(CFLAGS) "$(SRC)/Baralho.c" -o "$(OBJ)/Baralho.o"

$(OBJ)/Jogo.o: $(SRC)/Jogo.c $(INC)/Jogo.h
	gcc -c $(CFLAGS) "$(SRC)/Jogo.c" -o "$(OBJ)/Jogo.o"

$(OBJ)/trab1.o: trab1.c
	gcc -c $(CFLAGS) trab1.c -o "$(OBJ)/trab1.o"

# Roda o programa
run:
	./$(EXE)

# Compila e roda o programa
voado: all run

# Roda o programa com valgrind e flags úteis
val:
	valgrind --leak-check=full -v ./$(EXE)
        #  --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file = valgrind-out.txt \
         ./executable exampleParam1

# Limpa objetos e o executável do programa
clean:
	-rm $(OBJ)/*.o
	-rm $(EXE)
