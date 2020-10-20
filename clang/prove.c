#include <stdio.h>

void prove(int n)
{
  int k;

  printf("いまから、P(%d)が成り立つことを証明します。\n", n);
  k = 0;
  printf("ステップ1により、P(%d)が成り立ちます。\n", k);
  while (k < n) {
    printf("ステップ2により、「P(%d)が成り立つならばP(%d)も成り立つ」といえます。\n", k, k + 1);
    printf("したがって、「P(%d)が成り立つ」といえます。\n", k + 1);
    k = k + 1;
  }
  printf("以上で、証明が終わりました。\n");
}

int main(void)
{
  prove(3);
  return 0;
}
