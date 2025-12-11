#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// ポインタについての追加学習
typedef struct hello
{
    char h[56];
    int num1;
    int num2;
}hello;

int sum(int *x, int *y);
int main(void)
{
    int apple = 100;
    int orange = 150;
    int *b = &apple;
    int *c;
    c = &apple;

    printf("%d\n", *b + *c);
    printf("%d\n", apple + *c);
    printf("%p\n", &apple);
    printf("%p\n", b);

    sum(&apple, &orange);
    printf("%d, %d\n", apple, orange);

    hello hello1 = {"hello", 10, 56};
    hello *hello2 = &hello1;
    printf("%d\n", hello2->num1);

    
    return 0;
}

// この関数からmain関数の値を操作
int sum(int *x, int *y){
    *x = 25 + *y;
    *y = 50 + 5;

}
