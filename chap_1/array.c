#include <stdio.h>

int main(int argc, char* argv[])
{
	int array[5];
	int i;
	for (i = 0; i < 5; i++) {
		array[i] = i*i;
	}
	
	for (i = 0; i < 5; i++) {
		printf("%d\n", array[i]);
	}

	for (i = 0; i < 10; i++) {
		printf("&array[%d] ... %p ... %d\n", i, &array[i], array[i]);
	}

	return 0;
}
