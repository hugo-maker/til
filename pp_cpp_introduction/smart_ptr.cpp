#include <iostream>
#include <memory>

void print(const int *p)
{
  std::cout << *p << std::endl;
}

int main()
{
  std::unique_ptr<int> p(new int(100));
  print(p.get());
}
