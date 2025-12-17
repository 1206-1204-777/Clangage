#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <assert.h>

// --- グローバル変数 ---
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
void func5(int a, int b){
    printf("%p\n", &a);
    printf("%p\n", &b);
}
void tiny_printf(char *format, ...){
    int i;
    va_list ap;
    va_start(ap, format);
    for (i = 0; format[i] != '\0'; i++)
    {
        switch (format[i])
        {
        case 's':
            printf("%s", va_arg(ap, char*));
            break;
        case 'd':
            printf("%d", va_arg(ap, int));
            break;
        default:
            assert(0);
        }
    }
    va_end(ap);
    putchar('\n');
}

// --- 順列生成関連 ---
#define N_MAX (100)
int used_flg[N_MAX + 1]; 
int reslut[N_MAX];
int n, r;

void print_reslut(void){
    for (int i = 0; i < r; i++)
    {
        printf("%d", reslut[i]); 
    }
    printf("\n");    
}

void perm(int nth){
    if (nth == r){
        print_reslut();
        return;
    }
    // DEBUG: perm関数に入ったことを確認
    // printf("DEBUG perm: nth=%d\n", nth); 
    
    for (int i = 1; i <= n; i++)
    {
        if (used_flg[i] == 0){
            reslut[nth] = i;
            used_flg[i] = 1;
            perm(nth + 1);
            used_flg[i] = 0;
        }
    }
}
/*C99から追加されたVLAについての実験 */
void sub(int size1, int size2, int size3){
    int var1;
    int array1[size1];
    int var2;
    int array2[size2][size3];
    int var3;

    printf("%p\n", (void*)array1);
    printf("%p\n", (void*)array2);
    printf("%p\n", (void*)&var1);
    printf("%p\n", (void*)&var2);
    printf("%p\n", (void*)&var3);
    
}
// --- main関数 ---
// main関数の定義を修正 (int *argc -> int argc)
int main(int argc, char **argv)
{
    int *p;
    printf("%p\n", (void*)func1);
    printf("%p\n", (void*)func2);
    printf("%p\n", (void*)&hoge);
    printf("%p\n", (void*)&static_hoge);
    func1();
    func2();
    p = malloc(sizeof(int));
    printf("%p\n", (void*)p);
    free(p);
    printf("%p\n", (void*)"abc");

    void (*func_p)(int);
    func_p = func3;
    func_p(5);
    func_p = func4;
    func_p(5);

    int a,b;
    printf("%p\n%p\n", &a, &b);
    func5(1, 2);

    tiny_printf("sdd", "reslut ", 5 , 6);

    // ---  プリントデバッグログ挿入箇所 ---
    printf("DEBUG A: 引数チェック前\n"); 

    // 引数チェック
    if (argc < 3) {
        fprintf(stderr, "エラー: 実行には2つの引数 (nとr) が必要です。\n");
        fprintf(stderr, "使用法: ./hello <nの値> <rの値>\n");
        return 1;
    }
    
    printf("DEBUG B: sscanf実行前\n");

    // sscanfの戻り値チェック
    if (sscanf(argv[1], "%d", &n) != 1 || sscanf(argv[2], "%d", &r) != 1) {
        fprintf(stderr, "エラー: nまたはrの値が不正です。\n");
        return 1;
    }

    printf("DEBUG C: sscanf実行後 (n=%d, r=%d)\n", n, r); 
    
    // ロジック上のチェック (不正な値で配列アクセスを防ぐ)
    if (n < r || n > N_MAX || r > N_MAX || n < 1 || r < 1) {
        fprintf(stderr, "エラー: n, rの値が不適切です (1 <= r <= n <= %d).\n", N_MAX);
        return 1;
    }

    printf("DEBUG D: perm呼び出し前\n");

    perm(0); // 順列生成開始

    printf("DEBUG E: 正常終了\n");

    int size1, size2, size3;
    scanf("%d%d%d", &size1, &size2, &size3);
    sub(size1, size2, size3);
    return 0;
}