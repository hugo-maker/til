// stdioによる入出力とiostreamによる入出力の同期
#include <cstdio>
#include <ios>
#include <iostream>

int main()
{
  std::ios_base::sync_with_stdio(false);

  std::cout << "Hello ";
  std::puts("World");
  std::cout << "Hello ";
  std::puts("C++");
}
