// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

struct cout_iterator
{
  // -----ボイラープレートコード-----
  // 出力イテレータでは使わないのでvoid
  using difference_type = void;
  using value_type = void;
  using reference = void;
  using pointer = void;

  using iterator_category = std::output_iterator_tag;

  // 何もせず、自分自身を返すだけ
  cout_iterator &operator *()
  {
    return *this;
  }
  cout_iterator &operator ++()
  {
    return *this;
  }
  cout_iterator &operator ++(int)
  {
    return *this;
  }
  // -----ボイラープレートコード-----

  template <typename T>
  cout_iterator &operator =(T const &x)
  {
    std::cout << x;
    return *this;
  }
};

int main()
{
  std::vector<int> v = {1, 2, 3, 4, 5};
  cout_iterator out;
  std::copy(std::begin(v), std::end(v), out);

  // 上記と同じ処理
  std::vector<int> v2 = {1, 2, 3, 4, 5};
  std::ostream_iterator<int> out2(std::cout);
  std::copy(std::begin(v2), std::end(v2), out2);

  std::vector<int> v3 = {1, 2, 3, 4, 5};
  std::vector<int> tmp;
  auto out3 = std::back_inserter(tmp);
  std::copy(std::begin(v3), std::end(v3), out3);
}
