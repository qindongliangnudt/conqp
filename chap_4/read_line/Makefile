main: main.o read_line.o
	gcc -o main main.o read_line.o
main.o: main.c read_line.h
	gcc -c main.c
read_line.o: read_line.c read_line.h
	gcc -c read_line.c
