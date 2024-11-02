CC = gcc
CFLAGS = -std=c99 -Wall -Wpedantic -Werror -o3 -Wno-unused-function #-luuid
OS := $(shell uname)

mkBinDir := $(shell mkdir -p bin)
mkObjDir := $(shell mkdir -p obj)

BIN = ./bin/example.run

OBJ = ./obj/error.o

default: reset $(BIN)
ifeq ($(OS),Darwin) 
	$(BIN)
else 
	valgrind --track-origins=yes --leak-check=full $(BIN)  
endif

reset: clear $(BIN)

run: reset $(BIN)
	$(BIN)

$(BIN): $(OBJ) ./obj/example.o
	$(CC) $(CFLAGS) $(OBJ) ./obj/example.o -o $(BIN)

$(OBJ): ./src/error.c
	$(CC) $(FLAGS) -c ./src/error.c -o ./obj/error.o

./obj/example.o: ./src/example.c ./src/error.h
	$(CC) $(CFLAGS) -c ./src/example.c -o ./obj/example.o
	
clear: clear-bin

clear-bin:
	-rm ./bin/*
