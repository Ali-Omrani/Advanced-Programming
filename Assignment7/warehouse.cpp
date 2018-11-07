#include "warehouse.h"
using namespace std;

material::material(string _name, int _amount, int _value) : name(_name) , amount(_amount) , value(_value) {}

void material::show_material()
{
	cout << setw(20) << name << setw(30) << amount << setw(20) << value << endl;
}

bool material_comparator(const material& l, const material& r) {return l.name < r.name;}


warehouse::warehouse() {}

warehouse::warehouse(vector <shipment> _shipments) : shipments(_shipments) {}

int warehouse::get_value_of(string item_name, int item_amount)
{
	int value = 0;
	int last_price = 0;
	// this->sort_shipments();
	
	for (int i=0;i<shipments.size();i++)
	{
	
		if(shipments[i].has_item(item_name))
		{
			last_price = shipments[i].find_item(item_name).get_unit_price();
			if(shipments[i].find_item(item_name).get_amount() >= item_amount)
			{
				value += item_amount * last_price;
				item_amount = 0;
			}
			else
			{
				value += shipments[i].find_item(item_name).get_amount() * last_price;
				item_amount -= shipments[i].find_item(item_name).get_amount() ;
			}
	
		}
		else
		{
			continue;
		}
		
	}
	if (item_amount != 0)
		value += last_price * item_amount;

	return value;
}

int warehouse::available(string item_name)
{
	int result = 0; 
	for (int i=0;i<shipments.size();i++)
	{
		if (!shipments[i].has_item(item_name))
		{
			continue;
		}
		result += shipments[i].find_item(item_name).get_amount();
	}
	return result;
}
int warehouse::last_price(string item_name)
{
	int result = 0;
	bool was_found = false;
	for(int i=0;i<shipments.size();i++)
	{
		if (!shipments[i].has_item(item_name))
			continue;
		result = shipments[i].find_item(item_name).get_unit_price();	
		was_found = true;
	}
	if (was_found == false)
		throw no_price_yet_exception();
	return result;
}
int warehouse::get_value()
{
	int result = 0;
	for (int i=0;i<shipments.size();i++)
		result += shipments[i].get_value();
	return result;
}
bool warehouse::has_enough(std::string name, int amount)
{	
	int available_amount = 0;
	for (int i=0;i<shipments.size();i++)
	{
		available_amount += shipments[i].get_amount_of(name);
	}
	return available_amount >= amount;
}
void warehouse::reserve (recipe& r)
{
	vector <ingredient> ingredients = r.get_ingredients();
	for (int i=0;i<ingredients.size();i++)
	{
		if (this->has_enough(ingredients[i].name,ingredients[i].amount))
			this->take(ingredients[i].name,ingredients[i].amount);
		else
			throw insufficient_ingredient_exception();
	}
}
void warehouse::take(string item_name, int amount)
{
	sort(shipments.begin(),shipments.end(),shipment_comparator);
	for(int i=0;i<shipments.size();i++)
	{
		shipments[i].take(item_name,amount);
	}
	if (amount != 0)
		throw insufficient_ingredient_exception();
}
void warehouse::clear()
{
	shipments.clear();
}
void warehouse::print_warehouse()
{
	for (int i=1;i<=shipments.size();i++)
	{
		cout << "shipment "  << i << ":";
		shipments[i-1].print_shipment();
	}
}

void warehouse::add_shipment(shipment s)
{
	shipments.push_back(s);
}

void warehouse::show_ingredients()
{	
	bool ingredient_exists = false;
	vector <material> ingredients;
	for (int i=0;i<shipments.size();i++)
	{
		vector <item> items = shipments[i].get_items();
		for(int j=0;j<items.size();j++)
		{
			string item_name = items[j].get_name();
			int amount = items[j].get_amount();
			int value = items[j].get_unit_price() * amount;

			for (int k=0;k<ingredients.size();k++)
			{
				if (ingredients[k].name == item_name)
				{
					ingredient_exists = true;
					ingredients[k].amount += amount;
					ingredients[k].value += value;
				}
			}
			if(ingredient_exists == false)
			{
				ingredients.push_back(material(item_name,amount,value));
			}

		}

	}
	sort(ingredients.begin(),ingredients.end(),material_comparator);
	for (int i=0;i<ingredients.size();i++)
	{
		cout << i+1;
		ingredients[i].show_material();
	}	
}


bool shipment_comparator(shipment& l, shipment& r)
{
	date a = r.get_date();
	return l.get_date().is_more_recent_than(a);
}