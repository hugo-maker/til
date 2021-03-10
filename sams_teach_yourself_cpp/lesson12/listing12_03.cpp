#include <iostream>
#include <memory> // new include to use unique_ptr
using namespace std;

class date
{
private:
  int day, month, year;

public:
  date(int in_month, int in_day, int in_year)
    : month(in_month), day(in_day), year(in_year) {}

  void display_date()
  {
    cout << month << " / " << day << " / " << year << endl;
  }
};

int main()
{
  unique_ptr<int> smart_int_ptr(new int);
  *smart_int_ptr = 42;

  // Use smart pointer type like an int *
  cout << "Integer value is: " << *smart_int_ptr << endl;

  unique_ptr<date> smart_holiday(new date(12, 25, 2016));
  cout << "The new instance of date contains: ";

  // Use smart_holiday just as you would a date
  smart_holiday->display_date();

  return 0;
}
