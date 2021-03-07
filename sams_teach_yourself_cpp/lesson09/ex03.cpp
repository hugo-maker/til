#include <iostream>
#include <string>
using namespace std;

class human
{
private:
  int age;
  string name;

public:
  human(const int humans_age, const string humans_name)
    : age(humans_age), name(humans_name) {}

  int get_age()
  {
    return age;
  }

  string get_name()
  {
    return name;
  }
};

int main()
{
  human first_man(10, "Adam");
  cout << "first_man: " << first_man.get_name() << " is " \
    << first_man.get_age() << " years old." << endl;
}
