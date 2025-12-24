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
    // sizeofを使った配列サイズの確認
   printf("%zu\n", sizeof(hoge));

   // 配列の初期化
   int test_array[100];
   char *color[] = {
    "red",
    "green",
    "blue",
   };

   int test_a[100];
   int test[][6] = {
    {10, 20},
    {10, 50}
   };
   char test_c[] = "test"; // t, e, s, t, \0の配列
   printf("%s\n", test_c);
   printf("%p\n", &color);
   printf("%p\n", &color[0]);
   printf("%p\n", &test);
   printf("%p\n", &test[4]);
    return 0;
}
