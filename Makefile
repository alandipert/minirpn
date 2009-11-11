CC=gcc
CFLAGS=-g -Wall
LIB=-lm

OBJECTS=rpn.o stack.o lex.o 

compile: $(OBJECTS)
	$(CC) $(CFLAGS) $(LIB) -o rpn $(OBJECTS)
	sh tests.sh

all: compile

clean:
	rm -f *.o rpn
