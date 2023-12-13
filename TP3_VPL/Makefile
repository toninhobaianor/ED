CC = gcc
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/heap.o $(OBJ)/tp3.o
HDRS = $(INC)/heap.h
CFLAGS = -Wall -c -I$(INC)

EXE = $(BIN)/tp3.out

all:$(EXE)
	
$(BIN)/tp3: $(OBJS)
	$(CC) -pg -o $(BIN)/tp3 $(OBJS) $(LIBS)

$(OBJ)/tp3.o: $(HDRS) $(SRC)/tp3.c
	$(CC) $(CFLAGS) -o $(OBJ)/tp3.o $(SRC)/tp3.c

$(OBJ)/heap.o: $(HDRS) $(SRC)/heap.c
	$(CC) $(CFLAGS) -o $(OBJ)/heap.o $(SRC)/heap.c
 	
clean:
	rm -f $(EXE) $(OBJS) gmon.out