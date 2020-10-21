#include <stdio.h>

int main(void)
{
  int score;
  printf("点数を入力してください:");
  scanf("%d", &score);
  if (score > 100) {
    printf("入力が 100 より大きいので修正します\n");
    score = 100;
  }
  printf("点数は %d 点です。\n", score);
  return 0;
}
