#include <iostream>
using namespace std;

class fish
{
private:
  bool is_fresh_water_fish;

public:
  // fish constructor
  fish(bool is_fresh_water) : is_fresh_water_fish(is_fresh_water) {}

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
  tuna() : fish(false) {}

  void swim()
  {
    cout << "Tuna swims real fast" << endl;
  }
};

class carp: public fish
{
public:
  carp() : fish(true) {}

  void swim()
  {
    cout << "Carp swims real slow" << endl;
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
