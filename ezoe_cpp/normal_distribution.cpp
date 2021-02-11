// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

// normal_distribution

int main()
{
  std::mt19937 e;

  // 正規分布
  std::normal_distribution d(0.0, 1.0);
  d.mean();
  d.stddev();

  for (int i = 0; i != 10; ++i)
  {
    std::cout << d(e) << " "sv;
  }
  std::cout << "\n"sv;

  // 対数正規分布
  std::lognormal_distribution ld(0.0, 1.0);
  ld.m();
  ld.s();

  for (int i = 0; i != 10; ++i)
  {
    std::cout << ld(e) << " "sv;
  }
  std::cout << "\n"sv;

  // カイ二乗分布
  std::chi_squared_distribution csd(1.0);
  csd.n();

  for (int i = 0; i != 10; ++i)
  {
    std::cout << csd(e) << " "sv;
  }
  std::cout << "\n"sv;

  // コーシー分布
  std::cauchy_distribution cd(0.0, 1.0);
  cd.a();
  cd.b();

  for (int i = 0; i != 10; ++i)
  {
    std::cout << cd(e) << " "sv;
  }
  std::cout << "\n"sv;
}
