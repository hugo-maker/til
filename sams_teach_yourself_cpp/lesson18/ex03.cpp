#include <list>
#include <iostream>
#include <vector>
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
  cout << endl;
}

int main()
{
  std::list<int> list;
  std::vector<int> vector{1, 2, 3, 4, 5};

  list.insert(list.begin(), vector.begin(), vector.begin() + 3);

  cout << "Here is your list: ";
  display_contents(list);

  return 0;
}
