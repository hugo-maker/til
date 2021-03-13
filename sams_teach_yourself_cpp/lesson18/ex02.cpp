#include <list>
#include <iostream>
using namespace std;

int main()
{
  std::list<int> num_list{1, 2, 3};
  auto iterator = num_list.begin();
  cout << "Before inserting, iterator points to: " << *iterator << endl;

  num_list.push_front(0);
  cout << "After inserting, iterator points to: " << *iterator << endl;

  return 0;
}
