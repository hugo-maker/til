#include <forward_list>
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
  forward_list<int> flist_integers{3, 4, 2, 2, 0};
  flist_integers.push_front(1);

  cout << "Contents of forward_list: " << endl;
  display_contents(flist_integers);

  flist_integers.remove(2);
  flist_integers.sort();
  cout << "Contents after removing 2 and sorting: " << endl;
  display_contents(flist_integers);

  return 0;
}
