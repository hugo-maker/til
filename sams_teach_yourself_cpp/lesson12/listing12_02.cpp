#include <iostream>
#include <sstream> // new include for ostringstream
#include <string>
using namespace std;

class date
{
private:
  int day, month, year;
  string date_in_string;

public:
  date(int in_month, int in_day, int in_year)
    : month(in_month), day(in_day), year(in_year) {}

  operator const char * ()
  {
    ostringstream formatted_date; // assists string construction
    formatted_date << month << " / " << day << " / " << year;

    date_in_string = formatted_date.str();
    return date_in_string.c_str();
  }
};

int main()
{
  date holiday (12, 25, 2016);

  cout << "Holiday is on: " << holiday << endl;

  // string str_holiday(holiday); // OK!
  // str_holiday = date(11, 11, 2016); // also OK!

  return 0;
}
