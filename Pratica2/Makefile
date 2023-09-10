CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/TP.o 
HDRS = $(INC)/TP.h 
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/main

run: $(EXE)
	$(EXE) -f 10

$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/TP.o: $(HDRS) $(SRC)/TP.c
	$(CC) $(CFLAGS) -o $(OBJ)/TP.o $(SRC)/TP.c
 	
clean:
	rm -f $(EXE) $(OBJS) gmon.out