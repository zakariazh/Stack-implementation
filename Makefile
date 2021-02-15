#
#

all:stack.o test.o
	@gcc stack.o test.o -o tst 
satck.o:stack.c stack.h
	@gcc -c stack.c -I${PWD}
test.o:test.c
	@gcc -c test.c -I${PWD}

clean:
	-@rm -f *.o tst
