#include <stdio.h>
#include <stdlib.h>

void hanoi (int number, char x, char y, char z);

void hanoi (int number, char x, char y, char z)
{
  if (number == 0) {
    //何もしない
  } else {
    hanoi(number - 1, x, z, y);
    printf("%c->%c\n", x, y);
    hanoi(number - 1, z, y, x);
  }
}

int main(void)
{
  int number;
  scanf("%d", &number);
  hanoi(number, 'A', 'B', 'C');
  return EXIT_SUCCESS;
}
