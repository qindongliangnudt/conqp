#include <stdio.h>
#include "read_line.h"

int main(int argc, const char* argv[])
{
	printf("%s\n", read_line(stdin));
	free_buffer();
	return 0;
}
