// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

template <typename Engine>
auto dice(Engine & e)
{
  // ループを実行する
  while (true)
  {
    // 3bitの乱数を得る
    auto r = e() & 0b111;
    // 0-5なら乱数分布終わり
    if (r <= 5)
    {
      return r + 1;
    }
  }
}

int main()
{
  std::random_device rd;

  // 6面ダイス
  for (int i = 0; i != 10; ++i)
  {
    std::cout << dice(rd) << " "sv;
  }
}
