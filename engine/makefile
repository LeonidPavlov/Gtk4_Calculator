all: engine.o test.o engine.h
	gcc engine.o test.o -o test.out && ./test.out

test.o : test.c engine.h
	gcc -c test.c

engine.o : engine.c engine.h
	gcc -c engine.c

clear :
	rm -f *.o *.out
