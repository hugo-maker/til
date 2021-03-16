#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
  vector<int> nums_in_vec{2021, 0, -1, 42, 10101, 25};

  cout << "Enter number to find in collection: ";
  int num_to_find = 0;
  cin >> num_to_find;

  auto element = find(nums_in_vec.cbegin(),
                      nums_in_vec.cend(),
                      num_to_find);

  // Check if find succeeded
  if (element != nums_in_vec.cend())
  {
    cout << "Value " << *element << " found!" << endl;
  }
  else
  {
    cout << "No element contains value " << num_to_find << endl;
  }

  cout << "Finding the first even number using find_if: " << endl;

  auto even_num = find_if(nums_in_vec.cbegin(),
                      nums_in_vec.cend(),
                      [](int element) {return (element % 2) == 0; } );

  if (even_num != nums_in_vec.cend())
  {
    cout << "Number '" << *even_num << "' found at position [";
    cout << distance(nums_in_vec.cbegin(), even_num) << "]" << endl;
  }

  return 0;
}
