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
  list<int> link_ints1;

  // Inserting elements at the beginning...
  link_ints1.insert(link_ints1.begin(), 2);
  link_ints1.insert(link_ints1.begin(), 1);

  // Inserting an element at the end...
  link_ints1.insert(link_ints1.end(), 3);

  cout << "The contents of list 1 after inserting elements:" << endl;
  display_contents(link_ints1);

  list<int> link_ints2;

  // Inserting 4 elements of the same value 0...
  link_ints2.insert(link_ints2.begin(), 4, 0);

  cout << "The contents of list 2 after inserting elements:" << endl;
  display_contents(link_ints2);

  list<int> link_ints3;

  // Inserting elements from another list at the beginning...
  link_ints3.insert(link_ints3.begin(), link_ints1.begin(), link_ints1.end());

  cout << "The contents of list 2 after inserting the contents of list 1 at the beginning:" << endl;
  display_contents(link_ints3);

  // Inserting elements from another list at the end...
  link_ints3.insert(link_ints3.end(), link_ints2.begin(), link_ints2.end());

  cout << "The contents of list 2 after inserting the contents of list 2 at the end:" << endl;
  display_contents(link_ints3);

  return 0;
}
