CC=g++
CFLAGS=-std=c++0x -Wall -pedantic
CLIBS=
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
EXEC=../LFM.out

all: objects
	$(CC) $(CLIBS) $(OBJ) -o $(EXEC)

objects:
	$(CC) $(CFLAGS) -c $(SRC)

prod: mrproper all

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
	rm -rf *~
