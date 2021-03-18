#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

struct human
{
  human() {};
  human(const char * in_name, int in_age, const char * in_dob) : age(in_age)
  {
    strcpy(name, in_name);
    strcpy(dob, in_dob);
  }

  char name[30];
  int age;
  char dob[20];
};

int main()
{
  human input("Siddhartha Rao", 101, "May 1916");

  ofstream fs_out("my_binary.bin", ios_base::out | ios_base::binary);

  if (fs_out.is_open())
  {
    cout << "Writing one object of human to a binary file" << endl;
    fs_out.write(reinterpret_cast<const char *>(&input), sizeof(input));
    fs_out.close();
  }

  ifstream fs_in("my_binary.bin", ios_base::in | ios_base::binary);

  if (fs_in.is_open())
  {
    human some_person;
    fs_in.read((char *)&some_person, sizeof(some_person));

    cout << "Reading information from binary file: " << endl;
    cout << "Name = " << some_person.name << endl;
    cout << "Age = " << some_person.age << endl;
    cout << "Date of Birth = " << some_person.dob << endl;
  }

  return 0;
}
