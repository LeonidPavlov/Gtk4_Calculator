all : stack.o test.o
	gcc stack.o test.o -o stack.out && ./stack.out

test.o : test.c stack.h
	gcc -c test.c

stack.o : stack.c stack.h
	gcc -c stack.c

clear :
	rm -f *.o *.out

val:
	valgrind ./stack.out
