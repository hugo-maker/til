#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

bool is_even(const int & num) // unary predicate
{
  return ((num % 2) == 0);
}

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
  vector<int> nums_in_vec{2021, 0, -1, 42, 10101, 25};

  cout << "The initial contents: " << endl;
  display_contents(nums_in_vec);

  vector<int> vec_copy(nums_in_vec);

  cout << "The effect of using partition(): " << endl;
  partition(nums_in_vec.begin(), nums_in_vec.end(), is_even);
  display_contents(nums_in_vec);

  cout << "The effect of using stable_partition(): " << endl;
  stable_partition(vec_copy.begin(), vec_copy.end(), is_even);
  display_contents(vec_copy);

  return 0;
}
