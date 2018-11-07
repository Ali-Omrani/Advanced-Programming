#include "prof.h"
using namespace std;

reservation_item::reservation_item(string day, string name) : day_in_week(day) , food_name(name) 
{
	srand (time(0));
	refrence = rand();
}


prof::prof(string _username, string _password) : user(_username,_password) , failed_attempt_num(0) , blocked (false) {}
int prof::get_failed_attempt_num(){return failed_attempt_num;}

void prof::toggle_blocked_status()
{
	blocked = !blocked;
}
bool prof::is_blocked()
{
	return blocked;
}
void prof::start_timer()
{
	t = time(NULL);
}

int prof::time_passed()
{
	time_t now = time(NULL);
	return (now-t);
}
void prof::set_failed_attempt_num (int val)
{
	failed_attempt_num = val;
}

void prof::print_prof()
{
	cout << "username: " << username << "       password: " << password << endl;
}

void prof::reserve(reservation_item item)
{
	reserved_items.push_back(item);
	cout << "refrence: " << item.refrence << endl; 
}

void prof::print_reservations()
{
	for (int i=0;i< reserved_items.size();i++)
		cout << reserved_items[i].refrence << setw(25) <<reserved_items[i].day_in_week << setw(25) << reserved_items[i].food_name << endl ;
}

string prof::get_username() {return username;}
string prof::get_password() {return password;}

string prof::what_are_you() {return "prof";}


void prof::print_reservation_by_day(string day)
{
	for (int i=0;i<reserved_items.size();i++)
	{
		if(reserved_items[i].day_in_week == day)
		{
			cout <<setw(20)<< username << setw(30) << reserved_items[i].food_name << setw(30) << day << endl;
		}
	}
}

bool prof::has_reserved(string day, string name)
{
	
	for (int i=0;i<reserved_items.size();i++)
	{

		if (reserved_items[i].day_in_week == day && reserved_items[i].food_name == name)
		{
			return true;
		}
	}
	return false;
}



