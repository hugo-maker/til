#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <functional>
using namespace std;

int main()
{
  string str("THIS is a TEst string!");
  cout << "The sample stirng is: " << str << endl;

  string str_lower_case_copy;
  str_lower_case_copy.resize(str.size());

  transform(str.cbegin(), // start source range
            str.cend(), // end source range
            str_lower_case_copy.begin(), // start dest range
            ::tolower); // unary function

  cout << "Result of 'transform' on the string with 'tolower': " << endl;
  cout << "\"" << str_lower_case_copy << "\"" << endl << endl;

  // Two sample vectors of integers...
  vector<int> nums_in_vec1{2021, 0, -1, 42, 10101, 25};
  vector<int> nums_in_vec2(nums_in_vec1.size(), -1);

  // A destination range for holding the result of addition
  deque<int> sum_in_deque(nums_in_vec1.size());

  transform(nums_in_vec1.cbegin(),
            nums_in_vec1.cend(),
            nums_in_vec2.cbegin(),
            sum_in_deque.begin(),
            plus<int>());

  cout << "Result of 'transform' using binary function 'plus': " << endl;
  cout << "Index Vector1 + Vector2 = Result (in Deque)" << endl;
  for (size_t index = 0; index < nums_in_vec1.size(); ++index)
  {
    cout << index << "\t " << nums_in_vec1[index] << "\t+ ";
    cout << nums_in_vec2[index] << "\t = ";
    cout << sum_in_deque[index] << endl;
  }

  return 0;
}
