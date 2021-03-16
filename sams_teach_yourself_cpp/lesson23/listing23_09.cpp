#include <algorithm>
#include <vector>
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
  vector<int> nums_in_vec(6);

  // fill first 3 elements with value 8, last 3 with 5
  fill(nums_in_vec.begin(), nums_in_vec.begin() + 3, 8);
  fill_n(nums_in_vec.begin() + 3, 3, 5);

  // shuffle the container
  random_shuffle(nums_in_vec.begin(), nums_in_vec.end());

  cout << "The initial contents of vector: " << endl;
  display_contents(nums_in_vec);

  cout << endl << "'std::replace' value 5 by 8" << endl;
  replace(nums_in_vec.begin(), nums_in_vec.end(), 5, 8);

  cout << "'std::replace_if' even values by -1" << endl;
  replace_if(nums_in_vec.begin(), nums_in_vec.end(),
      [](int element) {return ((element % 2) == 0); }, -1 );

  cout << endl << "Vector after replacements: " << endl;
  display_contents(nums_in_vec);

  return 0;
}

