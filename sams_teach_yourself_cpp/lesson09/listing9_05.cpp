#include <iostream>
#include <string>
using namespace std;

class human
{
private:
  string name;
  int age;

public:
  human(string humans_name, int humans_age)
  {
    name = humans_name;
    age = humans_age;
    cout << "Overloaded constructor creates " << name;
    cout << " of age " << age << endl;
  }

  void introduce_self()
  {
    cout << "I am " + name << " and am ";
    cout << age << " years old" << endl;
  }
};

int main()
{
  human first_man("Adam", 25);
  human first_woman("Eve", 28);

  first_man.introduce_self();
  first_woman.introduce_self();

  return 0;
}
