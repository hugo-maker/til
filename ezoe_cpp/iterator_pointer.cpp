// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

template <typename Array>
struct array_iterator
{
  using pointer = typename Array::pointer;
  using reference = typename Array::reference;
  pointer p;

  array_iterator(pointer p)
    : p(p) {}

  reference operator *()
  {
    return *p;
  }

  array_iterator &operator ++()
  {
    ++p;
    return *this;
  }

  reference operator [](std::size_t n)
  {
    return p[n];
  }
};

template <typename T, std::size_t N>
struct array
{
  T storage[N];

  // pointer
  using iterator = T *;

  iterator begin()
  {
    return &storage[0];
  }

  iterator end()
  {
    return begin() + N;
  }
};

int main()
{
  array<int, 5> a = {1, 2, 3, 4, 5};

  auto iter = a.begin();
  std::cout << *iter << "\n"s;
  ++++iter;
  std::cout << *iter << "\n"s;

  iter = a.end();
  std::cout << *iter << "\n"s;
}
