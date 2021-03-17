#include <stack>
#include <vector>

int main()
{
  using namespace std;

  // A stack of integers
  stack<int> nums_in_stack;

  // A stack of doubles
  stack<double> dbls_in_stack;

  // A stack of doubles contained in a vector
  stack<double, vector<double>> doubles_stacked_in_vec;

  // initializing one stack to be a copy of another
  stack<int> unms_in_stack_copy(nums_in_stack);

  return 0;
}
