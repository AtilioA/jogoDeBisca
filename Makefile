OBJ      := obj
OBJS 	 := Baralho.o Jogo.o trab1.o
DEPS 	 := Baralho.h Jogo.h
SRC      := src
INC      := include
CFLAGS   := -lm -g
EXE 	 := bisca
CC		 := gcc


all: main

# Cria objetos de todos os arquivos de código-fonte para então linká-los no executável final
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)


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
