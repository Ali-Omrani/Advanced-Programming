#include "account.h"
using namespace std;
void account:: add_customer(customer* new_customer)
{
	owners.push_back(new_customer);
}

void account:: set_balance(int new_balance)
{
	balance = new_balance;
}

account:: account(int _id,int _balance)
{
	id = _id;
	balance =_balance;
}


void account:: print_account()
{
	cout << "Balance : " << balance << endl;
	cout << "Owners : " ;
	for (int i=0;i<owners.size();i++)
	{
		cout << owners[i]->get_name() << " " << owners[i]->get_surname();
		if (i!=owners.size()-1)
			cout << ",";
	}
	cout << endl;
	cout << "Transactions : " << endl;
	for (int j=0;j<transactions.size();j++)
	{
		cout << "[" << transactions[j]->get_id() << "] " << transactions[j]->get_amount() << " to  " << (transactions[j]->get_dest())->get_id() << " -> " << transactions[j]->get_status();  
		cout << endl;
	}
}

int account:: num_of_owners()
{
	return owners.size();
}

int account:: get_balance()
{
	return balance;
}

void account:: add_transaction (transaction* trans)
{
	transactions.push_back(trans);
}

int account:: get_id()
{
	return id;
}