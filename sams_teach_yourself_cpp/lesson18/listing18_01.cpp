#include <list>
#include <vector>

int main()
{
  using namespace std;

  // instantiate an empty list
  list<int> link_ints;

  // instantiate a list with 10 integers
  list<int> list_with10_integers(10);

  // instantiate a list with 4 integers, each value 99
  list<int> list_with4_integers_each99(4, 99);

  // create an exact copy of an existing list
  list<int> list_copy_another(list_with4_integers_each99);

  // a vector with 10 integers, each 2021
  vector<int> vec_integers(10, 2021);

  // instantiate a list using values from another container
  list<int> list_contains_copy_of_another(vec_integers.cbegin(), vec_integers.cend());

  return 0;
}
