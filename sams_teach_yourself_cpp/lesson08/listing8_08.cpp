#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "How many integers shall I reserve memory for?" << endl;
  int num_entries = 0;
  cin >> num_entries;

  int * my_numbers = new int[num_entries];

  cout << "Memory allocated at: " << my_numbers << hex << endl;

  delete[] my_numbers;

  return 0;
}
