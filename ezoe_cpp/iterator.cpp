// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

// array_iterator実装
template <typename Array>
struct array_iterator
{
  Array &a;
  std::size_t i;

  // コンストラクタ
  array_iterator(Array &a, std::size_t i)
    : a(a), i(i) {}

  // 今参照している要素へのリファレンスを返す
  typename Array::reference operator *()
  {
    return a[i];
  }

  // operator [] 
  // *(i + n) のシンタックスシュガー
  // 既に実装済みのoperator + と operator * を使用している
  typename Array::reference operator [] (std::size_t n) const
  {
    return *(*this + n);
  }

  // 次の要素を指す 前置
  array_iterator &operator ++()
  {
    ++i;
    return *this;
  }
  // 後置
  array_iterator operator ++(int)
  {
    array_iterator copy = *this;
    ++*this;
    return copy;
  }

  // 前の要素を指す 前置
  array_iterator &operator --()
  {
    --i;
    return *this;
  }
  // 後置
  array_iterator operator --(int)
  {
    array_iterator copy = *this;
    --*this;
    return copy;
  }

  // operator +=
  array_iterator &operator +=(std::size_t n)
  {
    i += n;
    return *this;
  }

  // operator -=
  array_iterator &operator -=(std::size_t n)
  {
    i -= n;
    return *this;
  }

  // operator +
  array_iterator operator +(std::size_t n) const
  {
    auto copy = *this;
    copy += n;
    return copy;
  }
  // operator -
  array_iterator operator -(std::size_t n) const
  {
    auto copy = *this;
    copy -= n;
    return copy;
  }

  // bool operator
  bool operator ==(array_iterator const &right) const
  {
    return i == right.i;
  }

  bool operator !=(array_iterator const &right) const
  {
    return i != right.i;
  }

  bool operator <(array_iterator const &right) const
  {
    return i < right.i;
  }

  bool operator <=(array_iterator const &right) const
  {
    return i <= right.i;
  }

  bool operator >(array_iterator const &right) const
  {
    return i > right.i;
  }

  bool operator >=(array_iterator const &right) const
  {
    return i >= right.i;
  }
};

// constなイテレータ array_const_iterator実装 
template <typename Array>
struct array_const_iterator
{
  Array const &a;
  std::size_t i;

  // コンストラクタ
  array_const_iterator(Array const &a, std::size_t i)
    : a(a), i(i) {}

  // array_iteratorからの変換コンストラクタ
  array_const_iterator(typename array_iterator<Array>::array_iterator const &iter)
    : a(iter.a), i(iter.i) {}

  typename Array::const_reference operator *() const
  {
    return a[i];
  }

  typename Array::const_reference operator [] (std::size_t i) const 
  {
    return *(*this + i);
  }

  array_const_iterator &operator ++()
  {
    ++i;
    return *this;
  }
  array_const_iterator operator ++(int)
  {
    array_const_iterator copy = *this;
    ++*this;
    return copy;
  }

  array_const_iterator &operator --()
  {
    --i;
    return *this;
  }
  array_const_iterator operator --(int)
  {
    array_const_iterator copy = *this;
    --*this;
    return copy;
  }

  array_const_iterator &operator +=(std::size_t n)
  {
    i += n;
    return *this;
  }
  array_const_iterator &operator -=(std::size_t n)
  {
    i -= n;
    return *this;
  }
  array_const_iterator operator +(std::size_t n) const
  {
    auto copy = *this;
    copy += n;
    return copy;
  }
  array_const_iterator operator -(std::size_t n) const
  {
    auto copy = *this;
    copy -= n;
    return copy;
  }

  // bool operator
  bool operator ==(array_const_iterator const &right) const
  {
    return i == right.i;
  }

  bool operator !=(array_const_iterator const &right) const
  {
    return i != right.i;
  }

  bool operator <(array_const_iterator const &right) const
  {
    return i < right.i;
  }

  bool operator <=(array_const_iterator const &right) const
  {
    return i <= right.i;
  }

  bool operator >(array_const_iterator const &right) const
  {
    return i > right.i;
  }

  bool operator >=(array_const_iterator const &right) const
  {
    return i >= right.i;
  }
};

// array実装
template <typename T, std::size_t N>
struct array
{
  T storage[N];

  using iterator = array_iterator<array>;
  using const_iterator = array_const_iterator<array>;

  // const arrayのときにconst_iteratorを返す
  const_iterator begin() const
  {
    return const_iterator(*this, 0);
  }
  const_iterator end() const
  {
    return const_iterator(*this, N);
  }

  // 常にconst_iteratorを返す
  const_iterator cbegin() const
  {
    return const_iterator(*this, 0);
  }
  const_iterator cend() const
  {
    return const_iterator(*this, N);
  }

  // 最初の要素へのイテレータ
  iterator begin()
  {
    return array_iterator(*this, 0);
  }

  // 最後の次の要素へのイテレータ
  iterator end()
  {
    return array_iterator(*this, N);
  }

  // その他のメンバー
  using reference = T &;
  using const_reference = T const &;

  reference operator [] (std::size_t i)
  {
    return storage[i];
  }
  const_reference operator [] (std::size_t i) const
  {
    return storage[i];
  }

  reference front()
  {
    return storage[0];
  }
  const_reference front() const
  {
    return storage[0];
  }

  reference back()
  {
    return storage[N - 1];
  }
  const_reference back() const
  {
    return storage[N - 1];
  }

  using size_type = std::size_t;
  using const_size_type = std::size_t const;

  size_type size()
  {
    return N;
  }
  const_size_type size() const
  {
    return N;
  }
};

int main()
{
  // array_iterator test
  array<int, 5> a = {1, 2, 3, 4, 5};

  std::for_each(std::begin(a), std::end(a), [] (auto x) {std::cout << x;});
  std::cout << "\n"s;

  auto iter = a.begin();
  std::cout << *iter << "\n"s;

  ++++iter;
  std::cout << *iter << "\n"s;
  std::cout << *iter++ << "\n"s;
  std::cout << *iter << "\n"s;

  ----iter;
  std::cout << *iter << "\n"s;
  std::cout << *iter-- << "\n"s;
  std::cout << *iter << "\n"s;

  auto i = a.end();
  i -= 5;
  std::cout << *(i + 3) << "\n"s;
  std::cout << a[3] << "\n"s;

  auto b = std::begin(a);
  auto c = b + 1;

  std::cout << std::boolalpha;
  auto bool1 = b < c;
  auto bool2 = b <= c;
  auto bool3 = b > c;
  auto bool4 = b >= c;
  std::cout << bool1 << "\n"s;
  std::cout << bool2 << "\n"s;
  std::cout << bool3 << "\n"s;
  std::cout << bool4 << "\n"s;

  // array_const_iterator test
  const array<int, 5> con_a = {1, 2, 3, 4, 5};

  std::for_each(std::begin(con_a), std::end(con_a), [] (auto x) {std::cout << x;});
  std::cout << "\n"s;

  auto con_iter = con_a.cbegin();
  std::cout << *con_iter << "\n"s;

  ++++con_iter;
  std::cout << *con_iter << "\n"s;
  std::cout << *con_iter++ << "\n"s;
  std::cout << *con_iter << "\n"s;

  ----con_iter;
  std::cout << *con_iter << "\n"s;
  std::cout << *con_iter-- << "\n"s;
  std::cout << *con_iter << "\n"s;

  auto con_i = con_a.cend();
  con_i -= 5;
  std::cout << *(con_i + 3) << "\n"s;
  std::cout << a[3] << "\n"s;

  auto con_b = std::begin(con_a);
  auto con_c = con_b + 1;

  auto con_bool1 = con_b < con_c;
  auto con_bool2 = con_b <= con_c;
  auto con_bool3 = con_b > con_c;
  auto con_bool4 = con_b >= con_c;
  std::cout << con_bool1 << "\n"s;
  std::cout << con_bool2 << "\n"s;
  std::cout << con_bool3 << "\n"s;
  std::cout << con_bool4 << "\n"s;
}
