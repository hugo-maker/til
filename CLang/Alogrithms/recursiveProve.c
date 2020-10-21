#include <stdio.h>

//プロトタイプ宣言
void prove(int n);

void prove(int n)
{
  if (n == 0) {
    printf("ステップ1により、P(%d)が成り立ちます\n", n);
  } else {
    prove(n -1);
    printf("ステップ2により、「P(%d)が成り立つならばP(%d)も成り立つ」と言えます\n",n - 1, n);
    printf("したがって、「P(%d)が成り立つ」と言えます\n", n);
  }
}

int main(void)
{
  int n;
  scanf("%d", &n);
  prove(n);
  return 0;
}
