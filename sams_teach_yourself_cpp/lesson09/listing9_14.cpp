#include <iostream>
#include <string>
using namespace std;

class human
{
private:
  friend void display_age(const human & person);
  string name;
  int age;

public:
  human(string humans_name, int humans_age)
  {
    name = humans_name;
    age = humans_age;
  }
};

void display_age(const human & person)
{
  cout << person.age << endl;
}

int main()
{
  human first_man("Adam", 25);
  cout << "Accessing private member age via friend function: ";
  display_age(first_man);

  return 0;
}
