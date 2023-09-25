CC = gcc
LIBS = -lm 
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/vetop.o $(OBJ)/vet.o $(OBJ)/memlog.o
HDRS = $(INC)/vet.h $(INC)/memlog.h $(INC)/msgassert.h
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/vetop

all: mem perf gprof

mem: $(EXE)
	$(EXE) -s -p /tmp/somalog.out -l -d 5
	$(EXE) -i -p /tmp/prointlog.out -l -d 5
	$(EXE) -n -p /tmp/normalog.out -l -d 5

perf: $(EXE)
	$(EXE) -s -p /tmp/soma100.out  -x 100 -y 100
	$(EXE) -m -p /tmp/mult100.out  -x 100 -y 100
	$(EXE) -t -p /tmp/transp100.out  -x 100 -y 100
	$(EXE) -s -p /tmp/soma200.out  -x 200 -y 200
	$(EXE) -m -p /tmp/mult200.out  -x 200 -y 200
	$(EXE) -t -p /tmp/transp200.out  -x 200 -y 200
	$(EXE) -s -p /tmp/soma300.out  -x 300 -y 300
	$(EXE) -m -p /tmp/mult300.out  -x 300 -y 300
	$(EXE) -t -p /tmp/transp300.out  -x 300 -y 300
	$(EXE) -s -p /tmp/soma400.out  -x 400 -y 400
	$(EXE) -m -p /tmp/mult400.out  -x 400 -y 400
	$(EXE) -t -p /tmp/transp400.out  -x 400 -y 400
	$(EXE) -s -p /tmp/soma500.out  -x 500 -y 500
	$(EXE) -m -p /tmp/mult500.out  -x 500 -y 500
	$(EXE) -t -p /tmp/transp500.out  -x 500 -y 500
	$(EXE) -m -p /tmp/mult100log.out -l -x 100 -y 100

gprof: $(BIN)/matop
	$(EXE) -s -p /tmp/soma500gprof.out  -x 500 -y 500
	gprof $(EXE) gmon.out > /tmp/soma500gprof.txt
	$(EXE) -m -p /tmp/mult500gprof.out  -x 500 -y 500
	gprof $(EXE) gmon.out > /tmp/mult500gprof.txt
	$(EXE) -t -p /tmp/transp500gprof.out  -x 500 -y 500
	gprof $(EXE) gmon.out > /tmp/transp500gprof.txt
	

$(BIN)/vetop: $(OBJS)
	$(CC) -pg -o $(BIN)/vetop $(OBJS) $(LIBS)

$(OBJ)/vetop.o: $(HDRS) $(SRC)/vetop.c
	$(CC) $(CFLAGS) -o $(OBJ)/vetop.o $(SRC)/vetop.c 

$(OBJ)/vet.o: $(HDRS) $(SRC)/vet.c
	$(CC) $(CFLAGS) -o $(OBJ)/vet.o $(SRC)/vet.c 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c 
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out *grind*