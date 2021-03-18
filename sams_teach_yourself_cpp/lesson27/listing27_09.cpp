#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
  ifstream my_file;
  my_file.open("hello_file.txt", ios_base::in);

  if (my_file.is_open())
  {
    cout << "File open successful. It contains: " << endl;
    string file_contents;

    while (my_file.good())
    {
      getline(my_file, file_contents);
      cout << file_contents << endl;
    }

    cout << "Finished reading file, will close now" << endl;
    my_file.close();
  }
  else
  {
    cout << "open() failed: check if file is in right folder" << endl;
  }

  return 0;
}
