#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

template <typename t>
void display_contents(const t & container)
{
  for (auto element = container.cbegin();
      element != container.cend();
      ++element)
  {
    cout << *element << ' ';
  }

  cout << "| Number of elements: " << container.size() << endl;
}

int main()
{
  list<int> nums_in_list{2021, 0, -1, 42, 10101, 25};

  cout << "Source (list) contains: " << endl;
  display_contents(nums_in_list);

  // Initialize vector to hold 2x elements as the list
  vector<int> nums_in_vec(nums_in_list.size() * 2);

  auto last_element = copy(nums_in_list.cbegin(),
                          nums_in_list.cend(),
                          nums_in_vec.begin());

  // copy odd numbers from list into vector
  copy_if (nums_in_list.cbegin(), nums_in_list.cend(),
      last_element, [](int element) {return ((element % 2) != 0); } );

  cout << "Destination (vector) after copy and copy_if: " << endl;
  display_contents(nums_in_vec);

  // Remove all instances of '0', resize vector using erase()
  auto new_end = remove(nums_in_vec.begin(), nums_in_vec.end(), 0);
  nums_in_vec.erase(new_end, nums_in_vec.end());

  // Remove all odd numbers from the vector using remove_if
  new_end = remove_if(nums_in_vec.begin(), nums_in_vec.end(),
      [](int element) {return ((element % 2) != 0); } );
  nums_in_vec.erase(new_end, nums_in_vec.end()); // resizing

  cout << "Destination (vector) after remove, remove_if, erase: " << endl;
  display_contents(nums_in_vec);

  return 0;
}
