#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<bool> bool_flags(3);
  bool_flags[0] = true;
  bool_flags[1] = true;
  bool_flags[2] = false;

  bool_flags.push_back(true);

  cout << "The contents of the vector are: " << endl;
  for (size_t index = 0; index < bool_flags.size(); ++index)
  {
    cout << bool_flags[index] << ' ';
  }

  cout << endl;
  bool_flags.flip();

  cout << "The contents of the vector are: " << endl;
  for (size_t index = 0; index < bool_flags.size(); ++index)
  {
    cout << bool_flags[index] << ' ';
  }

  cout << endl;

  return 0;
}
