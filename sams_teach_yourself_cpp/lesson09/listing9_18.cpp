#include <iostream>
using namespace std;

class human
{
  int age;
public:
  constexpr human(int humans_age) : age(humans_age) {}
  constexpr int get_age() const {return age;}
};

int main()
{
  constexpr human some_person(15);
  const int his_age = some_person.get_age();

  human another_person(45); // not constant expression

  return 0;
}
