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

class mammal : public virtual animal
{
};

class bird : public virtual animal
{
};

class reptile : public virtual animal
{
};

class platypus final : public mammal, public bird, public reptile
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

  // no compile failure as there is only one animal::age
  duck_billed_p.age = 25;

  return 0;
}
