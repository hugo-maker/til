#include <iostream>
using namespace std;

int main()
{
  cout << "How many integers you wish to enter? ";
  int num_entries = 0;
  cin >> num_entries;

  int * points_to_ints = new int[num_entries];

  cout << "Allocated for " << num_entries << " integers" << endl;
  for (int counter = 0; counter < num_entries; ++counter)
  {
    cout << "Enter number " << counter << ": ";
    cin >> *(points_to_ints + counter);
  }

  cout << "Displaying all numbers entered: " << endl;
  for (int counter = 0; counter < num_entries; ++counter)
  {
    cout << *(points_to_ints++) << " ";
  }

  cout << endl;

  // return pointer to initial position
  points_to_ints -= num_entries;

  delete[] points_to_ints;

  return 0;
}
