#include <iostream>
using namespace std;

class fish
{
public:
  bool is_fresh_water_fish;

  void swim()
  {
    if (is_fresh_water_fish)
    {
      cout << "Swims in lake" << endl;
    }
    else
    {
      cout << "Swims in sea" << endl;
    }
  }
};

class tuna: public fish
{
public:
  tuna()
  {
    is_fresh_water_fish = false;
  }
};

class carp: public fish
{
public:
  carp()
  {
    is_fresh_water_fish = true;
  }
};

int main()
{
  carp my_lunch;
  tuna my_dinner;

  cout << "About my food:" << endl;

  cout << "Lunch: ";
  my_lunch.swim();

  cout << "Dinner: ";
  my_dinner.swim();

  return 0;
}
