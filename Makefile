CFLAGS = -g -Wall -pedantic -ansi -Wno-unused-result -D _BSD_SOURCE -O2
CC = gcc

D_OBS = ./observer
D_EXAMPLE = ./example
D_MODELS = ./example/models
D_TESTS = ./tests


# MAIN SAMPLE

$(D_EXAMPLE)/main.out: $(D_EXAMPLE)/main.c $(D_OBS)/observer.o $(D_OBS)/subject.o $(D_MODELS)/cat.o $(D_MODELS)/dog.o
	@$(CC) $(CFLAGS) -o $@ $^

$(D_MODELS)/cat.o: $(D_MODELS)/cat.c $(D_OBS)/observer.o $(D_OBS)/subject.o
	@$(CC) $(CFLAGS) $^ -c -o $@

$(D_MODELS)/dog.o: $(D_MODELS)/dog.c $(D_OBS)/observer.o
	@$(CC) $(CFLAGS) $^ -c -o $@


# LIB

$(D_OBS)/subject.o: $(D_OBS)/subject.c
	@$(CC) $(CFLAGS) $^ -c -o $@

$(D_OBS)/observer.o: $(D_OBS)/observer.c
	@$(CC) $(CFLAGS) $^ -c -o $@


# SAMPLE - FUNCTION POINTER

$(D_EXAMPLE)/function-pointer.out: $(D_EXAMPLE)/function-pointer.c
	@$(CC) $(CFLAGS) $^ -o $@


# CALLS

.PHONY: clean test

test: $(D_TESTS)/test-observable.out
	@./$^

example: $(D_EXAMPLE)/main.out
	@./$^

$(D_TESTS)/test-observable.out: $(D_TESTS)/test-observable.c
	@$(CC) $(CFLAGS) -o $@ $^
	./$@

clean:
	find . -name "*.out" -delete
	find . -name "*.o" -delete
