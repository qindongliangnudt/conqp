#include <stdio.h>

int main (int argc, const char *argv[])
{
	int hoge;
	int *hoge_p;
	
	hoge_p = &hoge;
	printf("hoge_p..%p\n", hoge_p);
	hoge_p++;
	printf("hoge_p..%p\n", hoge_p);
	printf("hoge_p..%p\n", hoge_p+3);
	return 0;
}
