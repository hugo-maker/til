#include <iostream>
using namespace std;

template <typename t>
class test_static
{
public:
  static int static_val;
};

// static member initialization
template <typename t> int test_static<t>::static_val;

int main()
{
  test_static<int> int_instance;
  cout << "Setting static_val for int_instance to 2011" << endl;
  int_instance.static_val = 2011;

  test_static<double> dbl_instance;
  cout << "Setting static_val for double_2 to 1011" << endl;
  dbl_instance.static_val = 1011;

  cout << "int_instance.static_val = " << int_instance.static_val << endl;
  cout << "dbl_instance.static_val = " << dbl_instance.static_val << endl;

  return 0;
}
