#include "date.h"
using namespace std;

date::date(int _day, int _month, int _year) : day(_day) , month(_month) , year(_year) {}

bool date::is_more_recent_than(date& d)
{
	if (year < d.year)
		return true;
	else if(year > d.year)
		return false;
	else
	{
		if (month < d.month)
			return true;
		else if (month > d.month)
			return false;
		else
		{
			if(day >= d.day)
				return false;
			else 
				return true;
		}
	}
}

void date::print_date()
{
	cout << year << "/" << month << "/" << day << endl;
}