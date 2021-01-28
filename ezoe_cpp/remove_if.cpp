// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

// 以下の実装は不完全。
auto remove_if = [] (auto first, auto last, auto pred)
{
  // removeする最初の要素
  auto removing = std::find_if(first, last, pred);

  if (removing == last)
  {
    return last;
  }

  // removeする要素の次の要素
  auto remaining = removing;
  ++remaining;

  // removeする要素に上書きする
  for (; remaining != last; ++remaining)
  {
    // 上書き元も取り除くのならばスキップ
    if (pred(*remaining) == false)
    {
      *removing = *remaining;
      ++removing;
    }
  }

  // 新しい終端イテレータ
  return removing;
};

int main()
{
  auto is_odd = [] (auto x) {return x % 2 == 1;};
  std::vector v = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  auto last = remove_if(std::begin(v), std::end(v), is_odd);

  std::for_each(std::begin(v), last, [] (auto x) {std::cout << x;});
  std::cout << "\n"s;
}
