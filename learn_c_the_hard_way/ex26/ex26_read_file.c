#include <stdio.h>
#include <stdlib.h>
#include "read_line.h"
#include "dbg.h"

#define ALLOC_SIZE (256)

char **add_line(char **text_data, char *line,
    int *line_alloc_num, int *line_num)
{
  check(*line_alloc_num >= *line_num,
      "ERROR: buffer overflow.");
  /*
   * line_alloc_numがline_numに追いついたら、
   * text_dataを拡張する。
   */
  if (*line_alloc_num == *line_num)
  {
    text_data = realloc(text_data,
        (*line_alloc_num + ALLOC_SIZE) * sizeof(char *));
    *line_alloc_num += ALLOC_SIZE;
  }
  /* text_dataの末尾に一行追加。*/
  text_data[*line_num] = line;
  (*line_num)++;

  return text_data;

error:
  exit(1);
}

char **read_file(FILE *fp, int *line_num_p)
{
  char **text_data = NULL;
  int line_num = 0;
  int line_alloc_num = 0;
  char *line;

  while (read_line(fp, &line) != READ_LINE_EOF)
  {
    text_data = add_line(text_data, line,
        &line_alloc_num, &line_num);
  }
  /* text_dataを本当に必要なサイズまで縮める */
  text_data = realloc(text_data,
      line_num * sizeof(char *));
  *line_num_p = line_num;

  return text_data;
}

int main(void)
{
  char **text_data;
  int line_num;
  int i = 0;

  /* UnixではCtrl+dでEOFを入力できる。*/
  text_data = read_file(stdin, &line_num);

  for (i = 0; i < line_num; i++)
  {
    printf("%s\n", text_data[i]);
  }
  free_buffer();

  return 0;
}
