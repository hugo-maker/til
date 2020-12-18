#include <stdio.h>

int main(void)
{
  int i;
  int j;

  //繰り返し外側
  for (i = 1;i <= 9;i++) {
    //繰り返し内側
    for (j = 1;j <= 9;j++ ) {
      printf("%2d * %2d = %2d\n",i, j, i * j);
    }
  }

  return 0;
}
