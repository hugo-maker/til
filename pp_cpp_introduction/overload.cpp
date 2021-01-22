#include <cmath>
#include <iostream>

int main()
{
  const float f1 = std::fabs(-10.5f);
  const double f2 = std::fabs(-10.5);
  const long double f3 = std::fabs(-10.5L);

  std::cout << f1 << std::endl;
  std::cout << f2 << std::endl;
  std::cout << f3 << std::endl;
}
