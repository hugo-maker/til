#include <iostream>
using namespace std;

class fish
{
public:
  virtual void swim()
  {
    cout << "Fish swims in water" << endl;
  }

  // base class should always have virtual destructor
  virtual ~fish() {}
};

class tuna : public fish
{
public:
  void swim()
  {
    cout << "Tuna swims real fast in the sea" << endl;
  }

  void become_dinner()
  {
    cout << "Tuna became dinner in Sushi" << endl;
  }
};

class carp : public fish
{
public:
  void swim()
  {
    cout << "Carp swims real slow in the lake" << endl;
  }

  void talk()
  {
    cout << "Carp talked Carp!" << endl;
  }
};

void detect_fish_type(fish * obj_fish)
{
  tuna * obj_tuna = dynamic_cast <tuna *>(obj_fish);
  if (obj_tuna)
  {
    cout << "Detected tuna. Making tuna dinner: " << endl;
    obj_tuna->become_dinner();
  }

  carp * obj_carp = dynamic_cast <carp *>(obj_fish);
  if (obj_carp)
  {
    cout << "Detected carp. Making carp talk: " << endl;
    obj_carp->talk();
  }

  cout << "Verifying type using virtual fish::swim: " << endl;
  obj_fish->swim(); // calling virtual finction swim
}

int main()
{
  carp my_lunch;
  tuna my_dinner;

  detect_fish_type(&my_dinner);
  cout << endl;
  detect_fish_type(&my_lunch);

  return 0;
}
