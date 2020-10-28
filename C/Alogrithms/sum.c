#include <stdio.h>

int sum(int array[], int size)
{
  int k = 0;
  int s = 0;
  //M(0)
  while (k < size) {
    //M(k)
    s = s + array[k];
    //M(k+1)
    k = k + 1;
    //M(k)
  }
  //M(size)
  return s;
}

int main(void)
{
  int array[5] = {2,2,3,4,5};
  printf("sum=%d\n",sum(array, 3));
  return 0;
}
