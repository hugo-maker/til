#include <iostream>
using namespace std;

class animal
{
public:
  animal()
  {
    cout << "animal constructor" << endl;
  }

  // sample member
  int age;
};

class mammal : public animal
{
};

class bird : public animal
{
};

class reptile : public animal
{
};

class platypus : public mammal, public bird, public reptile
{
public:
  platypus()
  {
    cout << "platypus constructor" << endl;
  }
};

int main()
{
  platypus duck_billed_p;

  // uncomment next line to see compile failure
  // age is mabiguous as there are three instances of base animal
  // duck_billed_p.age = 25;

  return 0;
}
