#include <queue>
#include <iostream>

int main()
{
  using namespace std;
  queue<int> nums_in_q;

  cout << "Inserting {10, 5, -1, 20} into queue" << endl;
  nums_in_q.push(10);
  nums_in_q.push(5);
  nums_in_q.push(-1);
  nums_in_q.push(20);

  cout << "Queue contains " << nums_in_q.size() << " elements" << endl;
  cout << "Element at front: " << nums_in_q.front() << endl;
  cout << "Element at back: " << nums_in_q.back() << endl;

  while (nums_in_q.size() != 0)
  {
    cout << "Deleting element: " << nums_in_q.front() << endl;
    nums_in_q.pop();
  }

  if (nums_in_q.empty())
  {
    cout << "The queue is now empty!" << endl;
  }

  return 0;
}
