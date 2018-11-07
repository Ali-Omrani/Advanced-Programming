#ifndef _SHIPMENT_
#define _SHIPMENT_
#include <vector>
#include "item.h"
#include "date.h"
class shipment
{
public:
	shipment(date& _arrival_date, std::vector <item> _items);	
	// int get_value_of(std::string item_name, int& item_amount);
	void take (std::string item_name, int& amount);
	bool has_item(std::string item_name); 
	int get_amount_of(std::string name);
	date get_date();
	int get_value();  
	item find_item(std::string item_name);
	std::vector <item> get_items();
	void print_shipment();
private:
	date arrival_date;
	std::vector<item> items;
	//item / item* ??
};
#endif
 