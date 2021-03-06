#include <iostream>
using namespace std;

int main()
{
  const int ARRAY_LEN = 5;

  // Static array of 5 integers, initialized
  int my_numbers[ARRAY_LEN] = {24, -1, 365, -999, 2011};

  // Pointer initialized to first element in array
  int * points_to_nums = my_numbers;

  cout << "Display array using pointer syntax, oprator*" << endl;
  for (int index = 0; index < ARRAY_LEN; ++index)
  {
    cout << "Element " << index << " = " << *(my_numbers + index) << endl;
  }

  cout << "Display array using ptr with array syntax, oprator[]" << endl;
  for (int index = 0; index < ARRAY_LEN; ++index)
  {
    cout << "Element " << index << " = " << points_to_nums[index] << endl;
  }

  return 0;
}
