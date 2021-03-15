#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

// A structure as a unary predicate
template <typename number_type>
struct is_multiple
{
  number_type Divisor;

  is_multiple(const number_type & divisor)
  {
    Divisor = divisor;
  }

  bool operator () (const number_type & element) const
  {
    // Check if the divisor is a multiple of the divisor
    return ((element % Divisor) == 0);
  }
};

int main()
{
  vector<int> nums_in_vec{25, 26, 27, 28, 29, 30, 31};
  cout << "The vector contains: 25, 26, 27, 28, 29 , 30, 31" << endl;

  cout << "Enter divisor (> 0): ";
  int divisor = 2;
  cin >> divisor;

  // find the first element that is a multiple of divisor
  auto element = find_if(nums_in_vec.begin(),
      nums_in_vec.end(), is_multiple<int>(divisor));

  if (element != nums_in_vec.end())
  {
    cout << "First element in vector divisible by " << divisor;
    cout << ": " << *element << endl;
  }

  return 0;
}
