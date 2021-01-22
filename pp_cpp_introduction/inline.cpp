#include <iostream>

template <typename T>
inline T cube(T a)
{
  return a * a * a;
}

int main()
{
  const int x1 = cube(10);
  const double x2 = cube(3.14);
  std::cout << x1 << std::endl;
  std::cout << x2 << std::endl;
}
