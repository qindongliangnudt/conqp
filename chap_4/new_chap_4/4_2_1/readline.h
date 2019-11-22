#ifndef READLINE_H_INCLUDED
#define READLINE_H_INCLUDED

#include <stdio.h>

char *read_line(FILE *fp);
void free_buffer(void);

#endif
