#include <iostream>
using namespace std;

void display_array(int numbers[], int length)
{
  for (int index = 0; index < length; ++index)
  {
    cout << numbers[index] << " ";
  }
  cout << endl;
}

void display_array(char characters[], int length)
{
  for (int index = 0; index < length; ++index)
  {
    cout << characters[index] << " ";
  }
  cout << endl;
}

int main()
{
  int my_nums[4] = {24, 58, -1, 245};
  display_array(my_nums, 4);

  char my_statement[7] = {'H', 'e', 'l', 'l', 'o', '!', '\0'};
  display_array(my_statement, 7);

  return 0;
}
