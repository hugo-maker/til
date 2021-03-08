#include <iostream>
using namespace std;

class fish
{
public:
  void swim()
  {
    cout << "Fish swims... !" << endl;
  }

  void swim(bool is_fresh_water_fish) // overloaded version
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
  void swim()
  {
    cout << "Tuna swims real fast" << endl;
  }
};

int main()
{
  tuna my_dinner;

  cout << "About my food" << endl;

  // my_dinner.swim(false); // failure: tuna::swim() hides fish::swim(bool)
  my_dinner.swim();

  return 0;
}
