CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/listaencadeada.o $(OBJ)/graph.o
HDRS = $(INC)/listaencadeada.h $(INC)/graph.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run: $(EXE)
	$(EXE) -d

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/listaencadeada.o: $(HDRS) $(SRC)/listaencadeada.c
	$(CC) $(CFLAGS) -o $(OBJ)/listaencadeada.o $(SRC)/listaencadeada.c

$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.c
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.c
 	
clean:
	rm -f $(EXE) $(OBJS) gmon.out