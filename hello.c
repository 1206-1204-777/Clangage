#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <assert.h>

// ポインタ経由で複数の値を返す
void func1(int *x, double *y){
    *x = 5;
    *y = 1.6 + *x;
}
// 配列のポインタを渡す
void func2(int *array, int size){
    for (int i = 0; i < size; i++)
    {
        printf("%d\n", array[i]);
    }
    
}

int main(void)
{
  int a;
  double b;
  func1(&a, &b);
  printf("%d %f\n", a, b);

  int array[] = {1, 2, 3, 4, 5};
  printf("%zu\n",sizeof(array));
  printf("%zu\n",sizeof(array[0]));
  func2(array, sizeof(array) / sizeof(array[0]));

  // mallocを使った動的配列
  char buf[256];
  int size;
  int *arrays;

  fgets(buf, 256, stdin); // 文字列を取得
  sscanf(buf, "%d", &size); // 取得した文字列を配列に格納
  arrays = malloc(sizeof(int)* size);

  for (int i = 0; i < size; i++)
  {
    arrays[i] = i;
  }
  for (int i = 0; i < size; i++)
  {
    printf("%d ", arrays[i]);
  }
  printf("\n");
  // mallocを使った動的配列
  int *arrays2 = NULL;
  int size2 = 0;
  char buf2[256];

  while (fgets(buf2, 256, stdin) != NULL)
  {
    size2 ++;
    arrays2 = realloc(arrays2, sizeof(int) * size2);
    sscanf(buf2, "%d", &size2);
  }
  for (int i = 0; i < size2; i++)
  {
    printf("%d\n", arrays2[i]);
  }
  
    return 0;
}
