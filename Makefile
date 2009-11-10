CC=gcc
CFLAGS=-g -Wall

OBJECTS=rpn.o stack.o lex.o 

compile: $(OBJECTS)
	$(CC) $(CFLAGS) -o rpn $(OBJECTS)
	sh tests.sh

all: compile

clean:
	rm -f *.o rpn
