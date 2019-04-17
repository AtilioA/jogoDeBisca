CC=gcc
CFLAGS=-I.   -lm
DEPS = listaencadeada.h
OBJ =  proglista_encadeada.o listaencadeada.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

progListaArr: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
