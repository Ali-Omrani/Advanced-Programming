#ifndef _SERVER_
#define _SERVER_
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <iomanip>
#include "timer.h"
#include "menu.h"
#include "user.h"
#include "admin.h"
#include "prof.h"
#include "warehouse.h"
#include "shipment.h"
#include "recipe.h"
#include "item.h"
#include "date.h"
#include "exception.h"
class server
{
public:

	server();
	
	void write_log(std::string mylog);
	void login(std::string username, std::string password);
	void parser(std::string command, bool& confirmed, bool& reservation_available, bool& server_is_free);
	void estimate(int num, std::string recipe_name);
	void add_shipment(std::vector <item> items);
	void create_menu(std::vector <menu_item> items);
	void reserve(reservation_item item);
	void initialize_users();
	void initialize_warehouse();
	void initialize_recipes();
	void show_ingredients();
	void show_warehouse();
	void show_recipes();
	void admin_show_reservations();
	void prof_show_reservations();
	void print_recipes();
	void show_profs();
	void show_admin();
	void finilize();
private:
	warehouse system_warehouse;
	std::vector <recipe> recipes;
	std::vector <prof> profs;
	admin system_admin;
	menu system_menu;
	user* loged_in_user;
	std::ofstream system_log;

};
bool recipes_comparator(recipe& l, recipe& r);
// must be singleton
#endif 