#include <iostream>
using namespace std;

class date
{
  int day, month, year;

public:
  date(int in_month, int in_day, int in_year)
    : month(in_month), day(in_day), year(in_year) {}

  date operator + (int days_to_add) // binary addition
  {
    date new_date(month, day + days_to_add, year);
    return new_date;
  }

  date operator - (int days_to_sub) // binary subtraction
  {
    return date(month, day - days_to_sub, year);
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

  date previous_holiday(holiday - 19);
  cout << "Previous holiday on: ";
  previous_holiday.display_date();

  date next_holiday(holiday + 6);
  cout << "Next holiday on: ";
  next_holiday.display_date();

  return 0;
}
