#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// 変数実験
int apple = 15; //グローバル変数
int main(void){
    {
        int apple = 50; // ローカル変数
        printf("%d\n", apple);
    }

    // 配列の学習
    int array[10];
    array[9] = 60;
    printf("%d\n",array[10]);
    //宣言と代入を同時に行う
    int array2[100] = {12,13,14,100,56};
    printf("%d\n",array2[0]);
    printf("%d\n",array2[1]);
    printf("%d\n",array2[2]);
    printf("%d\n",array2[3]);
    printf("%d\n",array2[4]);

    int array3[] = {12,13,1,14,5};
    printf("%d\n",array3[1]);
    // for文を使った出力
    int array4[] = {12,13,14};
    for (int i = 0; i < sizeof(array4); i++)
    {
        printf("%d番目:%d\n",i,array4[i]);
    }

    // 文字列を配列で扱う方法
    char c = 'a';
    printf("%c\n",c);

    char ch[] = {'J','O','H','N','\0'};
    printf("%s\n",ch);
    char str[] = "256";
    printf("%s\n",str);

    // atoi
    int str2 = atof(str);
    printf("%i\n", str2 + 5);

    // strcat
    char str3[10] = "Hello ";
    strcat(str3, ch);
    printf("%s\n", str3);

    // sprintf
    char str4[20];
    char str5[] = "star";
    char str6[] = "wars";
    int i = 3;
    sprintf(str4, "%s%s%d",str5,str6,i);
    printf("%s\n", str4);
    char str7[256];
    scanf("%s", str7);
    i = strlen(str7);
    printf("%d\n",i);
    return 0;
};