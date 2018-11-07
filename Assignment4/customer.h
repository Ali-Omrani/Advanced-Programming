#ifndef _CUSTOMER
#define _CUSTOMER

#include <iostream>
#include <string>
#include <vector>
#include "transaction.h"

class customer
{
public:
	customer(std::string _name, std::string _surname,int _id);
	void print_customer ();
	void approve_transaction (transaction* trans);
	void decline_transaction (transaction* trans);
	int get_id();
	std :: string get_name();
	std :: string get_surname();
private:
	std::string name,surname;
	int id;
	static int last_id;
	// vector <account*> accounts;

};




#endif