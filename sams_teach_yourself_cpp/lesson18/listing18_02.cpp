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
  std::list<int> link_ints{-101, 42};

  link_ints.push_front(10);
  link_ints.push_front(2021);
  link_ints.push_back(-1);
  link_ints.push_back(9999);

  display_contents(link_ints);

  return 0;
}
