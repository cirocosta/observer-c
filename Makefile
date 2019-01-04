CFLAGS = -g -Wall -pedantic -ansi -Wno-unused-result -O2
CC = gcc

D_OBS = ./observer
D_EXAMPLE = ./example
D_TESTS = ./tests


$(D_EXAMPLE)/main: $(D_EXAMPLE)/main.o $(D_OBS)/observer.o $(D_OBS)/subject.o $(D_EXAMPLE)/cat.o $(D_EXAMPLE)/dog.o $(D_EXAMPLE)/utils.o

$(D_EXAMPLE)/main.o: $(D_EXAMPLE)/main.c $(D_EXAMPLE)/cat.h $(D_EXAMPLE)/dog.h
$(D_EXAMPLE)/cat.o: $(D_EXAMPLE)/cat.c $(D_EXAMPLE)/cat.h $(D_EXAMPLE)/utils.h
$(D_EXAMPLE)/dog.o: $(D_EXAMPLE)/dog.c $(D_EXAMPLE)/dog.h $(D_EXAMPLE)/cat.h $(D_EXAMPLE)/utils.h $(D_OBS)/observer.h
$(D_EXAMPLE)/utils.o: $(D_EXAMPLE)/utils.c $(D_EXAMPLE)/utils.h
$(D_OBS)/subject.o: $(D_OBS)/subject.c $(D_OBS)/subject.h $(D_OBS)/observer.h
$(D_OBS)/observer.o: $(D_OBS)/observer.c $(D_OBS)/observer.h

# CALLS

.PHONY: clean test

test: $(D_TESTS)/test-observable.out
	@./$^

$(D_TESTS)/test-observable.out: $(D_TESTS)/test-observable.c
	@$(CC) $(CFLAGS) -o $@ $^
	./$@

clean:
	rm -f ./example/main
	find . -name "*.o" -delete
