#include <stdio.h>

int main(void)
{
  int juice,milk,money,payment,change;
  double tax;

  juice = 152;
  milk = 238;
  money = 2000;
  tax = 1.10;

  payment = (int) ((juice * 2 + milk * 3) * tax);
  change = money - payment;
  
  printf("お釣りは%d円です。\n", change);

  return 0;
}
