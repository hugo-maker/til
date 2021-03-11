#include <iostream>
#include <tuple>
#include <string>
using namespace std;

template <typename tuple_type>
void display_tuple_info(tuple_type & tup)
{
  const int num_members = tuple_size<tuple_type>::value;
  cout << "Num elements in tuple: " << num_members << endl;
  cout << "Last element value: " << get<num_members - 1>(tup) << endl;
}

int main()
{
  tuple<int, char, string> tup1(make_tuple(101, 's', "Hello Tuple!"));
  display_tuple_info(tup1);

  auto tup2(make_tuple(3.14, false));
  display_tuple_info(tup2);

  auto concat_tup(tuple_cat(tup2, tup1)); // contains tup2, tup1 members
  display_tuple_info(concat_tup);

  double pi;
  string sentence;
  tie(pi, ignore, ignore, ignore, sentence) = concat_tup;
  cout << "Unpacked! Pi: " << pi << " and \"" << sentence << "\"" << endl;

  return 0;
}
