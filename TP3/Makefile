CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/heap.o $(OBJ)/main.o
HDRS = $(INC)/heap.h
CFLAGS = -Wall -c -I$(INC)
EXE = $(BIN)/main

all:$(EXE)
	$(EXE)
	
$(BIN)/main: $(OBJS)
	$(CC) -pg -o $(BIN)/main $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.c
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.c

$(OBJ)/heap.o: $(HDRS) $(SRC)/heap.c
	$(CC) $(CFLAGS) -o $(OBJ)/heap.o $(SRC)/heap.c
 	
clean:
	rm -f $(EXE) $(OBJS) gmon.out