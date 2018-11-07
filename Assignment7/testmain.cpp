#include <iostream>
#include <vector>
#include "warehouse.h"
#include "shipment.h"
#include "item.h"
#include "date.h"
using namespace std;

int main()
{
	vector <item> items1;
	vector <item> items2;
	date d1(20,1,1375);
	date d2(10,2,1380);
	item first("rice",10000,1200);
	item second("meat",1000,34000);
	item third("adas",500,450);
	item forth("coke",3,2300);
	items2.push_back(third);
	items2.push_back(forth);
	items1.push_back(first);
	items1.push_back(second);
	shipment s1(d1,items1);
	shipment s2(d2,items2);
	s1.print_shipment();
	s2.print_shipment();
	vector <shipment> shipments;
	shipments.push_back(s1);
	shipments.push_back(s2);
	warehouse w(shipments);
	cout << "----------------------------------------------------" << endl;
	w.print_warehouse();
}
// testin items