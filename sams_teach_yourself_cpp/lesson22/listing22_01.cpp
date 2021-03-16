#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
  vector<int> nums_in_vec{101, -4, 500, 21, 42, -1};

  list<char> chars_in_list{'a', 'h', 'z', 'k', 'l'};
  cout << "Display elements in a vector using a lambda: " << endl;

  // Display the array of integers
  for_each(nums_in_vec.cbegin(),
          nums_in_vec.cend(),
          [](const int & element) {cout << element << ' ';});

  cout << endl;
  cout << "Display elements in a list using a lambda: " << endl;

  // Display the list of characters
  for_each(chars_in_list.cbegin(),
          chars_in_list.cend(),
          [](auto & element) {cout << element << ' ';});

  return 0;
}
