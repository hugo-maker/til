#include <stdio.h>

int main(void)
{
  int score;

  do {
    printf("テストの点数を入力してください:");
    scanf("%d", &score);
  } while (score < 0 || score > 100);

  printf("%d 点\n", score);
  return 0;
}

