CC = gcc
LIBS = -lm 
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)vet/.o $(OBJ)/analisamem.o
TOBJS = $(OBJ)/vet.o $(OBJ)/testevet.o
HDRS = $(INC)/vet.h $(INC)/msgassert.h
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/analisamem

TEST = $(BIN)/testevet

all: test use

use: $(EXE)
	if test -d /tmp/out; then rm -rf /tmp/out; fi
	mkdir /tmp/out
	mkdir /tmp/out/teste
	fixaddr/fixaddr.csh teste/multlog.out /tmp/out
	$(EXE) -i /tmp/out/teste/multlog.out.fixed -p /tmp/out/mult
	fixaddr/fixaddr.csh teste/somalog.out /tmp/out
	$(EXE) -i /tmp/out/teste/somalog.out.fixed -p /tmp/out/soma
	fixaddr/fixaddr.csh teste/transplog.out /tmp/out
	$(EXE) -i /tmp/out/teste/transplog.out.fixed -p /tmp/out/transp
	gnuplot /tmp/out/*.gp
	ls /tmp/out/

test: $(TEST)
	$(BIN)/testevet

bin: $(EXE) $(TEST)

$(BIN)/testevet: $(TOBJS)
	$(CC) -g -o $(BIN)/testevet $(TOBJS) $(LIBS)

$(BIN)/analisamem: $(OBJS)
	$(CC) -g -o $(BIN)/analisamem $(OBJS) $(LIBS)

$(OBJ)/analisamem.o: $(HDRS) $(SRC)/analisamem.c
	$(CC) $(CFLAGS) -o $(OBJ)/analisamem.o $(SRC)/analisamem.c 

$(OBJ)/testevet.o: $(HDRS) $(SRC)/testevet.c
	$(CC) $(CFLAGS) -o $(OBJ)/testevet.o $(SRC)/testevet.c 

$(OBJ)/vet.o: $(HDRS) $(SRC)/vet.c
	$(CC) $(CFLAGS) -o $(OBJ)/vet.o $(SRC)/vet.c 

clean:
	rm -f $(EXE) $(TEST) $(OBJS)  $(TOBJS)