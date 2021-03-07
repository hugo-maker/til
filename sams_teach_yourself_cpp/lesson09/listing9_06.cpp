#include <iostream>
#include <string>
using namespace std;

class human
{
private:
  int age;
  string name;

public:
  human(string humans_name = "Adam", int humans_age = 25)
    :name(humans_name), age(humans_age)
  {
    cout << "Constructed a human called " << name;
    cout << ", " << age << " years old" << endl;
  }
};

int main()
{
  human adam;
  human eve("Eve", 18);

  return 0;
}
