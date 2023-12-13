CC = gcc
LIBS = -lm 
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/pa11.o $(OBJ)/pageAVLtree.o $(OBJ)/AVLtree.o  
HDRS = $(INC)/pageAVLtree.h $(INC)/AVLtree.h 
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/pa11.out

all:$(EXE)
	
$(BIN)/pa11: $(OBJS)
	$(CC) -pg -o $(BIN)/pa11 $(OBJS) $(LIBS)

$(OBJ)/pa11.o: $(HDRS) $(SRC)/pa11.c
	$(CC) $(CFLAGS) -o $(OBJ)/pa11.o $(SRC)/pa11.c

$(OBJ)/AVLtree.o: $(HDRS) $(SRC)/AVLtree.c
	$(CC) $(CFLAGS) -o $(OBJ)/AVLtree.o $(SRC)/AVLtree.c 

$(OBJ)/pageAVLtree.o: $(HDRS) $(SRC)/pageAVLtree.c
	$(CC) $(CFLAGS) -o $(OBJ)/pageAVLtree.o $(SRC)/pageAVLtree.c 

clean:
	rm -f $(EXE) $(OBJS)  gmon.out