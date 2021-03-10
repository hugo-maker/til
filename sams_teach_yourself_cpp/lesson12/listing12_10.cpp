#include <iostream>
#include <string>
using namespace std;

class display
{
public:
  void operator () (string input) const
  {
    cout << input << endl;
  }
};

int main()
{
  display display_func_obj;

  // equivalent to display_func_obj.operator () ("Display this string! ");

  display_func_obj ("Display this string! ");

  return 0;
}
