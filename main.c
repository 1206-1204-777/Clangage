#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

/*Cでのテストについて*/
int dummy(int *ptr){

    if (ptr == NULL){
        fprintf(stderr, "NULLポインタが渡されました。\n");
        exit(1);
    }
    return 0;
}
void test_dummy(){
    int val = 5;
    assert(dummy(&val) == 0);
    dummy(NULL);
    printf("全ケース（正常・異常）合格\n");
}
int main(void)
{
    test_dummy();
    return 0;
    
}
