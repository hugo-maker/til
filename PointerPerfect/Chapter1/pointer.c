#include <stdio.h>

int main(void)
{
  int hoge = 5;
  int piyo = 10;
  int *hoge_p;

  /* print the addresses of each variables */
  printf("&hoge.. %p\n", (void*)&hoge);
  printf("&piyo.. %p\n", (void*)&piyo);
  printf("&hoge_p.. %p\n", (void*)&hoge_p);

  /* assgin the address of hoge to hoge_p(pointer variable) */
  hoge_p = &hoge;
  printf("hoge_p..%p\n", (void*)hoge_p);

  /* print the value of hoge via hoge_p */
  printf("*hoge_p..%d\n", *hoge_p);

  /* change the value of hoge via hoge_p */
  *hoge_p = 10;
  printf("hoge..%d\n", hoge);

  return 0;
}
