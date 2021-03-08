#include <iostream>
using namespace std;

class motor
{
public:
  void switch_ignition()
  {
    cout << "Ignition ON" << endl;
  }
  void pump_fuel()
  {
    cout << "Fuel in cylinders" << endl;
  }
  void fire_cylinders()
  {
    cout << "Vroooom" << endl;
  }
};

class car: protected motor
{
public:
  void move()
  {
    switch_ignition();
    pump_fuel();
    fire_cylinders();
  }
};

class race_car: protected car
{
public:
  void move()
  {
    switch_ignition();
    pump_fuel();
    fire_cylinders();
    fire_cylinders();
    fire_cylinders();
  }
};

int main()
{
  race_car my_dream_car;
  my_dream_car.move();

  return 0;
}
