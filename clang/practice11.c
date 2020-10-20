#include <stdio.h>

//プロトタイプ宣言
int olympic();

int main(void)
{
  int year = 0;
  do {
    if (year != 0) {
      if (year < 1896) printf("最初の近代オリンピックが開催されたのは1896年です。西暦年を再入力してください。\n");
      if (year > 2020) printf("現在は2020年です。西暦年を再入力してください。\n");
    } 
    printf("西暦年を入力してください :");
    scanf("%d", &year);
  } while (year < 1896 || year > 2020);

  int answer;
  answer = olympic(year);

  /*if (answer == 0) {
    printf("オリンピックは開催されます\n");
  } else {
    printf("オリンピックは開催されません\n");
  }*/

  switch (answer) {
    case 0:
      printf("オリンピックは開催されません\n");
      break;
    case 1:
      printf("夏季オリンピック\n");
      break;
    case 2:
      printf("冬季オリンピック\n");
      break;
  }
  return 0;
}

int olympic(int year)
{
  /*int result;
  result = year % 2;
  return result;*/
  if (year % 2 == 0) {
    if (year % 4 == 0) {
      return 1;
    } else {
      return 2;
    }
  } else {
    return 0;
  }
}
