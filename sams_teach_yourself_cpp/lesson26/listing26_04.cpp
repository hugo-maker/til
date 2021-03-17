#include <iostream>
#include <memory>
using namespace std;

class fish
{
public:
  fish() {cout << "fish: constructed!" << endl;}
  ~fish() {cout << "fish: destructed!" << endl;}

  void swim() const {cout << "fish swims in water" << endl;}
};

void make_fish_swim(const unique_ptr<fish> & in_fish)
{
  in_fish->swim();
}

int main()
{
  unique_ptr<fish> smart_fish(new fish);

  smart_fish->swim();
  make_fish_swim(smart_fish);

  unique_ptr<fish> copy_smart_fish;
  // copy_smart_fish = smart_fish; // error: operator = is private

  return 0;
}
