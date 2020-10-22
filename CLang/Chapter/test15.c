#include <stdio.h>

int main(void)
{
  int *data;
  int i;
  int average = 0;
  int array[10] = {15,78,98,15,98,85,17,35,42,15};

  //ここに注目
  for (data = array;data != &array[10];data++) {
    average += *data;
  }

  printf("%d\n", average / 10);
  return 0;
}
