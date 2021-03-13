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
  cout << endl;
}

int main()
{
  std::list<int> link_ints{4, 3, 5, -1, 2021};

  // Store an iterator obtained in using insert()
  auto val2 = link_ints.insert(link_ints.begin(), 2);

  cout << "Initial contents of the list:" << endl;
  display_contents(link_ints);

  cout << "After erasing element '" << *val2 << "':" << endl;
  link_ints.erase(val2);
  display_contents(link_ints);

  link_ints.erase(link_ints.begin(), link_ints.end());
  cout << "Number of elements after erasing range: ";
  cout << link_ints.size() << endl;

  return 0;
}
