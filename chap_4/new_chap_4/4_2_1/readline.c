#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define ALLOC_SIZE (256)

/*
 *读取行的缓存，必要时进行扩展。
 *但是区域不会被缩小。
 *调用free_buffer()释放。
*/
static char *st_line_buffer = NULL;

/*
 *在st_line_buffer前方被分配的内存区域的大小。
*/
static int st_current_buffer_size = 0;

/*
 * st_line_buffer中现存的字符的大小。
*/
static int st_current_used_size = 0;

/*
 *如有必要，扩展st_line_buffer前方的内存区域。
 *在st_line_buffer末尾追加一个字符。
*/
static void
add_character(int ch) {
    /*
     *此函数每次调用时，st_current_used_size都必定会增加1，
     *正常情况下，下面的断言肯定不会为假。
    */
    assert(st_current_buffer_size >= st_current_used_size);

    /*
    * st_current_used_size达到st_current_buffer_size的时候，
    * 扩展缓冲区的内存区域。
    */
    if (st_current_buffer_size == st_current_used_size) {
        st_line_buffer = realloc(st_line_buffer, 
                           (st_current_buffer_size + ALLOC_SIZE)
                                   * sizeof(char));
        st_current_buffer_size += ALLOC_SIZE;
    }       

    /*在缓冲区末尾追加一个字符*/
    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size++;
}

/* 
 *从fp中读取一个字符，一旦读到文件末尾，就返回NULL
*/
char *read_line(FILE *fp) {
    int ch;
    char *ret;

    st_current_used_size = 0;
    while((ch = getc(fp)) != EOF) {
        if (ch == '\n') {
            add_character('\0');
            break;
        }
        add_character(ch);
    }
    if (ch == EOF) {
        if(st_current_used_size > 0) {
            /*如果最终行后面没有换行*/
            add_character('\0');
        } else {
            return NULL;
        }
    }

    ret = malloc(sizeof(char) * st_current_used_size);
    strcpy(ret, st_line_buffer);

    return ret;
}

/*
 *释放缓冲去内存。
 *其实，即使不调用这个函数也不会有什么问题。
*/
void free_buffer(void) {
    free(st_line_buffer);
    st_line_buffer = NULL;
    st_current_buffer_size = 0;
    st_current_used_size = 0;
}
