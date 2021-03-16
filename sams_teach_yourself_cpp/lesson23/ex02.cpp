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
  vector<int> vec_ints{1, -1, 2, 100, 3};
  list<int> list_ints(5);

  copy(vec_ints.cbegin(), vec_ints.cbegin() + 3, list_ints.begin());

  cout << "Display vec_ints contents: ";
  display_contents(vec_ints);
  cout << "Display list_ints contents: ";
  display_contents(list_ints);

  return 0;
}
