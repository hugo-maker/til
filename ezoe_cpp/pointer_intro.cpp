// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

int f(int x)
{
  std::cout << x << "\n"s;
  return x;
}

using f_ptr = int (*)(int);

// 関数へのポインタを引数にとり、関数へのポインタを返す関数g
f_ptr g(f_ptr p)
{
  p(0);
  return p;
}

template <typename T>
using add_pointer_t = T *;

int main()
{
  int x = 123;
  int *p = &x;
  int **pp = &p;

  int value1 = **pp;
  std::cout << value1 << "\n"s;

  int y = 456;
  *pp = &y;

  int value2 = **pp;
  std::cout << value2 << "\n"s;

  using f_type = int(int);
  using f_pointer = f_type *;

  f_pointer ptr = &f;

  (*ptr)(123);
  // 関数へのポインタを経由した関数呼びだし
  ptr(123);

  g(&f);

  // int *
  add_pointer_t<int> a = nullptr;
  // int **
  add_pointer_t<int *> b = nullptr;
  // int (*)(int)
  add_pointer_t<int(int)> c = nullptr;
  // int (*)[5]
  add_pointer_t<int [5]> d = nullptr;
  // int **
  add_pointer_t<add_pointer_t<int>> e = nullptr;

  // referenceだとerror
  // add_pointer_t<int &> ptr = nullptr;

  // これはOK
  std::add_pointer_t<int &> pointer = nullptr;
  
  // int
  std::remove_pointer_t<int *> int_a = 0;
  std::cout << int_a << "\n"s;
  std::remove_pointer_t<std::add_pointer_t<int>> int_b = 0;
  std::cout << int_b << "\n"s;
}
