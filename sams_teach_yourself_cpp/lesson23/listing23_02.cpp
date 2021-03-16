#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// unary predicate for *_if functions
template <typename element_type>
bool is_even(const element_type & number)
{
  return ((number % 2) == 0);
}

int main()
{
  using namespace std;
  vector<int> nums_in_vec{2021, 0, -1, 42, 10101, 25};

  size_t num_zeros = count(nums_in_vec.cbegin(), nums_in_vec.cend(), 0);
  cout << "Number of instances of '0': " << num_zeros << endl << endl;

  size_t num_even_nums = count_if(nums_in_vec.cbegin(), nums_in_vec.cend(),
                                  is_even<int>);

  cout << "Number of even elements: " << num_even_nums << endl;
  cout << "Number of odd elements: ";
  cout << nums_in_vec.size() - num_even_nums << endl;

  return 0;
}
