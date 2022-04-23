CC=gcc
STD=-std=c99
CFLAGS=-g -Wall
BIN=bin


all: print.c iksOks.c gameMechanics.c header.h
	$(CC) $(CFLAGS) $(STD) -o $(BIN)/iksOks $^ -lm -lGL -lglfw

clean:
	rm $(BIN)/iksOks


