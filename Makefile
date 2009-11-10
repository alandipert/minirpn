CC=gcc
CFLAGS=-g -Wall
IPHONE_CC=/Developer/Platforms/iPhoneOS.platform/Developer/usr/bin/gcc-4.0
IPHONE_VER=3.0
IPHONE_CFLAGS=-arch armv6 -mthumb -isysroot /Developer/Platforms/iPhoneOS.platform/Developer/SDKs/iPhoneOS$(IPHONE_VER).sdk
IPHONE_IP=10.0.1.5

OBJECTS=rpn.o stack.o lex.o 

compile: $(OBJECTS)
	$(CC) $(CFLAGS) -o rpn $(OBJECTS)

iphone: CC=$(IPHONE_CC)
iphone: CFLAGS=$(IPHONE_CFLAGS)
iphone: compile

test: compile
	sh tests.sh

all: 
	compile

# scp binary to iphone, fake-sign it with ssh
# assumes you have your public key on the iphone
deploy: clean iphone
	ssh root@$(IPHONE_IP) 'rm /usr/local/bin/rpn'
	scp rpn root@$(IPHONE_IP):/usr/local/bin
	ssh root@$(IPHONE_IP) 'ldid -S /usr/local/bin/rpn'

clean:
	rm -f *.o rpn
