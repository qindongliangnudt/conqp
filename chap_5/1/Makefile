main: main.o get_word.o initialize.o add_word.o dump_word.o finalize.o
	gcc -o main main.o get_word.o initialize.o add_word.o dump_word.o finalize.o
main.o: main.c word_manage.h get_word.h
	gcc -c main.c
get_word.o: get_word.c get_word.h
	gcc -c get_word.c
initialize.o: initialize.c word_manage.h word_manage_p.h
	gcc -c initialize.c
add_word.o: add_word.c word_manage.h word_manage_p.h
	gcc -c add_word.c
dump_word.o: dump_word.c word_manage.h word_manage_p.h
	gcc -c dump_word.c
finalize.o: finalize.c word_manage.h word_manage_p.h
	gcc -c finalize.c
