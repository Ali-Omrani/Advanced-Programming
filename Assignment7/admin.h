#ifndef _ADMIN_
#define _ADMIN_
#include "user.h"
#include "prof.h"
class admin : public user
{
public:
	admin();
	admin(std::string _username, std::string _password);
	std::string what_are_you();
	void reserve(reservation_item item);
	void show_ingredients();
	void show_recepies();
	void estimate();
	void shipment();
	void menu();
	void confirm_menu();
	void show_reservations();
	void finialize_reservations();
	void print_admin();
	void print_reservations();

};
#endif