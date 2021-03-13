#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

char display_options()
{
  cout << "What do you wish to do?" << endl;
  cout << "Option 1: To enter length & breadth" << endl;
  cout << "Option 2: To query a value given an index" << endl;
  cout << "Option 3: To display dimensions of all packages " << endl;
  cout << "Option 4: To quit!" << endl << "> ";

  char ch;
  cin >> ch;
  return ch;
}

class dimensions
{
  int length, breadth;
  string str_out;

public:
  dimensions(int input_l, int input_b)
    : length(input_l), breadth(input_b) {}

  operator const char * ()
  {
    stringstream os;
    os << "Length "s << length << ", Breadth: "s << breadth << endl;
    str_out = os.str();
    return str_out.c_str();
  }
};

int main()
{
  vector<dimensions> vec_data;

  char user_select = '\0';
  while ((user_select = display_options()) != '4')
  {
    switch (user_select)
    {
      case '1':
      {
        cout << "Enter length and breadth";
        int length = 0, breadth = 0;;
        cin >> length;
        cin >> breadth;

        vec_data.push_back(dimensions(length, breadth));

        break;
      }
      case '2':
      {
        cout << "Enter an index between 0 and ";
        cout << (vec_data.size() - 1) << ": ";
        size_t index = 0;
        cin >> index;

        if (index < (vec_data.size()))
        {
          cout << "Element[" << index << "] = " << vec_data[index] << endl;
        }

        break;
      }
      case '3':
      {
        cout << "The contents of the vector are: ";
        for (size_t index = 0; index < vec_data.size(); ++index)
        {
          cout << vec_data[index] << ' ';
        }
        cout << endl;

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
