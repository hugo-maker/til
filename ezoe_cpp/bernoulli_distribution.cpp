// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

// コイントス100回
template <typename Engine>
auto coinflips100(Engine & e)
{
  // t == 100, p == 0.5
  std::binomial_distribution d(100, 0.5);
  return d(e);
}

// 6面ダイス60投
template <typename Engine>
auto roll_for_one(Engine & e)
{
  // t == 60, p == 1.0 / 6.0
  std::binomial_distribution d(60, 1.0 / 6.0);
  return d(e);
}

// 1%であたるくじを100回引く
template <typename Engine>
auto lootbox(Engine & e)
{
  // t == 100, p == 0.01
  std::binomial_distribution d(100, 1.0 / 100.0);
  return d(e);
}

// 表が出るまでコイントス
template <typename Engine>
auto try_coinflips(Engine & e)
{
  std::geometric_distribution d(0.5);
  // 幾何分布は成功する"まで"の試行回数を返す==成功した施行は施行回数に含めない
  // 成功した施行も回数に含めるには +1が必要
  return d(e) + 1;
}

// 1がでるまで6面ダイスを振る
template <typename Engine>
auto try_rolls(Engine & e)
{
  std::geometric_distribution d(1.0 / 6.0);
  return d(e) + 1;
}

// あたりが出るまでくじを引く
template <typename Engine>
auto try_lootboxes(Engine & e)
{
  std::geometric_distribution d(1.0 / 100.0);
  return d(e) + 1;
}

// 表が10回出るまでコイントス
template <typename Engine>
auto count_10_coinflips(Engine & e)
{
  std::negative_binomial_distribution d(10, 0.5);
  return d(e) + 10;
}

// 1が10回でるまで6面ダイスを振る
template <typename Engine>
auto count_10_rolls(Engine & e)
{
  std::negative_binomial_distribution d(10, 1.0 / 6.0);
  return d(e) + 10;
}

// あたりが10回出るまでくじを引く
template <typename Engine>
auto count_10_lootboxes(Engine & e)
{
  std::negative_binomial_distribution d(10, 1.0 / 100.0);
  return d(e) + 10;
}

int main()
{
// ベルヌーイ分布


  // ベルヌーイ分布
  // 施行回数
  const int trial_count = 1000;

  std::mt19937 e;
  std::bernoulli_distribution d(32.0 / 100.0);

  std::array<int, 2> result{};
  for (int i = 0; i != trial_count; ++i)
  {
    // boolからintへの変換はfaluseが0, trueが1
    ++result[d(e)];
  }

  std::cout << "false: "sv << double(result[0]) / double(trial_count) * 100 << "%\n"sv
    << "true: "sv << double(result[1]) / double(trial_count) * 100 << "\n"sv;


  // 二項分布
  // コイントス
  for (int i = 0; i != 10; ++i)
  {
    std::cout << coinflips100(e) << " "sv;
  }
  std::cout << "\n"sv;
  // 6面ダイス
  for (int i = 0; i != 10; ++i)
  {
    std::cout << roll_for_one(e) << " "sv;
  }
  std::cout << "\n"sv;
  // くじ
  for (int i = 0; i != 10; ++i)
  {
    std::cout << lootbox(e) << " "sv;
  }
  std::cout << "\n"sv;


  // 幾何分布
  // 表がでるまでコイントス
  for (int i = 0; i != 10; ++i)
  {
    std::cout << try_coinflips(e) << " "sv;
  }
  std::cout << "\n"sv;
  // 1がでるまで6面ダイスを振る
  for (int i = 0; i != 10; ++i)
  {
    std::cout << try_rolls(e) << " "sv;
  }
  std::cout << "\n"sv;
  // あたりが出るまでくじを引く
  for (int i = 0; i != 10; ++i)
  {
    std::cout << try_lootboxes(e) << " "sv;
  }
  std::cout << "\n"sv;



  // 負の二項分布
  // 表が10回でるまでコイントス
  for (int i = 0; i != 10; ++i)
  {
    std::cout << count_10_coinflips(e) << " "sv;
  }
  std::cout << "\n"sv;
  // 1がでるまで6面ダイスを振る
  for (int i = 0; i != 10; ++i)
  {
    std::cout << count_10_rolls(e) << " "sv;
  }
  std::cout << "\n"sv;
  // あたりが出るまでくじを引く
  for (int i = 0; i != 10; ++i)
  {
    std::cout << count_10_lootboxes(e) << " "sv;
  }
  std::cout << "\n"sv;
}
