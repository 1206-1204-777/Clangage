#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "read_line.h"

/*動的配列に動的配列をダブルポインタを使い格納する方法*/

int main(void)
{
    char *line;
    while (read_line(stdin, &line) != READ_LINE_EOF)
    {
        printf("%s\n", line);
    }
    free_buffer();
    return 0;
    
}
