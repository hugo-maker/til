#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename element_type>
struct display_element_keep_count
{
  int count;
  display_element_keep_count() : count (0) {}

  void operator () (const element_type & element)
  {
    ++count;
    cout << element << ' ';
  }
};

int main()
{
  vector<int> nums_in_vec{2021, 0, -1, 42, 10101, 25};

  cout << "Elements in vector are: " << endl;
  //display_element_keep_count<int> functor =
  auto functor =
    for_each(nums_in_vec.cbegin(),
            nums_in_vec.cend(),
            display_element_keep_count<int> ());
  cout << endl;

  // Use the state stored in the return value of for_each
  cout << "'" << functor.count << "' elements displayed" << endl;

  string str ("for_each and strings!");
  cout << "Sample string: " << str << endl;

  cout << "Characters displayed using lambda: " << endl;
  int num_chars = 0;
  for_each(str.cbegin(), str.cend(),
      [&num_chars](char c) {cout << c << ' '; ++num_chars; } );

  cout << endl;
  cout << "'" << num_chars << "' characters displayed" << endl;

  return 0;
}
