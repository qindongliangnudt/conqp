#include <stdio.h>
#include "read_line.h"

int main(int argc, const char* argv[])
{
	char *myline;
	read_line(stdin, &myline);
	printf("%s\n", myline);
	return 0;
}
