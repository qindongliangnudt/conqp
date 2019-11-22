main.out: main.o readline.o
	gcc -o main main.o readline.o
main.o: main.c readline.h
	gcc -c main.c
readline.o: readline.c readline.h
	gcc -c readline.c
