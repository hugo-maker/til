#include <iostream>
using namespace std;

class date
{
  int day, month, year;

public:
  date(int in_month, int in_day, int in_year)
    : month(in_month), day(in_day), year(in_year) {}

  void operator += (int days_to_add) // addition assignment
  {
    day += days_to_add;
  }

  void operator -= (int days_to_sub) // subtraction assignment
  {
    day -= days_to_sub;
  }

  void display_date()
  {
    cout << month << " / " << day << " / " << year << endl;
  }
};

int main()
{
  date holiday(12, 25, 2016);
  cout << "holiday on: ";
  holiday.display_date();

  cout << "holiday -= 19 gives: ";
  holiday -= 19;
  holiday.display_date();

  cout << "holiday += 25 gives: ";
  holiday += 25;
  holiday.display_date();

  return 0;
}
