#include <iostream>
using namespace std;

// template with default params: int & double
template <typename t1 = int, typename t2 = double>
class holds_pair
{
private:
  t1 value1;
  t2 value2;

public:
  holds_pair(const t1 & val1, const t2 & val2) // constructor
    : value1(val1), value2(val2) {}

  // Accessor functions
  const t1 & get_first_value() const
  {
    return value1;
  }

  const t2 & get_second_value() const
  {
    return value2;
  }
};

int main()
{
  holds_pair<> pair_int_dbl(300, 10.90);
  holds_pair<short, const char *> pair_short_str(25, "Learn templates, love C++");

  cout << "The first object contains -" << endl;
  cout << "Value 1: " << pair_int_dbl.get_first_value() << endl;
  cout << "Value 2: " << pair_int_dbl.get_second_value() << endl;

  cout << "The second object contains -" << endl;
  cout << "Value 1: " << pair_short_str.get_first_value() << endl;
  cout << "Value 2: " << pair_short_str.get_second_value() << endl;

  return 0;
}
