#ifndef _DATE_
#define _DATE_
#include <iostream>
class date
{
public:
	date(int _day, int _month, int _year);
	void print_date();
	bool is_more_recent_than(date& d);
private:
	int day,month,year;
};
#endif