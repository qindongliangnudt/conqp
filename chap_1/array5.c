#include <stdio.h>

int main(int argc, char* argv[])
{
	int array[5];
	int* p;
	int i;
	for (i = 0; i < 5; i++) {
		array[i] = i*i;
	}

	p = array;
	for (i = 0; i < 5; i++) {
		printf("%d\n", p[i]);
	}

	printf("array is: %p\n", array);
	return 0;
}
