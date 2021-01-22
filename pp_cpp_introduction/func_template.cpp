#include <cstdio>

template <typename T>
T change_sign(T a)
{
  return -a;
}

template <typename Ret, typename T>
Ret cast(T a)
{
  return static_cast<Ret>(a);
}

int main()
{
  std::printf("%d\n", change_sign(1000));
  std::printf("%f\n", change_sign(-1.33));

  const double a = 3.14;
  const int b = cast<int, double>(a);
  // 2個目のテンプレート実引数は明示せず、コンパイラの判断に任せることもできる
  // const int b = cast<int>(a);

  std::printf("%d\n", b);
}
