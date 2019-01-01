CC=gcc
CFLAGS=-Wall -ansi -pedantic

main: main.o cat.o dog.o utils.o

main.o: main.c cat.h
cat.o: cat.c cat.h utils.h
dog.o: dog.c dog.h utils.h
utils.o: utils.c utils.h
