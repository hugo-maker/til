// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

int main()
{
  std::vector<int> v = {1, 2, 3, 4, 5};

  std::reverse_iterator first{std::end(v)};
  std::reverse_iterator last{std::begin(v)};

  std::for_each(first, last, [] (auto x) {std::cout << x;});

  auto rfirst = std::rbegin(v);
  auto rlast = std::rend(v);
  std::for_each(rfirst, rlast, [] (auto x) {std::cout << x;});
}
