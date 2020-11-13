#include <stdio.h>

// nの最大値
#define N_MAX (100)

/* 数字を使用したら、その数字と等しい配列番号の要素を1にする。それを可能にするために、配列の要素数に1を加えている(配列番号は0から始まるため)。
 * 例) 100を使用したとき、配列番号100の要素を1にする。DrawPokerの役判定と同じ考え方*/
int used_flag[N_MAX + 1];

int result[N_MAX];
int n;
int r;

void print_result(void)
{
  int i;

  for (i = 0; i < r; i++)
  {
    printf("%d ", result[i]);
  }
  printf("\n");
}

void permutation(int nth)
{
  int i;

  if (nth == r)
  {
    print_result();
    return;
  }

  for (i = 1; i <= n; i++)
  {
    if (used_flag[i] == 0)
    {
      result[nth] = i;
      used_flag[i] = 1;
      permutation(nth + 1);
      used_flag[i] = 0;
    }
  }
}

int main(int argc, char **argv)
{
  sscanf(argv[1], "%d", &n);
  sscanf(argv[2], "%d", &r);

  permutation(0);

  return 0;
}
