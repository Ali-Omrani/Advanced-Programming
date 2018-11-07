#ifndef _MENU_
#define _MENU_
#include <vector>
#include <iostream>
struct menu_item
{
	menu_item(std::string day, std::string name, int p);
	std::string day_in_week;
	std::string food_name;

	int price;
};
class menu
{
public:
	menu();
	menu(std::vector <menu_item> _items);
	void print_menu();
	bool has_item(std::string day, std::string name);
	std::vector<menu_item> get_items();
	menu& operator=(const menu& m);
private:
	std::vector <menu_item> items;
};
#endif 