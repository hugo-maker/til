#include <stdio.h>

int main(void)
{
  //先入れ後出しque

  int array[10];
  int i;

  //10個の数値の入力を受付
  for (i = 10 - 1;i >= 0;i--) {
    printf("数値を入力してください :");
    scanf("%d", &array[i]);
  }
  //配列の要素を表示
  for (i = 0;i < sizeof(array) / sizeof(array[0]);i++) {
    printf("%d\n", array[i]);
  }
  return 0;
}
