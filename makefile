flags=`pkg-config --cflags gtk4`
libs=`pkg-config --libs gtk4`
file=Calculator_GTK_4

all : dist/${file}.out
	./dist/${file}.out

dist/${file}.out : ${file}.o
	mkdir dist && gcc ${flags} ${file}.o ${libs} -o dist/${file}.out

${file}.o : ${file}.c
	gcc ${flags} -c ${file}.c ${libs}

clear :
	rm -rf *.o *.out
