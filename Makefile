OBJ      := obj
SRC      := src
INC      := include
CFLAGS   := -g -w -O2


all: main

# main + 5 módulos

main: $(OBJ)/MODULO1.o $(OBJ)/MODULO2.o $(OBJ)/MODULO3.o $(OBJ)/MODULO4.o $(OBJ)/MODULO5.o $(OBJ)/trab1.o
	gcc $(OBJ)/*.o -o trab1 -lm $(CFLAGS)

$(OBJ)/MODULO1.o: $(SRC)/MODULO1.c $(INC)/MODULO1.h
	gcc -c $(CFLAGS) "$(SRC)/MODULO1.c" -o "$(OBJ)/MODULO1.o"

$(OBJ)/MODULO2.o: $(SRC)/MODULO2.c $(INC)/MODULO2.h
	gcc -c $(CFLAGS) "$(SRC)/MODULO2.c" -o "$(OBJ)/MODULO2.o"

$(OBJ)/MODULO3.o: $(SRC)/MODULO3.c $(INC)/MODULO3.h
	gcc -c $(CFLAGS) "$(SRC)/MODULO3.c" -o "$(OBJ)/MODULO3.o"

$(OBJ)/MODULO4.o: $(SRC)/MODULO4.c $(INC)/MODULO4.h
	gcc -c $(CFLAGS) "$(SRC)/MODULO4.c" -o "$(OBJ)/MODULO4.o"

$(OBJ)/MODULO5.o: $(SRC)/MODULO5.c $(INC)/MODULO5.h
	gcc -c $(CFLAGS) "$(SRC)/MODULO5.c" -o "$(OBJ)/MODULO5.o"

$(OBJ)/trab1.o: trab1.c
	gcc -c $(CFLAGS) trab1.c -o "$(OBJ)/trab1.o"

run:
	./trab1

val:
	valgrind --leak-check=full -v ./trab1

clean:
	-rm $(OBJ)/*.o
	-rm trab1
