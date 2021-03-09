#include <iostream>
using namespace std;

class fish
{
public:
  virtual void swim()
  {
    cout << "Fish swims!" << endl;
  }
};

class tuna : public fish
{
public:
  // override fish::swim
  void swim()
  {
    cout << "Tuna swims!" << endl;
  }
};

class carp : public fish
{
public:
  // override fish::swim
  void swim()
  {
    cout << "Carp swims!" << endl;
  }
};

void make_fish_swim(fish & input_fish)
{
  // calling virtual method swim()
  input_fish.swim();
}

int main()
{
  tuna my_dinner;
  carp my_lunch;

  // sending tuna as fish
  make_fish_swim(my_dinner);

  // sending carp as fish
  make_fish_swim(my_lunch);

  return 0;
}
