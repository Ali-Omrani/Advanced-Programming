#include "shipment.h"
using namespace std;

shipment::shipment(date& _arrival_date, vector <item> _items) : arrival_date(_arrival_date) , items(_items) {}

bool shipment::has_item(string item_name)
{
	for (int i=0;i<items.size();i++)
	{
		if (items[i].get_name()== item_name)
			return true;
	}
	return false;
}

date shipment::get_date() {return arrival_date;}

item shipment::find_item(string item_name)
{
	for (int i=0;i<items.size();i++)
	{
		if (items[i].get_name() == item_name)
			return items[i];
	}	
}
int shipment::get_amount_of(std::string name)
{
	for (int i=0;i<items.size();i++)
	{
		if(items[i].get_name() == name)
			return items[i].get_amount();
	}
}
int shipment::get_value()
{
	int result =0;
	for (int i=0;i<items.size();i++)
		result+=items[i].get_amount() * items[i].get_unit_price();
	return result;
}
void shipment::take (std::string item_name, int& amount)
{
	for (int i=0;i<items.size();i++)
	{
		if (items[i].get_name() == item_name)
		{
			if (items[i].get_amount() >= amount)
			{
				items[i].set_amount(items[i].get_amount()-amount);
				amount=0;
			}
			else 
			{
				amount-=items[i].get_amount();
				items[i].set_amount(0);
			}
		}
	}
}
// int shipment::get_value_of(std::string item_name, int& item_amount)
// {
// 	int value;
// 	int last_price;
// 	for (int i=0;i<items.size();i++)
// 	{
// 		if(items[i].get_name() == item_name)
// 		{
// 			if(items[i].get_amount >= item_amount)
// 			{
// 				last_price = items[i].get_unit_price();
// 				items[i].set_amount(items[i].get_amount-item_amount);
// 				value += item[i].get_unit_price()*item_amount;
// 				item_amount=0;
// 			}
// 			else
// 			{
// 				last_price = items[i].get_unit_price();
// 				item_amount-=items[i].get_amount();
// 				value += item[i].get_unit_price()*items[i].get_amount();
// 				items[i].set_amount(0);
// 			}
// 		}
// 	}
// 	return value;
// }
vector <item> shipment::get_items() {return items;}

void shipment::print_shipment()
{
	cout << "date: " ;
	arrival_date.print_date();
	for (int i=1; i<=items.size();i++)
	{
		cout << "item " << i << ":" ;
		items[i-1].print_item();
	}
}