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

class car: private motor // private inheritance
{
public:
  void move()
  {
    switch_ignition();
    pump_fuel();
    fire_cylinders();
  }
};

int main()
{
  car my_dream_car;
  my_dream_car.move();

  return 0;
}
