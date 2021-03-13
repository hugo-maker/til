#include <deque>
#include <iostream>
#include <algorithm>

int main()
{
  using namespace std;

  // Define a deque of integers
  deque<int> int_deque;

  // Insert integers at the bottom of the array
  int_deque.push_back(3);
  int_deque.push_back(4);
  int_deque.push_back(5);

  // Insert integers at the top of the array
  int_deque.push_front(2);
  int_deque.push_front(1);
  int_deque.push_front(0);

  cout << "The contents of the deque after inserting elements ";
  cout << "at the top and bottom are:" << endl;

  // display contents on the screen
  for (size_t count = 0;
      count < int_deque.size();
      ++count)
  {
    cout << "Element[" << count << "] = ";
    cout << int_deque[count] << endl;
  }

  cout << endl;

  // Erase an element at the top
  int_deque.pop_front();

  // Erase an element at the bottom
  int_deque.pop_back();

  cout << "The contents of the deque after erasing an element ";
  cout << "from the top and bottom are:" << endl;

  // Display contents again: this time using iterator
  // if on older compilers, remove auto and uncomment next line
  // deque<int>::iterator. element;
  for (auto element = int_deque.begin();
      element != int_deque.end();
      ++element)
  {
    size_t offset = distance(int_deque.begin(), element);
    cout << "Element[" << offset << "] = " << *element << endl;
  }

  return 0;
}
