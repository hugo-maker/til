#include <stdio.h>
#include <stdlib.h>
#include "get_word.h"
#include "word_manage.h"

#define WORD_LEN_MAX (1024)

int main(int argc, char *argv[])
{
  char buf[WORD_LEN_MAX];
  FILE *fp;

  if (argc == 1)
  {
    fp = stdin;
  }
  else
  {
    fp = fopen(argv[1], "r");
    check(fp != NULL,
        "Failed to open %s:%s", argv[0], argv[1]);
  }

  /* 単語管理部を初期化する。*/
  word_initialize();

  /* ファイルを読み込みながら、単語を登録する。*/
  while (get_word(buf, WORD_LEN_MAX, fp) != EOF)
  {
    add_word(buf);
  }
  /* 単語の出現頻度を出力する。logfindには必要ないかも。*/
  dump_word(stdout);

  /* 単語管理部の終了処理 */
  word_finalize();

  return 0;

error:
  return -1;
}
