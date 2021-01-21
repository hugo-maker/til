#include <iostream>

void f(const void *p)
{
  if (p == nullptr)
  {
    std::cout << "p is null" << std::endl;
  }
  else
  {
    std::cout << "p is not null" << std::endl;
  }
}

int main()
{
  int n = 100;

  int *p = &n;
  f(p);
  p = nullptr;
  f(p);
}
