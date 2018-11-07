#ifndef _USER_
#define _USER_
#include <iostream>
struct reservation_item;
class user
{
public:
	user(std::string _username, std::string _password);
	void print_user();
	virtual std::string what_are_you() = 0;
	virtual void print_reservations() = 0;
	virtual void reserve(reservation_item item) = 0;
protected:
	std::string username;
	std::string password;	
};
#endif