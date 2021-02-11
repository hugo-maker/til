// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

// sampling_distributions

// 1の目が2倍の確率で出るいかさまダイス
template <typename Engine>
int roll_dice(Engine & e)
{
  std::discrete_distribution d = {2.0, 1.0, 1.0, 1.0, 1.0, 1.0};
  return d(e) + 1;
}

int main()
{
  // イテレータのペアで変数宣言
  std::array ps = {1.0, 2.0, 3.0};
  std::discrete_distribution d(std::begin(ps), std::end(ps));

  std::mt19937 e;

  for (int i = 0; i != 10; ++i)
  {
    std::cout << d(e) << " "sv;
  }
  std::cout << "\n"sv;

  // 初期化リストで変数宣言
  // std::discrete_distribution d2 = {1.0, 2.0, 3.0};
  std::discrete_distribution d2({1.0, 2.0, 3.0});

  for (int i = 0; i != 10; ++i)
  {
    std::cout << d2(e) << " "sv;
  }
  std::cout << "\n"sv;

  // 個数, デルタ, 関数
  std::discrete_distribution d3(5, 0.0, 1.0, 
      [](auto x) 
      {
        std::cout << x << '\n';
        if (x < 0.3)
        {
          x = 0.3;
        }
        if (x > 0.8)
        {
          x = 0.8;
        }
        return x;
      });

  auto v1 = d.probabilities();
  std::for_each(v1.begin(), v1.end(), [] (const double & n) {std::cout << n << "\n";});
  auto v2 = d2.probabilities();
  std::for_each(v2.begin(), v2.end(), [] (const double & n) {std::cout << n << "\n";});
  auto v3 = d3.probabilities();
  std::for_each(v3.begin(), v3.end(), [] (const double & n) {std::cout << n << "\n";});

  for (int i = 0; i != 50; ++i)
  {
    std::cout << roll_dice(e) << " "sv;
  }
  std::cout << "\n"sv;
}
