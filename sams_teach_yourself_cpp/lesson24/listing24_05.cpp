#include <queue>
#include <functional>

int main()
{
  using namespace std;

  priority_queue<int> nums_in_prio_q;

  priority_queue<double> dbls_in_prio_q;

  priority_queue<int, deque<int>, greater<int>> nums_in_descending_q;

  priority_queue<int> copy_q(nums_in_prio_q);

  return 0;
}
