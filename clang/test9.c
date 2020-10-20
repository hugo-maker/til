#include <stdio.h>

int main(void)
{
  int i;
  for (i = 1;i <= 10;i++) {
    printf("%d\n", i);
    //i == 6 のときループを強制終了
    if (i == 6) break;
  }
  return 0;
}
