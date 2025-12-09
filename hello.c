#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 構造体についての学習
// 構造体の作成
struct studend
{
    int year;
    char name[64];
    double weight;
    double height;
};
int main(void){

    struct studend taro;

    taro.year = 10;
    printf("%d\n", taro.year);
    return 0;
};
