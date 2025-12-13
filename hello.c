#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// ポインタについての追加学習
// ポインタについてのさらなる深堀の学習
int func_hoge(int *x, int *y){
    *x = *x + *y;
    *y = 56;

}
int get_word(char buf[], int buf_size, FILE *fp){
    int len;
    int ch;

    while ((ch = getc(fp) != EOF && !isalnum(ch)));
    if (ch == EOF)
    {
        return EOF;
    }
    len = 0;
    do
    {
        buf[len] = ch;
        len++;
        if (len >= buf_size)
        {
            fprintf(stderr, "word to long. \n");
            exit(1); // 異常終了
        }
        
    } while ((ch = getc(fp) != EOF && !isalnum(ch)));
    
    buf[len] = '\0';
    return len;
    
}
int main(void)
{
    /*基本の復習*/
    int hoge = 5;
    int piyo = 10;
    int *hoge_p; // int型から派生したポインタ

    // アドレスの確認
    printf("%p\n", &hoge);
    printf("%p\n", &piyo);
    printf("%p\n", &hoge_p);

    hoge_p = &hoge;
    printf("変更後のhoge_p: %p\n", &hoge_p);

    printf("%d\n", *hoge_p);
    *hoge_p = 10; // ポインタの指す先の値を変更
    printf("%d\n", *hoge_p);
    printf("%p\n", hoge_p);

    /*演算子*/
    // アドレス演算子 = &
    // 関節演算子　=　*
    // 添字演算子　= []

    /*ポインタ演算 */
   // hoge_p++;
    printf("%p\n", hoge_p + 3);

    // 複数の値をポインタを使い返す
    int x = 5;
    int y = 6;
    func_hoge(&x, &y);

    printf("%d\n", x);
    printf("%d\n", y);

    /*配列*/
    int array[5];
    int i;
    int *p;
    for (i = 0; i < 5; i++)
    {
        array[i] = i;
        printf("%d ", array[i]);
    }
    printf("\n");
    for (p = &array[0]; p != &array[5]; p++)
    {
        printf("%d ", *p);
    }
    printf("\n");
    
    /*char buf[256];
    while (get_word(buf, 256, stdin) != EOF)
    {
        printf("<<%s>>\n", buf);
    }*/
    
    /*可変長配列 */
    int size1, size2, size3;
    scanf("%d %d %d", &size1, &size2, &size3);

    int array1[size1];
    int array2[size2][size3];
    for (int i = 0; i < size1; i++)
    {
        array1[i] = i;
    }
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size3; j++)
        {
            array2[i][j] = i * size3 * j;
        }
        
    }
    for (int i = 0; i < size1; i++)
    {
        printf("[%d]: %d\n", i, array1[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        for (int j = 0; j < size3; j++)
        {
            printf("\t%d", array2[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
