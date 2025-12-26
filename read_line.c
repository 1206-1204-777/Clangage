#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <assert.h>
/*文字列を動的に保管する関数*/
#define ALLOC_SIZE (256)

/*行を読み込むバッファ*/
static char *st_line_buffer = NULL;

/*st_line_bufferの指す先に割り当てる領域のサイズ*/
static int st_current_buffer_size = 0;

/*st_line_bufferの中で使用されている領域サイズ*/
static int st_current_used_size = 0;

/*st_line_bufferの末尾に1文字追加し必要なら領域を拡張する*/
static void add_character(int ch){
    assert(st_current_buffer_size >= st_current_used_size);
    if(st_current_buffer_size == st_current_used_size){
        st_line_buffer = realloc(st_line_buffer, (st_current_buffer_size + ALLOC_SIZE) * sizeof(char));
        st_current_buffer_size +=ALLOC_SIZE;
    }
    /*末尾に1文字追加*/
    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size ++;
}
char *read_line(FILE *fp){
    int ch;
    char *ret;
    st_current_used_size = 0;
    while ((ch = getc(fp)) != EOF)
    {
        if(ch == '\n'){
            add_character('\0');
            break;
        }
        add_character(ch);
    }
        if(ch == EOF){
            if(st_current_used_size > 0){
                add_character('\0');
            }else{
                return NULL;
            }
        }

    ret = malloc(sizeof(char) * st_current_used_size);
    strcpy(ret, st_line_buffer);
    return ret;
}

/*確保した領域の一括開放*/
void free_buffer(void){
    free(st_line_buffer);
    st_line_buffer = NULL;
    st_current_buffer_size = 0;
    st_current_used_size = 0;
}