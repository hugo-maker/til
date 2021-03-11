#include <iostream>
#include <string>
using namespace std;

template <typename type>
const type & get_max(const type & value1, const type & value2)
{
  if (value1 > value2)
  {
    return value1;
  }
  else
  {
    return value2;
  }
}

template <typename type>
void display_comparison(const type & value1, const type & value2)
{
  cout << "get_max(" << value1 << ", " << value2 << ") = ";
  cout << get_max(value1, value2) << endl;
}

int main()
{
  int num1 = -101, num2 = 2011;
  display_comparison(num1, num2);

  double d1 = 3.14, d2 = 3.1416;
  display_comparison(d1, d2);

  string name1("Jack"), name2("John");
  display_comparison(name1, name2);

  return 0;
}
