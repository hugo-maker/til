#include <iostream>
#include <string>
using namespace std;

class human
{
private:
  friend class utility;
  string name;
  int age;

public:
  human(string humans_name, int humans_age)
  {
    name = humans_name;
    age = humans_age;
  }
};

class utility
{
public:
  static void display_age(const human & person)
  {
    cout << person.age << endl;
  }
};

int main()
{
  human first_man("Adam", 25);
  cout << "Accesssing private memeber age via freind class: ";
  utility::display_age(first_man);

  return 0;
}
