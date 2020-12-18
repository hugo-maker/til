#include <stdio.h>

//enum宣言
enum {
  SUMMER,
  WINTER,
  NO
};

//プロトタイプ宣言
int olympic(int year);

int main(void)
{
  int year,hold;

  //入力受付部分
  printf("西暦年を入力してください:");
  scanf("%d",&year);

  hold = olympic(year);

  switch (hold) {
    case SUMMER:
      printf("夏季オリンピック\n");
      break;
    case WINTER:
      printf("冬季オリンピック\n");
      break;
    case NO:
      printf("オリンピックは開催されません\n");
      break;
  }

  return 0;
}

int olympic(int year)
{
  if (year % 2 == 0) {
    if (year % 4 == 0) {
      return SUMMER;
    } else {
      return WINTER;
    }
  } else {
    return NO;
  }
}
