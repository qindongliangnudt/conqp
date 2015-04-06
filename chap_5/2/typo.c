#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_MAX 126
#define ASCII_MIN 32
#define C_MAX 100000
#define BUF_MAX 65536
#define T_UNIT 10

void contrast_gen(char*, int);
int  ascii_gen(void);

int main (int argc, const char* argv[])
{
	srand(time(0));
	
	int  user_max;
	int  c;
	char buf[BUF_MAX];
	char contrast[T_UNIT + 1];
	char answer[T_UNIT + 1];
	
	int i;
	
	time_t t_start, t_end;
	
	printf("输入本次练习字符数（<100000）：\n");
	fgets(buf, sizeof(buf), stdin);
	buf[5] = '\0';
	sscanf(buf, "%d", &user_max);
	
	t_start = time(NULL);
	for (i = 1; i*T_UNIT <= user_max; i++)
	{		
		contrast_gen(contrast, T_UNIT);
		do
		{
			fgets(buf, sizeof(buf), stdin);
			buf[T_UNIT] = '\0';
			sscanf(buf, "%s", answer);
		} while (strcmp(contrast, answer)); 
	}
	
	if (user_max - (i - 1) * T_UNIT > 0)
	{
		contrast_gen(contrast, user_max - (i - 1) * T_UNIT);
		do
		{
			fgets(buf, sizeof(buf), stdin);
			buf[user_max - (i - 1) * T_UNIT] = '\0';
			sscanf(buf, "%s", answer);
		} while (strcmp(contrast, answer));
	}
	
	t_end = time(NULL);
	
	printf("本次用时：%ld秒",t_end - t_start);

	return 0;
}

void contrast_gen(char* contrast, int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
	{
		contrast[i] = ascii_gen();
	}
	contrast[i] = '\0';
	printf("%s\n",contrast);
}

int ascii_gen(void)
{
	int random_variable = (int)((double)rand() / (double)RAND_MAX * (ASCII_MAX - ASCII_MIN) + ASCII_MIN);
	return random_variable;
}
