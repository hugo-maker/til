#include <iostream>
using namespace std;

class fish
{
public:
  void swim()
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

void make_fish_swim(fish & input_fish)
{
  // calling fish::swim
  input_fish.swim();
}

int main()
{
  tuna my_dinner;

  // calling tuna::swim
  my_dinner.swim();

  // sending tuna as fish
  make_fish_swim(my_dinner);

  return 0;
}
