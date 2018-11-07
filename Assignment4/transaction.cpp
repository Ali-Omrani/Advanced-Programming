#include "transaction.h"
#include "account.h"

using namespace std;
transaction :: transaction (account* _src_account , account* _dest_account,int _amount,int _id)
{
	id = _id;
	amount=_amount;
	src_account=_src_account;
	dest_account= _dest_account;
	status="pending";
	num_of_approved=0;
	decline_flag=false;
}

void transaction :: increase_approved_num ()
{
	num_of_approved++;
	update_transaction_status();
	perform_transaction();
}

void transaction:: update_transaction_status()
{
	if (num_of_approved >= src_account->num_of_owners()-1)
		{
		status = "accepted";
		}
	else if (decline_flag==true)
		status = "rejcted";
	else 
		status = "pending";
}

void transaction:: perform_transaction()
{
	if (status=="accepted")
	{
		if (src_account->get_balance()<amount)
			{
			status="rejected";
			return;
			}
		else
		{
			src_account->set_balance(src_account->get_balance()-amount);
			dest_account->set_balance(dest_account->get_balance()+amount);
		}
	}

}

void transaction:: decline()
{
	decline_flag=true;
}

int transaction :: get_id()
{
	return id;
}

string transaction:: get_status()
{
	return status;
}
int  transaction:: get_amount()
{
	return amount;
}

account* transaction:: get_dest()
{
	return dest_account;
}