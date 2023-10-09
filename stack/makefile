all : stack.out 
	./stack.out

stack.out : stack.o test.o
	gcc stack.o test.o -o stack.out

test.o : test.c stack.h
	gcc -c test.c

stack.o : stack.c stack.h
	gcc -c stack.c

clear :
	rm -f *.o *.out
