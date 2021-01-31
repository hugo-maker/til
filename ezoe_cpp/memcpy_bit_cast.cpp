// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

// 自作memcpy
void *memcpy(void *dest, void const *src, std::size_t n)
{
  // destをstd::byte *型に変換
  auto d = static_cast<std::byte *>(dest);
  // srcをstd::byte const *型に変換
  auto s = static_cast<std::byte const *>(dest);
  // srcからnバイトコピーするのでnバイト先のアドレスを得る
  auto last = s + n;
  // nバイトコピーする
  while (s != last)
  {
    *d = *s;
    ++d;
    ++s;
  }

  return dest;
}

// 自作memcpy (operator [] を用いた場合)
void *another_memcpy(void *dest, void const *src, std::size_t n)
{
  auto d = static_cast<std::byte *>(dest);
  auto s = static_cast<std::byte const *>(dest);

  for (std::size_t i = 0; i != n; ++i)
  {
    d[i] = s[i];
  }
  
  return dest;
}

template <typename To, typename From>
To bit_cast(From const &from)
{
  // 値fromのバイト列をTo型の値として解釈して返す
  To to;
  memcpy(&to, &from, sizeof(To));
  return to;
}

template <typename T>
void print_size()
{
  std::cout << sizeof(T) << "\n"s;
}

// 生のアドレスを出力
template <typename T>
void print_raw_address(T ptr)
{
  std::cout << bit_cast<std::uintptr_t>(ptr) << "\n"s;
}

struct Object
{
  int x = 123; 
  int y = 456;
  int z = 789;
};

int main()
{
  print_size<int *>();
  print_size<double *>();
  print_size<int **>();
  print_size<std::uintptr_t>();

  int data[3] = {0, 1, 2};
  print_raw_address(&data[0]);
  print_raw_address(&data[1]);
  print_raw_address(&data[2]);

  int a[4] = {0, 1, 2, 3};

  int *a0 = &a[0];
  print_raw_address(a0);

  int *a3 = a0 + 3;
  print_raw_address(a3);

  int *a1 = a3 - 2;
  print_raw_address(a1);
  print_size<int>();
  print_size<Object>();

  Object object;

  std::byte *start = bit_cast<std::byte *>(&object);
  // offset 0
  int *x = bit_cast<int *>(start + 0);
  // offset 4
  int *y = bit_cast<int *>(start + 4);
  // offset 8
  int *z = bit_cast<int *>(start + 8);

  std::cout << *x << *y << *z << "\n"s;
}
