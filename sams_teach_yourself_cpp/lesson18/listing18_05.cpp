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
  std::list<int> link_ints{0, 1, 2, 3, 4, 5};

  cout << "Initial contents of list:" << endl;
  display_contents(link_ints);

  link_ints.reverse();
  cout << "Contents of list after using reverse():" << endl;
  display_contents(link_ints);

  return 0;
}
