#include <list>
#include <iostream>
#include <string>
#include <algorithm>
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
  std::list<string> str_list{"Jonathan", "Joseph", "Jotaro", "Josuke",
    "Giorno", "Jolyne", "Johnny", "Joestar"};

  cout << "list before sorting: ";
  display_contents(str_list);

  str_list.sort();
  cout << "list after sorting: ";
  display_contents(str_list);

  str_list.reverse();
  cout << "list after reverse: ";
  display_contents(str_list);

  return 0;
}
