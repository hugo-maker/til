#include <string>
#include <iostream>
#include <algorithm>

int main()
{
  using namespace std;

  string sample_str("Hello String! We will reverse you!");
  cout << "The original sample string is: " << endl;
  cout << sample_str << endl << endl;

  reverse(sample_str.begin(), sample_str.end());

  cout << "After applying the std::reverse alogorithm: " << endl;
  cout << sample_str << endl;

  return 0;
}
