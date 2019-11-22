#include <stdio.h>
#include <stdlib.h>
#include "readline.h"

int main(int argc, const char* argv[])
{
    FILE* fp = fopen("haha.txt", "r");
    if(!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }
	char *myline = read_line(fp);
	printf("%s\n", myline);
    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");

    fclose(fp);
	return 0;
}
