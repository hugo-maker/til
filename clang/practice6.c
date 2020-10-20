#include <stdio.h>

int main(void)
{
  int price;
  double discount;
  discount = 0.1;

  //入力部分
  printf("定価を入力してください: ");
  scanf("%d", &price);

  //計算と出力を繰り返す
  while (discount < 0.8) {
    printf("%d割引: %d円\n", (int) (discount * 10), (int) (price - (price * discount)));
    discount += 0.2;
  }
  return 0;
}
