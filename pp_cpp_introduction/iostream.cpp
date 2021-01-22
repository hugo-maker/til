#include <iostream>

int main()
{
  int a;
  double b;
  char c[80];

  std::cin >> a >> b >> c;

  std::cout << a << "\n"
            << b << "\n"
            << c << std::endl;

  int d;
  std::cin >> d;
  if (std::cin)
  {
    std::cout << d << std::endl;
  }
  else
  {
    std::cout << "error" << std::endl;
  }
}
