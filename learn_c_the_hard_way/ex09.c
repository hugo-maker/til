#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 1;
  while (i < 41)
  {
    if ((i % 3) == 0)
    {
      printf("foo!!\n");
      i++;
      continue;
    }
    printf("%d\n", i);
    i++;
  }
  return 0;
}
