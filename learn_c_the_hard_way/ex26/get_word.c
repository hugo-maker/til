#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "dbg.h"

int get_word(char *buf, int buf_size, FILE *fp)
{
  int len = 0;
  int ch = NULL;

  /* 空白文字を読み飛ばす。 */
  while ((ch = getc(fp)) != EOF && !isalnum(ch)) {};

  if (ch == EOF)
  {
    return EOF;
  }

  do
  {
    buf[len] = ch;
    len++;

    check(len < buf_size, "ERROR: word too long.");
  } while ((ch = getc(fp)) != EOF && isalnum(ch));

  buf[len] = '\0';

  return len;

error:
  return -1;
}

/*
int main(void)
{
  char buf[256];

  while (get_word(buf, 256, stdin) != EOF)
  {
   printf("<<%s>>\n", buf);
  }

  return 0;
}
*/
