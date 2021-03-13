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

bool sort_predicate_descending(const int & lhs, const int & rhs)
{
  // define creteria for list::sort: return true for desired order
  return (lhs > rhs);
}

int main()
{
  list<int> link_ints{0, -1, 2021, 444, -5};

  cout << "Initial contents of the list are - " << endl;
  display_contents(link_ints);

  link_ints.sort();

  cout << "Order after sort():" << endl;
  display_contents(link_ints);

  link_ints.sort(sort_predicate_descending);
  cout << "Order after sort() with a predicate:" << endl;
  display_contents(link_ints);

  return 0;
}
