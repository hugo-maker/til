#include <algorithm>
#include <list>
#include <string>
#include <iostream>
using namespace std;

template <typename t>
void display_contents(const t & container)
{
  for (auto element = container.cbegin();
      element != container.cend();
      ++element)
  {
    cout << *element << endl;
  }
}

int main()
{
  list<string> names{"John", "Brad", "jack", "sean", "Anna"};

  cout << "Sorted contents of the list are: " << endl;
  names.sort();
  display_contents(names);

  cout << "Lowest index where \"Brad\" can be inserted is: ";
  auto min_pos = lower_bound(names.begin(), names.end(), "Brad");
  cout << distance(names.begin(), min_pos) << endl;

  cout << "The highest index where \"Brad\" can be inserted is: ";
  auto max_pos = upper_bound(names.begin(), names.end(), "Brad");
  cout << distance(names.begin(), max_pos);

  cout << endl;

  cout << "List after inserting Brad in sorted order: " << endl;
  names.insert(min_pos, "Brad");
  display_contents(names);

  return 0;
}
