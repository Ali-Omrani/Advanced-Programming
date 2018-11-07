#include "menu.h"
using namespace std;

menu_item::menu_item(string day, string name, int p) : day_in_week(day) , food_name(name) , price(p) {}

menu::menu() {}
menu::menu(vector <menu_item> _items) : items(_items) {}

void menu::print_menu()
{
	string days[5]={"SAT","SUN","MON","TUE","WED"};
	bool has_sth = false;
	for(int j=0;j<5;j++)
	{
		cout << days[j] << endl;
		for (int i=0;i<items.size();i++)
		{
			if (items[i].day_in_week == days[j])
			{
				cout << "-" << items[i].food_name << " (" << items[i].price << ")" << endl;
				has_sth = true;
			}
		}
		if(!has_sth)
			cout << "-\n";
		has_sth = false;
	}
}


bool menu::has_item(std::string day, std::string name)
{
	for (int i=0;i<items.size();i++)
	{
		if(items[i].food_name == name && items[i].day_in_week == day)
			return true;
	}
	return false;
}


vector<menu_item> menu::get_items()
{
	return items;
}
menu& menu::operator=(const menu& m)
{
    if (this == &m)
        return *this;
        
   	items.clear();
    items = m.items;    
    return *this;
}
