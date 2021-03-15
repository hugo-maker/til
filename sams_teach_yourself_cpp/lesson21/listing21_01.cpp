#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

// struct that behaves as a unary function
template <typename element_type>
struct display_element
{
  void operator () (const element_type & element) const
  {
    cout << element << ' ';
  }
};

int main()
{
  vector<int> nums_in_vec{0, 1, 2, 3, -1, -9, 0, -999};
  cout << "Vector of integers contains: " << endl;

  for_each(nums_in_vec.begin(),
      nums_in_vec.end(),
      display_element<int> ());

  // display the list of characters
  list<char> chars_in_list{'a', 'z', 'k', 'd'};
  cout << endl << "List of characters contains: " << endl;

  for_each(chars_in_list.begin(),
      chars_in_list.end(),
      display_element<char> ());

  return 0;
}
