#include <iostream>
using namespace std;

class human
{
  int age;
public:
  // explicit constructor blocks implicit conversions
  explicit human(int humans_age) : age(humans_age) {}
};

void do_something(human person)
{
  cout << "human sent did something" << endl;
  return;
}

int main()
{
  human kid(10); //explicit conversion is OK
  human another_kid = human(11); // explicit, OK
  do_something(kid); // OK

  // human another_kid2 = 11; failure: implicit conversion not OK
  // do_something(10); // implicit conversion

  return 0;
}
