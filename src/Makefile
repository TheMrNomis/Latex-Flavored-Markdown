CC=g++
CFLAGS=-std=c++0x
CLIBS=
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)
EXEC=../LFM.out

all: objects
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC) $(CLIBS)

objects:
	$(CC) $(CFLAGS) -c $(SRC)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)
	@rm -rf *~
