// 参考 http://www.yamamo10.jp/yamamoto/lecture/2007/5E_comp_app/gnuplot/html/node4.html
// コンパイル時末尾に-lmを付けないと、gccがmath libraryにリンクできていないため、undefined reference to 'sin'と表示され、エラーになる
// gcc -o test_gnuplot test_gnuplot.c -lm
#include <stdio.h>
#include <math.h>

#define NX 720

int main(void)
{
  FILE *gp;
  int i = 0;
  double dx, x[NX + 1], y[NX + 1];

  // データを作成
  dx = 4 * M_PI / NX;
  for (i = 0; i <= NX; i++)
  {
    x[i] = -2 * M_PI + i * dx;
    y[i] = sin(x[i]);
  }

  // グラフを作成
  gp = popen("gnuplot -persist", "w"); // パイプを開く
  fprintf(gp, "set xrange [-6.5:6.5]\n");
  fprintf(gp, "set yrange [-1.5:1.5]\n");
  fprintf(gp, "plot '-' with lines linetype 1 title \"sin\"\n");

  for (i = 0; i <= NX; i++)
  {
    fprintf(gp, "%f\t%f\n", x[i], y[i]); // データの書き込み
  }
  fprintf(gp, "e\n"); // データの終了

  pclose(gp); // パイプを閉じる

  return 0;
}
