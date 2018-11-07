#ifndef _TRANS
#define _TRANS

#include <vector>
#include <string>

class account;

class transaction
{
public:
	transaction(account* _src_account , account* _dest_account,int _amount,int _id);
	int get_id();
	int get_amount();
	account* get_dest();
	std :: string get_status();
	void increase_approved_num ();
	void decline();
	void perform_transaction();
	void update_transaction_status();
private:
	account* src_account,*dest_account;
	int id,amount,num_of_approved;
	bool decline_flag;
	std ::string status;
};
#endif