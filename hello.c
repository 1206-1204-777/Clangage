#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// ポインタについての追加学習
// Cがメモリをどう使うかについての学習
// 仮想アドレスについて
int hoge;
static int static_hoge;
void func1(void){
    int local_hoge;
    static int local_static_hoge;
    printf("%p\n", &local_hoge);
    printf("%p\n", &local_static_hoge);
}
void func2(void){
    int local_hoge2;
    printf("%p\n", &local_hoge2);
}
void func3(int x){
    printf("%d\n", x + 10);
}
void func4(int x){
    printf("%d\n", x + 20);
}
int main(void)
{
    /*char buf[256];
    printf("%p\n", &hoge); // グローバルメモリのアドレス
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", hoge);

    for (;;)
    {
        printf("%p\n", &hoge);
        getchar();
        hoge++;
    }*/
    // アドレスの確認実験
    int *p;
    /*関数のアドレスを確認*/
    printf("%p\n", (void*)func1);
    printf("%p\n", (void*)func2);

    /*グローバル変数のアドレス確認*/
    printf("%p\n", (void*)&hoge);
    printf("%p\n", (void*)&static_hoge);

    /*関数ごとのローカル変数のアドレスを確認*/
    func1();
    func2();
    /*mallocで保持したアドレスの確認*/
    p = malloc(sizeof(int));
    printf("%p\n", (void*)p);
    free(p);
    /*文字列のアドレス*/
    printf("%p\n", (void*)"abc");

    /*関数のポインタを格納しポインタ経由で値を渡す */
    void (*func_p)(int); //関数のポインタ
    func_p = func3; // 関数のポインタを変数に格納
    func_p(5); // ポインタ変数内のアドレスにある関数を呼び出し値を渡す


    func_p = func4; // ポインタを別の関数に向ける
    func_p(5);
   return 0;
}
