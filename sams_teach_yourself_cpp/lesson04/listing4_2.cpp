#include <iostream>
using namespace std;
constexpr int square(int number) {return number * number;}

int main()
{
  const int ARRAY_LENGTH = 5;

  // Array of 5 integers, initialized using a const
  int my_numbers[ARRAY_LENGTH] = {5, 10, 0, -101, 20};

  // Using a constexpr for array of 25 integers
  int more_numbers[square(ARRAY_LENGTH)];

  cout << "Enter index of the element to be changed: ";
  int element_index = 0;
  cin >> element_index;

  cout << "Enter new value: ";
  int new_value = 0;
  cin >> new_value;

  my_numbers[element_index] = new_value;
  more_numbers[element_index] = new_value;

  cout << "Element " << element_index << " in array my_numbers is: ";
  cout << my_numbers[element_index] << endl;

  cout << "Element " << element_index << " in array more_numbers is: ";
  cout << more_numbers[element_index] << endl;

  return 0;
}
