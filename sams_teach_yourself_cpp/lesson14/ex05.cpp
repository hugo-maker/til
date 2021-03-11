#include <iostream>
using namespace std;

void display()
{
}

template <typename first, typename... last>
void display(first a, last... z)
{
  cout << a << endl;
  display(z...);
}

int main()
{
  display('a');
  display(3.1416);
  display('a', 'b', 'c', 3.1416, -18, true);
  display('y', "Hello, World");

  return 0;
}
