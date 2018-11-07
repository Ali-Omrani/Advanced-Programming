#ifndef _ACCOUNT
#define _ACCOUNT
#include "transaction.h"
#include "customer.h"
#include <vector>
#include <iostream>
class account
{
public:
	account(int _id,int _balance);
	void add_transaction (transaction* trans);
	int num_of_owners();
	int get_balance();
	int get_id();
	void set_balance(int new_balance);
	void add_customer(customer* new_customer);
	void print_account();
private:
	int id;
	std::vector <customer*> owners;
	std:: vector <transaction*> transactions;
	int balance;
};

#endif