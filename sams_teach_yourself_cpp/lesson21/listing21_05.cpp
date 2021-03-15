#include <vector>
#include <iostream>
#include <algorithm>

template <typename element_type>
class multiply
{
public:
  element_type operator () (const element_type & elem1,
                            const element_type & elem2)
  {
    return (elem1 * elem2);
  }
};

int main()
{
  using namespace std;

  vector<int> multiplicands{0, 1, 2, 3, 4};
  vector<int> multipliers{100, 101, 102, 103, 104};

  // A third container that holds the result of multiplication
  vector<int> vec_result;

  // make space for the result of the multiplication
  vec_result.resize(multipliers.size());
  transform(multiplicands.begin(), // range of the multiplicands
            multiplicands.end(), // end of range
            multipliers.begin(), // multiplier value
            vec_result.begin(), // holds result
            multiply<int> ()); // multiplies

  cout << "The contents of the first vector are: " << endl;
  for (size_t index = 0; index < multiplicands.size(); ++index)
  {
    cout << multiplicands[index] << ' ';
  }
  cout << endl;

  cout << "The contents of the second vector are: " << endl;
  for (size_t index = 0; index < multipliers.size(); ++index)
  {
    cout << multipliers[index] << ' ';
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

