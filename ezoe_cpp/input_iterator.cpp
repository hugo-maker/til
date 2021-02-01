// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

template <typename T>
struct cin_iterator
{
  // -----ボイラープレートコード-----
  using difference_type = std::ptrdiff_t;
  using value_type = T;
  using reference = T &;
  using pointer = T *;

  using iterator_category = std::input_iterator_tag;
  // -----ボイラープレートコード-----

  // コンストラクタ
  cin_iterator(bool fail = false)
    : fail(fail)
  {++*this;}

  // キャッシュした値を返す
  // 後ろにconstを付けるとcompile error
  const reference operator *()
  {
    return value;
  }

  // 新しい値をキャッシュする
  cin_iterator &operator ++()
  {
    // 失敗状態でなければ
    if (!fail)
    {
      // 値を読み込む
      std::cin >> value;
      // 失敗状態かどうかも調べる
      fail = std::cin.fail();
    }
    return *this;
  }

  // 後置インクリメント
  cin_iterator operator ++(int)
  {
    // 元の値をコピー
    auto old = *this;
    // 次の値を読み込み
    ++*this;
    // 元の値を返す
    return old;
  }

  // イテレータの等価比較の状態
  bool fail;
  // 値のキャッシュ
  value_type value;
};

// 比較演算子
template <typename T>
bool operator ==(cin_iterator<T> const &l, cin_iterator<T> const &r)
{
  return l.fail == r.fail;
}

template <typename T>
bool operator !=(cin_iterator<T> const &l, cin_iterator<T> const &r)
{
  return !(l == r);
}

template <typename InputIterator>
void print(InputIterator iter, InputIterator end_iter)
{
  while (iter != end_iter)
  {
    std::cout << *iter;
    ++iter;
  }
}

int main()
{
  std::vector<int> v = {1, 2, 3, 4, 5};
  print(std::begin(v), std::end(v));

  cin_iterator<int> iter, fail(true);
  print(iter, fail);
}
