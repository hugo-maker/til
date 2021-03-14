#include <set>
#include <iostream>
#include <string>
using namespace std;

template <typename t>
void display_contents(const t & container)
{
  for (auto i_element = container.cbegin();
      i_element != container.cend();
      ++i_element)
  {
    cout << *i_element << ' ';
  }
  cout << endl;
}


int main()
{
 set<int> set_ints{1, 17, 3, 7, 5};
 multiset<int> mset_ints{1, -2, 26, 14, 8};

 cout << "Before inserting, set_ints contains: ";
 display_contents(set_ints);
 cout << "Before inserting, mset_ints contains: ";
 display_contents(mset_ints);

 set_ints.insert(1);
 mset_ints.insert(1);
 cout << "After inserting, set_ints contains: ";
 display_contents(set_ints);
 cout << "After inserting, mset_ints contains: ";
 display_contents(mset_ints);

 return 0;
}
