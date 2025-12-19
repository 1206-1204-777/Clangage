#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <assert.h>
// 宣言についての学習
int func_p(double){

}
int main(void)
{
  
    // 関数へのポインタの宣言
    int (*func_p)(double);
    // 配列の配列
    int hoge[2][3] = {
        {1,2,3},
        {4,5,6}
    };
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d\n", hoge[i][j]);
        }
        
    }
   
    
    return 0;
}
