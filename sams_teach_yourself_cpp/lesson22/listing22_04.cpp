#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> vec_multiplicand{0, 1, 2, 3, 4};
  vector<int> vec_multiplier{100, 101, 102, 103, 104};

  // Holds the result of multiplication
  vector<int> vec_result;

  // Make space for the result of the multiplication
  vec_result.resize(vec_multiplier.size());

  transform(vec_multiplicand.begin(), // range of multiplicands
            vec_multiplicand.end(), // end of range
            vec_multiplier.begin(), // multiplier values
            vec_result.begin(), // range that holds result
            [](int a, int b) {return a * b; }); // lambda

  cout << "The contents of the first vector are: " << endl;
  for (size_t index = 0; index < vec_multiplicand.size(); ++index)
  {
    cout << vec_multiplicand[index] << ' ';
  }
  cout << endl;

  cout << "The contents of the second vector are: " << endl;
  for (size_t index = 0; index < vec_multiplier.size(); ++index)
  {
    cout << vec_multiplier[index] << ' ';
  }
  cout << endl;

  cout << "The result of the multiplication is: " << endl;
  for (size_t index = 0; index < vec_result.size(); ++index)
  {
    cout << vec_result[index] << ' ';
  }
  cout << endl;

  return 0;
}
