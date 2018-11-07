#ifndef _WAREHOUSE_
#define _WAREHOUSE_
#include "shipment.h"
#include "exception.h"
#include "recipe.h"
#include <algorithm>
#include <iomanip>
struct material
{
	material(std::string _name, int _amount, int _value);
	
	void show_material();
	std::string name;
	int amount;
	int value;
};
bool material_comparator(const material& l, const material& r);
class warehouse
{
public:
	warehouse();
	warehouse(std::vector <shipment> _shipments);
	int get_value_of(std::string item_name, int item_amount);
	int available(std::string item_name);
	int last_price(std::string item_name);
	int get_value();
	bool has_enough(std::string name, int amount);
	void take(std::string item_name, int amount);
	void reserve (recipe& r);
	void clear();
	void show_ingredients();
	void print_warehouse();
	void add_shipment(shipment s);
private:
	std::vector <shipment> shipments;
};

bool shipment_comparator(shipment& l, shipment& r);
#endif
// can be singleton