#include "customer.h"
using namespace std;

customer:: customer (string _name, string _surname,int _id)
{
	name=_name;
	surname=_surname;
	id = _id;
}

void customer:: print_customer()
{
	cout << id <<": " << name << "  " << surname << endl;
}

int customer:: get_id()
{
	return id;
}

string customer:: get_name()
{
	return name;
}

string customer:: get_surname()
{
	return surname;
}

void customer:: approve_transaction (transaction* trans)
{
	trans-> increase_approved_num ();
	
}

void customer:: decline_transaction (transaction* trans)
{
	trans-> decline();
}