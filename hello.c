#include <stdio.h>
// 関数の作り方

int hello(void);
int price(int x);
int fruits(int apple, int banana);
int main(void){
    hello();
    price(500);
    fruits(4, 4 );
    return 0;
}

// 引数なし関数
int hello(void){
    printf("hello\n");
    return 0;
}

// 引数あり関数
int price(int x){
    printf("%f\n", x * 1.1);
    return 0;
}

int fruits(int apple, int banana){
    int total = apple * 300 + banana * 150;
    int total_price = price(total);
    return total_price;
}