#include <iostream>
using namespace std;

class fish
{
public:
  // define a pure virtual function swim
  virtual void swim() = 0;
};

class tuna : public fish
{
public:
  void swim()
  {
    cout << "Tuna swims fast in the sea!" << endl;
  }
};

class carp : public fish
{
  void swim()
  {
    cout << "Carp swims slow in the lake!" << endl;
  }
};

void make_fish_swim(fish & input_fish)
{
  input_fish.swim();
}

int main()
{
  // fish my_fish; // Fails, cannnot instantiate an ABC
  carp my_lunch;
  tuna my_dinner;

  make_fish_swim(my_lunch);
  make_fish_swim(my_dinner);

  return 0;
}
