#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char display_options()
{
  cout << "What do you wish to do?" << endl;
  cout << "Option 1: To enter an integer" << endl;
  cout << "Option 2: To query a value given an index" << endl;
  cout << "Option 3: To display the vector" << endl;
  cout << "Option 4: To find a value" << endl;
  cout << "Option 5: To quit!" << endl << "> ";

  char ch;
  cin >> ch;
  return ch;
}

int main()
{
  vector<int> integers;
  char user_select = '\0';

  while ((user_select = display_options()) != '5')
  {
    switch (user_select)
    {
      case '1':
      {
        cout << "Enter an integer: ";
        int input_integer;
        cin >> input_integer;
        integers.push_back(input_integer);

        break;
      }
      case '2':
      {
        cout << "Enter an index between 0 and ";
        cout << (integers.size() - 1) << ": ";
        size_t index = 0;
        cin >> index;

        if (index < (integers.size()))
        {
          cout << "Element[" << index << "] = " << integers[index] << endl;
        }

        break;
      }
      case '3':
      {
        cout << "The contents of the vector are: ";
        for (size_t index = 0; index < integers.size(); ++index)
        {
          cout << integers[index] << ' ';
        }
        cout << endl;

        break;
      }
      case '4':
      {
        cout << "Enter a value: ";
        int value = 0;
        cin >> value;
        auto element_found = std::find(integers.begin(), integers.end(), value);
        if (element_found != integers.end())
        {
          cout << "Element found!" << endl;
        }
        else
        {
          cout << "No such element" << endl;
        }

        break;
      }
      default:
      {
        cout << "No such options!" << endl;
        break;
      }
    }
  }

  cout << "Good bye!" << endl;
  return 0;
}
