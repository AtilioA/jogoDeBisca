OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -lm -g -w -O3
EXE 	 := bisca


# Cria objetos de todos os arquivos de código-fonte para então linká-los no executável final
main: $(OBJ)/Cartas.o $(OBJ)/MaosSimples.o $(OBJ)/BaralhoEncadeado.o $(OBJ)/IA2Jogadores.o $(OBJ)/IA4Jogadores.o $(OBJ)/PartidaCircular.o $(OBJ)/Jogo.o $(OBJ)/trab1.o
	gcc $(OBJ)/*.o -o $(EXE) $(CFLAGS)

$(OBJ)/Cartas.o: $(SRC)/Cartas.c $(INC)/Cartas.h
	gcc -c $(CFLAGS) "$(SRC)/Cartas.c" -o "$(OBJ)/Cartas.o"

$(OBJ)/MaosSimples.o: $(SRC)/MaosSimples.c $(INC)/MaosSimples.h
	gcc -c $(CFLAGS) "$(SRC)/MaosSimples.c" -o "$(OBJ)/MaosSimples.o"

$(OBJ)/BaralhoEncadeado.o: $(SRC)/BaralhoEncadeado.c $(INC)/BaralhoEncadeado.h
	gcc -c $(CFLAGS) "$(SRC)/BaralhoEncadeado.c" -o "$(OBJ)/BaralhoEncadeado.o"

$(OBJ)/IA2Jogadores.o: $(SRC)/IA2Jogadores.c $(INC)/IA2Jogadores.h
	gcc -c $(CFLAGS) "$(SRC)/IA2Jogadores.c" -o "$(OBJ)/IA2Jogadores.o"

$(OBJ)/IA4Jogadores.o: $(SRC)/IA4Jogadores.c $(INC)/IA4Jogadores.h
	gcc -c $(CFLAGS) "$(SRC)/IA4Jogadores.c" -o "$(OBJ)/IA4Jogadores.o"

$(OBJ)/PartidaCircular.o: $(SRC)/PartidaCircular.c $(INC)/PartidaCircular.h
	gcc -c $(CFLAGS) "$(SRC)/PartidaCircular.c" -o "$(OBJ)/PartidaCircular.o"

$(OBJ)/Jogo.o: $(SRC)/Jogo.c $(INC)/Jogo.h
	gcc -c $(CFLAGS) "$(SRC)/Jogo.c" -o "$(OBJ)/Jogo.o"

$(OBJ)/trab1.o: trab1.c
	gcc -c $(CFLAGS) trab1.c -o "$(OBJ)/trab1.o"

# Roda o programa
run:
	./$(EXE)

# Compila e roda o programa
voado: clean main run

# Roda o programa com valgrind e flags úteis
val:
	valgrind --leak-check=full -v --show-leak-kinds=all --track-origins=yes --verbose ./$(EXE)

# Roda o programa com valgrind sem flags
valzin:
	valgrind ./$(EXE)

# Roda o programa com valgrind e salva resultados num .txt
valtxt:
	valgrind --leak-check=full -v --show-leak-kinds=all --track-origins=yes --verbose --log-file="valgrind-out.txt" ./$(EXE)

# Limpa objetos e o executável do programa (para Windows)
cleanW:
	del /F/Q/S "$(OBJ)\*.o"
	del /F/Q/S $(EXE).exe

# Limpa objetos e o executável do programa (para Linux)
clean:
	-rm $(OBJ)/*.o
	-rm $(EXE)
