#include <iostream>
using namespace std;

class fish
{
public:
  fish()
  {
    cout << "Constructed fish" << endl;
  }
  virtual ~fish() // virtual destructor
  {
    cout << "Destroyed fish" << endl;
  }
};

class tuna : public fish
{
public:
  tuna()
  {
    cout << "Constructed tuna" << endl;
  }
  ~tuna()
  {
    cout << "Destroyed tuna" << endl;
  }
};

void delete_fish_memory(fish * p_fish)
{
  delete p_fish;
}

int main()
{
  cout << "Allocating a tuna on the free store:" << endl;
  tuna * p_tuna = new tuna;
  cout << "Deleting the tuna: " << endl;
  delete_fish_memory(p_tuna);

  cout << "Instantiating a tuna on the stack:" << endl;
  tuna my_dinner;
  cout << "Automatic destruction as it goes out of scope: " << endl;
}
