#include "bank.h"
using namespace std;

int bank:: create_customer (string name,string surname)
{
	customer* new_customer= new customer(name,surname,customers.size());
	customers.push_back(new_customer);
	return customers.size();
}

void bank:: show_all_customers ()
{
	for (int i=0;i<customers.size();i++)
		customers[i]->print_customer();
}

customer* bank:: customer_finder(int id)
{
	for (int i=0;i<customers.size();i++)
	{
		if (customers[i]->get_id()==id)
			return customers[i];
	}
	return NULL;
}	

transaction* bank:: transaction_finder(int id)
{
	for (int i=0;i<transactions.size();i++)
	{
		if (transactions[i]->get_id()==id)
			return transactions[i];
	}
	return NULL;
}
account* bank:: account_finder(int id)
{	
	for (int i=0;i<accounts.size();i++)
	{
		if (accounts[i]->get_id()==id)
			{
			return accounts[i];
			}
	}
	return NULL;
}
int bank:: create_account (std::vector <int>& owners, int balance)
{
	account* new_account=new account (accounts.size(),balance);
	for (int i=0;i<owners.size();i++)
	{
		new_account->add_customer(this->customer_finder(owners[i]));
	}
	accounts.push_back(new_account);
	return accounts.size();
}

void bank:: show_all_accounts()
{
	cout << accounts.size() << endl;
	for (int i=0;i<accounts.size();i++)
		accounts[i]->print_account();
}

void bank:: add_owner (int acc_id,int owner_id)
{
	accounts[acc_id]->add_customer(this->customer_finder(owner_id));
}

int bank:: book_transaction(int src_account_id,int dest_account_id,int amount)
{
	account* src=account_finder(src_account_id);
	account* dest=account_finder(dest_account_id);
	transaction* new_trans = new transaction(src,dest,amount,transactions.size());
	transactions.push_back(new_trans);
	src->add_transaction(new_trans);
	return transactions.size();
}

void bank:: approve_transaction(int trans_id,int owner_id)
{
	transaction* trans=transaction_finder(trans_id);
	customer* owner=customer_finder(owner_id);
	owner->approve_transaction(trans);
}

void bank:: decline_transaction(int trans_id,int owner_id)
{
	transaction* trans=transaction_finder(trans_id);
	customer* owner=customer_finder(owner_id);
	owner->decline_transaction(trans);
}

void bank:: show_account (int acc_id)
{
	account* acc= account_finder(acc_id);
	acc->print_account();
}