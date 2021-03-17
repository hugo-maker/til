#include <queue>
#include <functional>
#include <iostream>

int main()
{
  using namespace std;

  priority_queue<int, vector<int>, greater<int>> nums_in_prio_q;

  cout << "Inserting {10, 5, -1, 20} into the priority queue" << endl;
  nums_in_prio_q.push(10);
  nums_in_prio_q.push(5);
  nums_in_prio_q.push(-1);
  nums_in_prio_q.push(20);

  cout << "Deleting the " << nums_in_prio_q.size() << " elements" << endl;
  while (!nums_in_prio_q.empty())
  {
    cout << "Deleting topmost element: " << nums_in_prio_q.top() << endl;
    nums_in_prio_q.pop();
  }

  return 0;
}
