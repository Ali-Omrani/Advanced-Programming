#include "admin.h"
using namespace std;
admin::admin() : user("admin","password") {}
admin::admin(string _username, string _password) : user(_username,_password) {}

string admin::what_are_you() { return "admin"; }
void admin::reserve(reservation_item item)
{
	cout << "admin!!" << endl;
}

void admin::print_admin()
{
	cout << "username: " << username << "      password: " << password << endl;
}

void admin::print_reservations()
{
	cout << "admin cant reserve!" << endl;	
}