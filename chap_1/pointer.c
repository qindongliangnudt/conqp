#include <stdio.h>

int main (int argc, const char* argv[])
{
	int hoge = 5;
	int piyo = 10;
	int* hoge_p;
	int* piyo_p;
	
	/*输出每个变量的地址*/
	printf("&hoge..%p\n", &hoge);
	printf("&piyo..%p\n", &piyo);
	printf("&hoge_p..%p\n", &hoge_p);
	printf("&piyo_p..%p\n", &piyo_p);
	
	/*将hoge的地址赋值给hoge_p*/
	hoge_p = &hoge;
	printf("hoge_p..%p\n", hoge_p);

	piyo_p = &piyo;
	printf("piyo_p..%p\n", piyo_p);
	
	/*通过hoge_p输出hoge的内容*/
	printf("*hoge_p..%d\n", *hoge_p);
	printf("*piyo_p..%d\n", *piyo_p);
	
	/*通过hoge_p修改hoge的内容*/
	*hoge_p = 15;
	*piyo_p = 20;
	printf("hoge..%d\n", hoge);
	printf("piyo..%d\n", piyo);
	
	return 0;
}
