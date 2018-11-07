#include "item.h"
using namespace std;

item::item(string _name, int _amount, int _unit_price) : name(_name) , unit_price(_unit_price) , amount(_amount) {}
string item::get_name() {return name;}
int item::get_amount() {return amount;}
int item::get_unit_price() {return unit_price;}
void item::set_amount(int val) {amount = val;}
void item::print_item()
{
	cout << "name: " << name << "    amount: " << amount << "    unit_price: " << unit_price << endl;
}