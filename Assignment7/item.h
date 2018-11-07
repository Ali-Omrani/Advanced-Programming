#ifndef _ITEM_
#define _ITEM_
#include <iostream>
class item 
{
public:
	item(std::string _name, int _amount, int _unit_price);
	std::string get_name();
	void set_amount(int val);
	int get_amount();
	int get_unit_price();
	void print_item();
private:
	std::string name;
	int unit_price;
	int amount;	
	
};
#endif