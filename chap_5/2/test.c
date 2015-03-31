#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ASCII_MAX 126
#define ASCII_MIN 32

int ascii_gen(void)
{
	int random_variable = (int)((double)rand() / (double)RAND_MAX * (ASCII_MAX - ASCII_MIN) + ASCII_MIN);
	return random_variable;
}

int main(int argc, const char* argv[])
{
	srand(time(0));
	int i = 0;
	for (i = 0; i < 50; i++)
	{
		printf("%c ", ascii_gen());
	}
	return 0;
}
