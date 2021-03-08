#include <iostream>
using namespace std;

class mammal
{
public:
  void feed_baby_milk()
  {
    cout << "Mammal: Baby says glug!" << endl;
  }
};

class reptile
{
public:
  void spit_venom()
  {
    cout << "Reptile: Shoo enemy! Spits venom!" << endl;
  }
};

class bird
{
public:
  void lay_eggs()
  {
    cout << "Bird: Laid my eggs, am lighter now!" << endl;
  }
};

class platypus: public mammal, public bird, public reptile
{
public:
  void swim()
  {
    cout << "Platypus: Voila, I can swim!" << endl;
  }
};

int main()
{
  platypus real_freak;
  real_freak.lay_eggs();
  real_freak.feed_baby_milk();
  real_freak.spit_venom();
  real_freak.swim();

  return 0;
}
