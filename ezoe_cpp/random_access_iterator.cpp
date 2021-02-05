// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

template <typename T>
struct iota_iterator
{
  // イテレータ同士の距離を表現する型
  using difference_type = std::ptrdiff_t;
  // 要素の型
  using value_type = T;
  using reference = T &;
  using pointer = T *;
  using iterator_category = std::bidirectional_iterator_tag;
  // 値を保持する
  T value;

  // コンストラクタ
  iota_iterator(T value = 0)
    : value(value)
  {}

  // その他のコード

  // 非const
  reference operator *() noexcept
  {
    return value;
  }
  // const
  const reference operator *() const noexcept
  {
    return value;
  }

  // 前置
  iota_iterator &operator ++() noexcept
  {
    ++value;
    return *this;
  }
  // 後置
  iota_iterator operator ++(int) noexcept
  {
    auto temp = *this;
    ++*this;
    return temp;
  }
  
  // 前置
  iota_iterator &operator --() noexcept
  {
    --value;
    return *this;
  }
  // 後置
  iota_iterator operator --(int) noexcept
  {
    auto temp = *this;
    --*this;
    return temp;
  }

  bool operator ==(iota_iterator const &i) const noexcept
  {
    return value == i.value;
  }
  bool operator !=(iota_iterator const &i) const noexcept
  {
    return !(*this == i);
  }

  // for random access iterator
  bool operator <(iota_iterator const &i) const noexcept
  {
    return value < i.value;
  }
  bool operator <=(iota_iterator const &i) const noexcept
  {
    return value <= i.value;
  }
  bool operator >(iota_iterator const &i) const noexcept
  {
    return value > i.value;
  }
  bool operator >=(iota_iterator const &i) const noexcept
  {
    return value >= i.value;
  }

  // for random access iterator
  iota_iterator &operator +=(difference_type n)
  {
    value += n;
    return *this;
  }
  iota_iterator operator +(difference_type n) const
  {
    auto temp = *this;
    temp += n;
    return *this;
  }
  iota_iterator &operator -=(difference_type n)
  {
    value -= n;
    return *this;
  }
  iota_iterator operator -(difference_type n) const
  {
    auto temp = *this;
    temp -= n;
    return *this;
  }

  difference_type operator -(iota_iterator const &i)
  {
    return value -i.value;
  }
};

// クラス外フリー関数
// for random access iterator
template <typename T>
iota_iterator<T> operator +
(
  iota_iterator<T> i,
  typename iota_iterator<T>::difference_type n
)
{
  return i + n;
}

template <typename T>
iota_iterator<T> operator -
(
  iota_iterator<T> i,
  typename iota_iterator<T>::difference_type n
)
{
  return i - n;
} 

int main()
{
  // i(0)
  iota_iterator<int> i;
  // iota_iterator<int>
  iota_iterator first(0), last(10);

  // lastにiをコピー
  i = last;

  // 非constなオブジェクト
  iota_iterator non_const(0);
  // 非const版のoperator *を呼びだす
  int value = *non_const;
  // 変更可
  *non_const = 1;

  // constなオブジェクト
  iota_iterator immutable(0);
  // const版のoperator *を呼び出す
  int const_value = *immutable;
}
