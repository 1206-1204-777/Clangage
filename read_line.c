#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <assert.h>
#include "read_line.h"
/*文字列を動的に保管する関数*/
#define ALLOC_SIZE (256)

/*行を読み込むバッファ*/
static char *st_line_buffer = NULL;

/*st_line_bufferの指す先に割り当てる領域のサイズ*/
static int st_current_buffer_size = 0;

/*st_line_bufferの中で使用されている領域サイズ*/
static int st_current_used_size = 0;

/*st_line_bufferの末尾に1文字追加し必要なら領域を拡張する*/
static ReadLineStatuse add_character(int ch){
    assert(st_current_buffer_size >= st_current_used_size);
    if(st_current_buffer_size == st_current_used_size){
        char *temp;
        temp = realloc(st_line_buffer, (st_current_buffer_size + ALLOC_SIZE) * sizeof(char));
        if (temp == NULL)
        {
            return RESD_LINE_OUT_OF_MEMORY;
        }
        st_line_buffer = temp;
        st_current_buffer_size += ALLOC_SIZE;
    }
    /*末尾に1文字追加*/
    st_line_buffer[st_current_used_size] = ch;
    st_current_used_size ++;

    return READ_LINE_SUCCESS;
}
ReadLineStatuse read_line(FILE *fp, char **line){
    int ch;
    ReadLineStatuse status = READ_LINE_SUCCESS;
    st_current_used_size = 0;
    while ((ch = getc(fp)) != EOF)
    {
        if(ch == '\n'){
            status = add_character('\0');
            if(status != READ_LINE_SUCCESS){
                goto FUNC_END;
            break;
            }
        }
        status = add_character(ch);
        if (status != READ_LINE_SUCCESS){
            goto FUNC_END;
        }
    }
        if(ch == EOF){
            if(st_current_used_size > 0){
               status = add_character('\0');
               if (status != READ_LINE_SUCCESS)
               {
                goto FUNC_END;
               }

            }else{
                status = READ_LINE_EOF;
                goto FUNC_END;
            }
        }

    *line = malloc(sizeof(char) * st_current_used_size);
    if (*line == NULL)
    {
        status = RESD_LINE_OUT_OF_MEMORY;
        goto FUNC_END;
    }
    
    strcpy(*line, st_line_buffer);

    FUNC_END:
    if (status != READ_LINE_SUCCESS && status != READ_LINE_EOF)
    {
        free_buffer();
    }
    
    return status;
}

/*確保した領域の一括開放*/
void free_buffer(void){
    free(st_line_buffer);
    st_line_buffer = NULL;
    st_current_buffer_size = 0;
    st_current_used_size = 0;
}