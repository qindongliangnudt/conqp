/*
	程序说明：
	1.概述：从英文的文本文件中将单词一个一个取出来。
	2.程序读到EOF时退出结束

	分析：
	1.所有的字符都是文件的一部分，对这些字符首先区分一下两类：
	（1）EOF:此时程序的反应应该是退出
	（2）非EOF:此时程序进行正常的工作
	2.对于非EOF字符，进行如下区分：
	（1）可以构成单词的字符，包括0~9/a~z/A~Z,可以使用库函数isalnum()
		:Defined in header <ctype.h>
		:Checks if the given character is an alphanumeric character as classified by the current C locale. 
		:In the default locale, the following characters are alphanumeric:
		:	digits (0123456789)
		:	uppercase letters (ABCDEFGHIJKLMNOPQRSTUVWXYZ)
		:	lowercase letters (abcdefghijklmnopqrstuvwxyz)
		:Return Value: Non-zero value if the character is an alphanumeric character, 0 otherwise.
		:参考——http://en.cppreference.com/w/c/string/byte/isalnum
	（2）除去可以构成单词的那些字符归为其他字符（这其中的换行符不用特殊对待，只是当成一般的其它字符就可以）
	3.函数接口设计（也就是函数的调用方式）参照fgets()，定义成如下的形式：
		int get_word(char* buf, int buf_size, FILE* fp);
	单词长度大于buf_size的情况下果断难于处理，果断使用eixt()退出程序。
	为了测试函数，在程序中添加main()函数用来驱动测试过程，main()中声明的数组，在调用get_word()的时候被填充。
	4.get_word()函数的基本逻辑流程：
		（1）跳过开头的空白字符（如果有的话）
		（2）是否已经到达文件末尾？到达的话直接返回EOF给main()函数，让main()去处理
		（3）逐个读取字符，作为当前单词的内容填充到buf中（准确说是buf指针指向的连续内存区域中），直到EOF出现或者空白字符出现
		（4）返回读取到的单词的长度
	5.相应的main()函数的测试逻辑：
		没有到达EOF时持续读取单词	
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int get_word(char* buf, int buf_size, FILE* fp)
{
	int len;
	int ch;
	
	while ((ch = getc(fp)) != EOF && !isalnum(ch))
		;
	if (ch == EOF)
		return EOF;
		
	len = 0;
	do
	{
		buf[len] = ch;
		len++;
		if (len >= buf_size)
		{
			fprintf(stderr, "word too long.\n");
			exit(1);
		}
	} while ((ch = getc(fp)) != EOF && isalnum(ch));
	buf[len] = '\0';
	
	return len;
}

int main (int argc, const char* argv[])
{
	char buf[32];
	FILE* fp = fopen(argv[1], "r");
    	if(!fp) {
       		 perror("File opening failed");
       		 return EXIT_FAILURE;
	}	
	while (get_word(buf, 32, fp) != EOF)
	{
		printf("<<%s>>\n", buf);
	}
	return 0;
}
