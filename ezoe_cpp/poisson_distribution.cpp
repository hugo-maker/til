// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

// poisson_distribution

// 一ヶ月の事故発生件数を乱数で返す
template <typename Engine>
auto traffic_accidents(Engine & e)
{
  std::poisson_distribution d(10.0);
  return d(e);
}

// ある事故から次の事故までの時間間隔の乱数を日数で得る
template <typename Engine>
auto until_next_traffic_accident(Engine & e)
{
  std::exponential_distribution d(10.0);
  return d(e) * 30.0;
}

int main()
{
  std::mt19937 e;

  // ポアソン分布
  for (int i = 0; i != 10; ++i)
  {
    std::cout << traffic_accidents(e) << " "sv;
  }
  std::cout << "\n"sv;

  // 指数分布
  for (int i = 0; i != 10; ++i)
  {
    std::cout << until_next_traffic_accident(e) << " "sv;
  }
  std::cout << "\n"sv;
}
