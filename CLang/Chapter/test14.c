#include <stdio.h>

int main(void)
{
  /* str[16]だとエラーになる。
   「1~11byteのデータを0~16byteの領域に直接書き込んじゃってます」
   メモリの領域が足りなくなって、overflowしちゃう可能性がありますよってことかな？

  chapter14.c:9:21: warning: ‘%d’ directive writing between 1 and 11 bytes into a region of size between 0 and 16 [-Wformat-overflow=]
    9 |   sprintf(str, "%s%s%d\n", str1, str2, i);

    こっちでもエラー起こしてる。
   「3~29byteのデータを16byteの領域に出力してます」

  chapter14.c:9:3: note: ‘sprintf’ output between 3 and 29 bytes into a destination of size 16
    9 |   sprintf(str, "%s%s%d\n", str1, str2, i);

  */
	char str[32];

	char str1[12] = "DRAGON";
	char str2[] = "QUEST";
	int i = 3;
	sprintf(str,"%s%s%d\n",str1,str2,i);

  /* print(str); だとエラーになる。多分、strに%が含まれている可能性があるから。

chapter14.c:10:10: warning: format not a string literal and no format arguments [-Wformat-security]
   10 |   printf(str);

   */
	printf("%s",str);
	return 0;
}

/*以下、苦Cホームページのソースコードをコピペしたものをそのままコンパイルした際のエラーメッセージ
chapter14.c: In function ‘main’:
chapter14.c:10:10: warning: format not a string literal and no format arguments [-Wformat-security]
   10 |   printf(str);
      |          ^~~
chapter14.c:9:21: warning: ‘%d’ directive writing between 1 and 11 bytes into a region of size between 0 and 16 [-Wformat-overflow=]
    9 |   sprintf(str, "%s%s%d\n", str1, str2, i);
      |                     ^~
chapter14.c:9:3: note: ‘sprintf’ output between 3 and 29 bytes into a destination of size 16
    9 |   sprintf(str, "%s%s%d\n", str1, str2, i);
*/
