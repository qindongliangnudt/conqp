#include <stdio.h>

int main(int argc, char* argv[])
{
	int hoge = 5;
	char poye = 10;
	void* hoge_1 = NULL;
	int*  hoge_2;
	char* hoge_3;
	printf("&hoge: %p\n", &hoge);
	printf("&poye: %p\n", &poye);
	printf("&hoge_1: %p\n", &hoge_1);
	printf("&hoge_2: %p\n", &hoge_2);
	printf("&hoge_3: %p\n", &hoge_3);
	hoge_2 = &hoge;
	hoge_3 = &poye;

	printf("hoge_2: %p, hoge_2+1: %p\n", hoge_2, hoge_2+1);
	printf("hoge_3: %p, hoge_3+1: %p\n", hoge_3, hoge_3+1);

	printf("hoge_1: %p\n", hoge_1);

	hoge_1 = &hoge;

	printf("hoge_1: %p\n", hoge_1);
//	printf("*hoge_1: %d\n", *hoge_1);
	printf("hoge_1+1: %p\n", hoge_1+1);

	hoge_1 = &poye;

	printf("hoge_1: %p\n", hoge_1);
//	printf("*hoge_1: %c\n", *hoge_1);
	printf("hoge_1+1: %p\n", hoge_1+1);
	printf("NULL is %p\n", NULL);
	return 0;
}
