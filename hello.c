#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <assert.h>
// mallocについての学習
typedef struct books
{
    int price;
    char *title;
    struct books *next;
}books;

int main(void)
{
    // mallocの基礎
    int hoge = 10;    
    int *p = malloc(sizeof(hoge)); // 変数pの領域を確保
    if (p == NULL)
    {
        fprintf(stderr, "ポインタがnullです\n");
        return 1;    
    }
 
    *p = hoge;
    printf("%d\n", *p);
    free(p); // 変数pの領域を開放
    p = NULL;
    
    // callocの学習
    int *p2 = calloc(10 ,sizeof(hoge));
    if (p2 == NULL)
    {
        fprintf(stderr, "メモリ確保に失敗\n");
        return 1;
    }
    
    p2[0] = hoge;
    p2[1] = 1000;
    printf("%d\n", p2[0]);
    printf("%d\n", p2[1]);
    printf("未代入の p2[5] の値: %d\n", p2[5]);
    free(p2); 
    p2 = NULL;
    return 0;
}
