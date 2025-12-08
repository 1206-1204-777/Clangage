#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ポインタについての学習

int sum(int x, int y,  int *a1, int *a2);
int main(void){
    int apple = 10;
    int *hoge = &apple;
    printf("%d\n", apple);
    printf("%d\n",*hoge); 

    int apple2 , *hoge2;
    hoge2 = & apple2; // apple2とhoge2のアドレスを同じにする

    printf("%p\n", &    apple2);
    printf("%p\n", hoge2);

    // ポインタ変数の宣言
    int *hoge3;
    // アドレスの代入
    hoge3 = &apple; // hoge3にappleのアドレスを代入
    printf("%p\n", &apple);
    printf("%p\n", hoge3);

    // 参照先の値を変更
    int *p,i;
    p = &i;
    *p = 15;
    printf("%d\n", i);
    printf("%d\n", *p);

    // 複数の値を返す
    int sum1, sum2;
    sum(30, 50, &sum1, &sum2);
    printf("%d\n", sum1);
    printf("%d\n", sum2);
    return 0;
};

int sum(int x, int y, int *a1, int *a2){
    *a1 = x + y;
    *a2 = x - y;
    return 0;
}