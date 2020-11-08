#include <stdio.h>

int main(void)
{
  int no;
  scanf("%d", &no);

  switch (no) {
  case 1:
  case 2:
  case 3:
    printf("表彰台\n");
    break;
  case 4:
  default:
    printf("選外\n");
    break;
  }
  return 0;
}
