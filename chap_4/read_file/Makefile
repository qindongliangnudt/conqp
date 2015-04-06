read_file: read_file.o read_line.o
	gcc -o read_file read_file.o read_line.o
read_file.o: read_file.c read_line.h
	gcc -c read_file.c
read_line.o: read_line.c read_line.h
	gcc -c read_line.c
