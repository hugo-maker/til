#include <queue>
#include <list>

int main()
{
  using namespace std;

  // A queue of integers
  queue<int> nums_in_q;

  // A queue of doubles
  queue<double> dbls_in_q;

  // A queue of doubles stored internally in a list
  queue<double, list<double>> dbls_in_q_in_list;

  // one queue created as a copy of another
  queue<int> copy_q(nums_in_q);

  return 0;
}
