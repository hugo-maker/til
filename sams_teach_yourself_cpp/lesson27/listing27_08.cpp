#include <fstream>
#include <iostream>
using namespace std;

int main()
{
  ofstream my_file;
  my_file.open("hello_file.txt", ios_base::out);

  if (my_file.is_open())
  {
    cout << "File open successful" << endl;

    my_file << "My first text file!" << endl;
    my_file << "Hello file!";

    cout << "Finished writing to file, will close now" << endl;
    my_file.close();
  }

  return 0;
}
