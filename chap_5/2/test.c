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

int get_min(int a, int b)
{
	if (a <= 0 || b <= 0)
		return 0;
	else
	{
		return a < b ? a : b; 
	}
}

int main(int argc, const char* argv[])
{
	srand(time(0));
	int i = 0;
	for (i = 0; i < 50; i++)
	{
		printf("%c ", ascii_gen());
	}
	
	printf("\n");
	printf("get_min(-3, -5): %d", get_min(-3, -5));
	
	return 0;
}
