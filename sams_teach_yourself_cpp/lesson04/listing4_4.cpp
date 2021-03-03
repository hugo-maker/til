#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> dynamic_array(3);

  dynamic_array[0] = 365;
  dynamic_array[1] = -421;
  dynamic_array[2] = 789;

  cout << "Number of integers in array: " << dynamic_array.size() << endl;

  cout << "Enter another element to insert" << endl;
  int new_value = 0;
  cin >> new_value;
  dynamic_array.push_back(new_value);

  cout << "Number of integers in array: " << dynamic_array.size() << endl;

  cout << "Last element in array: ";
  cout << dynamic_array[dynamic_array.size() - 1] << endl;
  return 0;
}
