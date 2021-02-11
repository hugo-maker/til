// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

// piecewise_linear_distribution

int main()
{
  // イテレータによる指定
  auto bs = {0.0, 1.0, 2.0};
  auto ps = {1.0, 2.0, 1.0};
  std::piecewise_linear_distribution d1(std::begin(bs), std::end(bs), std::begin(ps));

  std::mt19937 e;
  d1(e);

  // 初期化リストと関数オブジェクトによる指定
  std::piecewise_linear_distribution d2(
      {0.0, 1.0, 2.0},
      [] (auto x) {return x;}
      );

  // 個数、最小値、最大値、関数オブジェクトによる指定
  std::piecewise_linear_distribution d3(
      5,
      1.0, 5.0,
      [] (auto x) {return x;}
      );

  for (int i = 0; i != 10; ++i)
  {
    std::cout << d1(e) << " "sv;
  }
  std::cout << "\n"sv;
  for (int i = 0; i != 10; ++i)
  {
    std::cout << d2(e) << " "sv;
  }
  std::cout << "\n"sv;
  for (int i = 0; i != 10; ++i)
  {
    std::cout << d3(e) << " "sv;
  }
  std::cout << "\n"sv;

  auto intervals1 = d1.intervals();
  auto densities1 = d1.densities();
  std::for_each(intervals1.begin(), intervals1.end(), [] (const double & n) {std::cout << n << "\n";});
  std::for_each(densities1.begin(), densities1.end(), [] (const double & n) {std::cout << n << "\n";});
  auto intervals2 = d2.intervals();
  auto densities2 = d2.densities();
  std::for_each(intervals2.begin(), intervals2.end(), [] (const double & n) {std::cout << n << "\n";});
  std::for_each(densities2.begin(), densities2.end(), [] (const double & n) {std::cout << n << "\n";});
  auto intervals3 = d3.intervals();
  auto densities3 = d3.densities();
  std::for_each(intervals3.begin(), intervals3.end(), [] (const double & n) {std::cout << n << "\n";});
  std::for_each(densities3.begin(), densities3.end(), [] (const double & n) {std::cout << n << "\n";});
}
