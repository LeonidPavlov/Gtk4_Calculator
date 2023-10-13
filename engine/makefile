all: engine.o test.o engine.h ../stack/stack.o
	gcc -g engine.o test.o ../stack/stack.o -o test.out && ./test.out

test.o : test.c engine.h
	gcc -c test.c

engine.o : engine.c engine.h
	gcc -c engine.c

../stack/stack.o : ../stack/stack.c ../stack/stack.h
	(cd ../stack; make)

clear :
	rm -f *.o *.out

val :
	valgrind ./test.out

