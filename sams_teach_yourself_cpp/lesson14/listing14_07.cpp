#include <iostream>
using namespace std;

template <typename res, typename val_type>
void sum(res & result, val_type & val)
{
  result = result + val;
}

template <typename res, typename first, typename... rest>
void sum(res & result, first val1, rest... val_n)
{
  result = result + val1;
  return sum(result, val_n ...);
}

int main()
{
  double d_result = 0;
  sum(d_result, 3.14, 4.56, 1.1111);
  cout << "d_result = " << d_result << endl;

  string str_result;
  sum(str_result, "Hello ", "World");
  cout << "str_result = " << str_result.c_str() << endl;

  return 0;
}
