#include <iostream>
using namespace std;

int main()
{
  const int INT_NUMS = 5;
  int my_ints[INT_NUMS] = {1, 2, 3, 4, 5};
  for (int iterator = INT_NUMS - 1; iterator >= 0; --iterator)
  {
    cout << "Integer[" << iterator << "] = " << my_ints[iterator] << endl;
  }

  return 0;
}
