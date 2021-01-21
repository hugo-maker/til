#include <cstdio>

namespace ns
{
  void f()
  {
    std::puts("ns::f()");
  }
}

const char MESSAGE[] = "Hello, World";

namespace ns
{
  void print_message()
  {
    std::puts(MESSAGE);
  }
}

int main()
{
  ns::f();
  ns::print_message();
}
