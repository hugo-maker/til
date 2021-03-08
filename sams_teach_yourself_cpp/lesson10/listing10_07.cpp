#include <iostream>
using namespace std;

class fish_dummy_member
{
public:
  fish_dummy_member()
  {
    cout << "fish_dummy_member constructor" << endl;
  }

  ~fish_dummy_member()
  {
    cout << "fish_dummy_member destructor" << endl;
  }
};

class fish
{
protected:
  fish_dummy_member dummy;

public:
  // fish coonstructor
  fish()
  {
    cout << "Fish constructor" << endl;
  }

  ~fish()
  {
    cout << "Fish destructor" << endl;
  }
};

class tuna_dummy_member
{
public:
  tuna_dummy_member()
  {
    cout << "tuna_dummy_member constructor" << endl;
  }

  ~tuna_dummy_member()
  {
    cout << "tuna_dummy_member destructor" << endl;
  }
};

class tuna: public fish
{
private:
  tuna_dummy_member dummy;

public:
  tuna()
  {
    cout << "tuna constructor" << endl;
  }
  ~tuna()
  {
    cout << "tuna destructor" << endl;
  }
};

int main()
{
  tuna my_dinner;

  return 0;
}
