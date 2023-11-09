CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/metodos.o $(OBJ)/main.o $(OBJ)/mainteste.o $(OBJ)/graph.o
HDRS = $(INC)/metodos.h $(INC)/graph.h
CFLAGS = -Wall -c -I $(INC)
EXE = $(BIN)/mainteste

all:$(EXE)
	$(EXE)

$(BIN)/mainteste: $(OBJS)
	$(CC) -pg -o $(BIN)/mainteste $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/mainteste.o: $(HDRS) $(SRC)/mainteste.c
	$(CC) $(CFLAGS) -o $(OBJ)/mainteste.o $(SRC)/mainteste.c

$(OBJ)/metodos.o: $(HDRS) $(SRC)/metodos.c
	$(CC) $(CFLAGS) -o $(OBJ)/metodos.o $(SRC)/metodos.c

$(OBJ)/graph.o: $(HDRS) $(SRC)/graph.c
	$(CC) $(CFLAGS) -o $(OBJ)/graph.o $(SRC)/graph.c
 	
clean:
	rm -f $(EXE) $(OBJS) gmon.out