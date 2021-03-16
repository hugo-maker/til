#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int> nums_in_vec{25, 26, 27, 28, 29, 30, 31};
  cout << "The vector contatins: {25, 26, 27, 28, 29, 30, 31}";

  cout << endl << "Enter divisor (> 0): ";
  int divisor = 2;
  cin >> divisor;

  // Find the first element that is a multiple of divisor
  auto element = find_if(nums_in_vec.begin(),
                    nums_in_vec.end(),
                    [divisor](int dividend) {return (dividend % divisor) == 0;} );

  if (element != nums_in_vec.end())
  {
    cout << "First element in vector divisible by " << divisor;
    cout << ": " << *element << endl;
  }

  return 0;
}
