#include "user.h"
using namespace std;

user::user(string _username, string _password) : username(_username) , password(_password) {}

void user::print_user()
{
	cout << "user: " << username << "    password: " << password << endl;
}