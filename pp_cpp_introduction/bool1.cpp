#include <cstdio>

void print_bool(bool b)
{
  if (b)
  {
    std::puts("true");
  }
  else
  {
    std::puts("false");
  }
}

int main()
{
  bool b = true;
  print_bool(b);

  b = !b;
  print_bool(b);
}
