#include <iostream>
using namespace std;

template <typename t1 = int, typename t2 = double>
class holds_pair
{
private:
  t1 value1;
  t2 value2;

public:
  holds_pair(const t1 & val1, const t2 & val2)
    : value1(val1), value2(val2) {}

  // accessor functions
  const t1 & get_first_value() const;
  const t2 & get_second_value() const;
};

// specialization of holds_pair for types int & int here
template<> class holds_pair<int, int>
{
private:
  int value1;
  int value2;
  string str_fun;

public:
  holds_pair(const int & val1, const int & val2)
    : value1(val1), value2(val2) {}

  const int & get_first_value() const
  {
    cout << "Returning integer " << value1 << endl;
    return value1;
  }
};

int main()
{
  holds_pair<int, int> pair_int_int(222, 333);
  pair_int_int.get_first_value();

  return 0;
}

