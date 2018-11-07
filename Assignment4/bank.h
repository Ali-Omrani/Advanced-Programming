#ifndef _BANK
#define _BANK

#include <vector>
#include <string>
#include "customer.h"
#include "account.h"
#include "transaction.h"
class bank
{
public:
	int create_customer (std::string name, std::string surname);
	int create_account (std::vector <int>& owners, int balance);
	int book_transaction (int src_account, int dest_account, int amount);
	void approve_transaction(int trans_id,int owner_id);
	void decline_transaction(int trans_id,int owner_id);
	customer* customer_finder(int id);
	transaction* transaction_finder(int id);
	account* account_finder(int id);
	void add_owner (int acc_id,int owner_id);
	void show_account (int acc_id);
	void show_all_customers ();
	void show_all_accounts();
private:
	std::vector <customer*> customers;
	std::vector <account*> accounts;
	std::vector <transaction*> transactions;
};

#endif