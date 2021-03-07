#include <iostream>
using namespace std;

class human
{
private:
  // Private member data;
  int age;

public:
  void set_age(int input_age)
  {
    age = input_age;
  }

  // human lies about his / her age (if over 30)
  int get_age()
  {
    if (age > 30)
    {
      return (age - 2);
    }
    else
    {
      return age;
    }
  }
};

int main()
{
  human first_man;
  first_man.set_age(35);

  human first_woman;
  first_woman.set_age(22);

  cout << "Age of first_man "  << first_man.get_age() << endl;
  cout << "Age of first_woman "  << first_woman.get_age() << endl;
}
