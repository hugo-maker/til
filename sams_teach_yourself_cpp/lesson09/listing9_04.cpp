#include <iostream>
#include <string>
using namespace std;

class human
{
private:
  string name;
  int age;

public:
  human() // default constructor
  {
    age = 0; // initialized to ensure no junk value
    cout << "Default constructor: name and age not set" << endl;
  }

  human(string humans_name, int humans_age) // overloaded
  {
    name = humans_name;
    age = humans_age;
    cout << "Overloaded constructor creates ";
    cout << name << " of " << age << " years" << endl;
  }
};

int main()
{
  human first_man; // use default constructor
  human first_woman("Eve", 20); // use overloaded constructor

  return 0;
}
