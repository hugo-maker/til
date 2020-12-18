#include <stdio.h>
#include <string.h>
#include <time.h>

int main(void)
{
  char dest[100000];
  char src[100000];
  int i;

  // memset
  clock_t begin = clock();
  memset(dest, 0x1, 100000);
  clock_t end = clock();
  printf("memset time1: %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

  begin = clock();
  memset(dest, 0x0, 100000);
  end = clock();
  printf("memset time2: %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

  // memcpy()
  for (i = 0; i < 100000; i++)
  {
    src[i] = i;
  }

  begin = clock();
  memcpy(dest, src, 100000);
  end = clock();
  printf("memcpy time1: %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

  // memmove
  begin = clock();
  memmove(dest, src, 100000);
  end = clock();
  printf("memmove time1: %f seconds\n", (double)(end - begin) / CLOCKS_PER_SEC);

  return 0;
}
