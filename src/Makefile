CC=g++
CFLAGS=-std=c++0x -I../include
CLIBS=-lm -lboost_regex -lpthread
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
EXEC=../LFM.out

DEBUGDIR=../Debug
DEBUGFLAGS=-Wall -pedantic
DEBUGARGS=../example.md

all: objects
	$(CC) $(OBJ) $(CLIBS) -o $(EXEC)

objects:
	$(CC) $(CFLAGS) -c $(SRC)

prod: mrproper all

debug: mrproper objects_debug
	$(CC) $(OBJ) $(CLIBS) -o $(EXEC) 2>&1 | tee $(DEBUGDIR)/linker.log
	valgrind --leak-check=full $(EXEC) $(DEBUGARGS) 2>&1 | tee $(DEBUGDIR)/valgrind.log

objects_debug:
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $(SRC) 2>&1 | tee $(DEBUGDIR)/compiler.log

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
	rm -rf *~
