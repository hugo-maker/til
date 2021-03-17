#include <stack>
#include <iostream>

int main()
{
  using namespace std;
  stack<int> nums_in_stack;

  // push: insert values at top of the stack
  cout << "Pushing {25, 10, -1, 5} on stack in that order:" << endl;
  nums_in_stack.push(25);
  nums_in_stack.push(10);
  nums_in_stack.push(-1);
  nums_in_stack.push(5);

  cout << "Stack contains " << nums_in_stack.size() << " elements" << endl;
  while (nums_in_stack.size() != 0)
  {
    cout << "Popping topmost element: " << nums_in_stack.top() << endl;
    nums_in_stack.pop();
  }

  if (nums_in_stack.empty())
  {
    cout << "Popping all elements empties stack!" << endl;
  }

  return 0;
}
