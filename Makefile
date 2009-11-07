CC=gcc
CFLAGS=-g -Wall

OBJECTS=rpn.o stack.o lex.o 

all: $(OBJECTS)
	$(CC) -o rpn $(OBJECTS)

clean:
	rm -f *.o rpn
