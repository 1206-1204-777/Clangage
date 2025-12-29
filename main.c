#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "read_line.h"

/*関数の引数に多次元配列を使用する*/
void func(int size1, int size2, int (*hoge)[size2] ){
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            printf("%d ", hoge[i][j]);
        }
        printf("\n");
    }
    
}
int main(void)
{
    int hoge[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    func(4, 3, hoge);
    return 0;
    
}
