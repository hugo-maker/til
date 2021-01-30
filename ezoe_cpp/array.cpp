// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

template <typename T, std::size_t N>
struct array
{
  T storage[N];

  void fill(T const &u)
  {
    for (std::size_t i = 0; i != N; ++i)
    {
      storage[i] = u;
    }
  }

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

template <typename Container>
void print(Container const &c)
{
  for (std::size_t i = 0; i != c.size(); ++i)
  {
    std::cout << c[i];
  }
  std::cout << "\n"s;
}

int main()
{
  array<int, 5> a = {1, 2, 3, 4, 5};
  print(a);

  std::cout << a.front() << "\n"s;
  std::cout << a.back() << "\n"s;

  array<int, 10> b;
  b.fill(1);
  print(b);
}
