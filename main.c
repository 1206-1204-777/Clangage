#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*コマンド行引数の使い方についての学習*/
/*catコマンドと同様の機能を実装*/
void type_one_file(FILE *fp){
    int ch;
    while ((ch = getc(fp)) != EOF)
    {
        putchar(ch);
    }
    
}
int main(int argc, char const *argv[])
{
    if(argc == 1){
        type_one_file(stdin);
    }else
    {
        FILE *fp;
        for (int i = 0; i < argc; i++)
        {
            fp = fopen(argv[i], "rb");
            if (fp == NULL){
                fprintf(stderr, "%s:%s can not open.\n", argv[0], argv[1]);
                exit(1);
            }
            type_one_file(fp);
        }
        
    }
    
    return 0;
}
