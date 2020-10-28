#include <stdio.h>

//プロトタイプ宣言
int sum(int);
int max;
int answer;

int main(void)
{
  printf("数値を入力してください: ");
  scanf("%d", &max);
  sum(max);
  printf("%d\n", answer);
  return 0;
}

int sum(int max)
{
  answer = (1 + max) * max / 2;
  return answer;
}
