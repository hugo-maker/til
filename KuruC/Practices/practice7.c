#include <stdio.h>

int main(void)
{
  int year;

  printf("西暦年を入力してください\n");
  scanf("%d", &year);
  
  //条件分岐
  if (year % 4 == 0) {
    printf("夏季オリンピックがありました。\n");
  }

  if (year % 2 == 0 && year % 4 != 0) {
    printf("冬季オリンピックがありました。\n");
  }

  if (year % 2 == 1) {
    printf("オリンピックはありませんでした。\n");
  }
  
  return 0;
}
