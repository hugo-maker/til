#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename element_type>
struct display_element_keep_count
{
  int count;
  display_element_keep_count() : count(0) {}

  void operator () (const element_type & element)
  {
    ++count;
    cout << element << ' ';
  }
};

int main()
{
  vector<int> nums_in_vec{22, 2021, -1, 999, 43, 901};
  cout << "Displaying the vector of integers: " << endl;

  display_element_keep_count<int> result;
  result = for_each(nums_in_vec.begin(),
      nums_in_vec.end(), display_element_keep_count<int> ());

  cout << endl << "Functor invoked " << result.count << " times";

  return 0;
}
