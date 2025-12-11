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
}taro,hanako;

typedef struct fruits
{
    int apple;
    int banana;
    int orange;
}fruits;
void price(struct fruits store1);
int main(void){
    taro.year = 10;
    hanako.year = 12;
    printf("%d\n", taro.year);
    printf("%d\n",hanako.year);

    //構造体へ複数の値を代入
    struct fruits store1 = {100, 200, 300};
    struct fruits store2 = {50, 230, 400};
    struct fruits store3 = store1; // 構造体内のデータ型が同じ場合のみ有効

    fruits store4 = store2;
    price(store4);

    // 構造体を配列に格納
    
    return 0;
};
    // 構造体を引数で渡す
    void price(struct fruits store1){
        printf("%d\n",store1.apple);
        printf("%d\n",store1.banana);
        printf("%d\n",store1.orange);
    }
