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
  print_bool(0);
  print_bool(100);
  print_bool(-1.8);
  print_bool(NULL);
}
