#include <iostream>
using namespace std;

class simple_class
{
  int a, b;

public:
  void do_something() {}
};

class base
{
  int a, b;

public:
  virtual void do_something() {}
};

int main()
{
  cout << "sizeof(simple_class) = " << sizeof(simple_class) << endl;
  cout << "sizefo(base) = " << sizeof(base) << endl;

  return 0;
}
