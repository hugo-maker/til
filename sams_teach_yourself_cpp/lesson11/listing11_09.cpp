#include <iostream>
using namespace std;

class fish
{
public:
  virtual fish * clone() = 0;
  virtual void swim() = 0;
  virtual ~fish() {};
};

class tuna : public fish
{
public:
  fish * clone() override
  {
    return new tuna(*this);
  }
  void swim() override final
  {
    cout << "Tuna swims fast in the sea" << endl;
  }
};

class blue_fin_tuna final : public tuna
{
public:
  fish * clone() override
  {
    return new blue_fin_tuna(*this);
  }

  // Cannot override tuna::swim as it is "final" in tuna
};

class carp final : public fish
{
  fish * clone() override
  {
    return new carp(*this);
  }
  void swim() override final
  {
    cout << "Carp swims slow in the lake" << endl;
  }
};

int main()
{
  const int ARRAY_SIZE = 4;

  fish * my_fishes[ARRAY_SIZE] = {NULL};
  my_fishes[0] = new tuna();
  my_fishes[1] = new carp();
  my_fishes[2] = new blue_fin_tuna();
  my_fishes[3] = new carp();

  fish * my_new_fishes[ARRAY_SIZE];
  for (int index = 0; index < ARRAY_SIZE; ++index)
  {
    my_new_fishes[index] = my_fishes[index]->clone();
  }

  // invoke a virtual method to check
  for (int index = 0; index < ARRAY_SIZE; ++index)
  {
    my_new_fishes[index]->swim();
  }

  // memory cleanup
  for (int index = 0; index < ARRAY_SIZE; ++index)
  {
    delete my_fishes[index];
    delete my_new_fishes[index];
  }

  return 0;
}
