#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "read_line.h"
#include "dbg.h"

#define ALLOC_SIZE (256)

/*
 * 行を読み込むバッファ。必要に応じて拡張される。
 * ただし、縮むことはない。
 * free_buffer() を呼び出すと解放される。
 */
static char *st_line_buffer = NULL;

/* st_line_bufferの先に割り当てられている領域のサイズ。*/
static int st_current_buffer_size = 0;

/*
 * st_line_bufferの中で
 * 現在文字が格納されている部分のサイズ。
 */
static int st_current_used_size = 0;

/*
 * st_line_bufferの末尾に一文字追加する。
 * 必要とあれば、st_line_bufferの先の領域を拡張する。
 */
static ReadLineStatus add_character(int ch)
{
  check(st_current_buffer_size >= st_current_used_size,
      "ERROR: buffer overflow.");

  /*
   * st_current_used_sizeがst_current_buffer_size
   * に追いついたら、バッファを拡張する。
   */
  // 比較対象は右側に。調査対象を左に。
  if (st_current_used_size == st_current_buffer_size)
  {
    char *temp;
    temp = realloc(st_line_buffer,
        (st_current_buffer_size + ALLOC_SIZE) * sizeof(char));

    if (temp == NULL)
    {
      return READ_LINE_OUT_OF_MEMORY;
    }
    st_line_buffer = temp;
    st_current_buffer_size += ALLOC_SIZE;
  }
  /* バッファの末尾に一文字追加。*/
  st_line_buffer[st_current_used_size] = ch;
  st_current_used_size++;

  return READ_LINE_SUCCESS;

error:
  return READ_LINE_OUT_OF_MEMORY;
}

void free_buffer(void)
{
  free(st_line_buffer);
  st_line_buffer = NULL;
  st_current_buffer_size = 0;
  st_current_used_size = 0;
}

/* fpから一行読み込む。*/
ReadLineStatus read_line(FILE *fp, char **line)
{
  int ch;
  ReadLineStatus status = READ_LINE_SUCCESS;

  st_current_used_size = 0;
  while ((ch = getc(fp)) != EOF)
  {
    if (ch == '\n')
    {
      status = add_character('\0');
      check(status == READ_LINE_SUCCESS, "Failed to read.");
      break;
    }
    status = add_character(ch);
    check(status == READ_LINE_SUCCESS, "Failed to read.");
  }
  if (ch == EOF)
  {
    if (st_current_used_size > 0)
    {
      /* 最後の行の後に改行がなかった場合、改行文字を追加 */
      status = add_character('\0');
      check(status == READ_LINE_SUCCESS, "Failed to read.");
    }
    else
    {
      status = READ_LINE_EOF;
      goto FUNC_END;
    }
  }

  *line = malloc(sizeof(char) * st_current_used_size);
  check(*line != NULL, "Failed to read.");

  strcpy(*line, st_line_buffer);

FUNC_END:
  return status;

error:
  free_buffer();
  return status;
}
