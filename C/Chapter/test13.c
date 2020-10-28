#include <stdio.h>
#include <string.h>

int main(void)
{
  //要素数の省略
  int array1[] = {33,82,79,18,29,};
  int array2[] = {1,3,5,7,9};
  int i;

  for (i = 0;i < sizeof(array2) / sizeof(array2[0]);i++) {
    printf("array2[%d] = %d\n",i, array2[i]);
  }

  //array1の全要素をarray2にコピー
  /*for (i = 0;i < sizeof(array2) / sizeof(array2[0]);i++) {
    array2[i] = array1[i];
  }*/
  memcpy(array2,array1,sizeof(array1));

  for (i = 0;i < sizeof(array2) / sizeof(array2[0]);i++) {
    printf("array2[%d] = %d\n",i, array2[i]);
  }
  return 0;
}
