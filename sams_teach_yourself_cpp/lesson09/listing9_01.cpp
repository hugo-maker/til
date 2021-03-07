#include <iostream>
#include <string>
using namespace std;

class human
{
public:
  string name;
  int age;

  void introduce_self()
  {
    cout << "I am " + name << " and am ";
    cout << age << " years old" << endl;
  }
};

int main()
{
  // An object of class human with attribute name as "Adam"
  human first_man;
  first_man.name = "Adam";
  first_man.age = 30;

  // An object of class human with attribute name as "Eve"
  human first_woman;
  first_woman.name = "Eve";
  first_woman.age = 28;

  first_man.introduce_self();
  first_woman.introduce_self();

  return 0;
}
