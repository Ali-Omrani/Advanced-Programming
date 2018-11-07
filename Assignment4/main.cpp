#include <iostream>
#include <vector>
#include <string>
#include "customer.h"
#include "account.h"
#include "bank.h"
#include "transaction.h"
using namespace std;

int main()
{
  bank my_bank;
  string input;
  int last_customer_id=-1;
  int last_account_id=-1;
  while (cin >> input)
  {
  		if (input=="create_customer")
  		{
  			string name,surname;
  			cin >> name >> surname;
  			// cout << input << endl << "name:" << name << endl << "surname:" << surname<< endl;
  			my_bank.create_customer(name,surname);
  			last_customer_id++;
  			// my_bank.show_all_customers();
  		}
  		else if (input=="create_account")
  		{
        
  			vector <int> owners_id;
  			char temp=cin.get();
  			int owner_id;
  			int balance;
  			while (temp!='\n'  )
  			{
  				cin.putback(temp);
  				cin >> owner_id;
  				owners_id.push_back(owner_id);
  				temp=cin.get();
  			}
        balance = owners_id [owners_id.size()-1];
  			owners_id.pop_back();
        my_bank.create_account(owners_id,balance);
        last_account_id++;
      
      // cout << "------------create-----------" << endl;
      //   my_bank.show_all_accounts();
      // cout << "-----------------------" << endl;
 
  		
      }
  		else if (input=="add_owner")
  		{
  			int account_id,owner_id;
  			cin >> account_id >> owner_id;
        my_bank.add_owner(account_id,owner_id);
  		 // cout << "-----------add------------" << endl;
     //    my_bank.show_all_accounts();
     //  cout << "-----------------------" << endl;
 
      }
  		else if (input=="book_transaction")
  		{
  			int src_account_id,dest_account_id, amount;
  			cin >> src_account_id >> dest_account_id >> amount ;
  			// cout << input << endl << "src:" << src_account_id << endl << "dest:" << dest_account_id << "amount:" << amount << endl;
  		  my_bank.book_transaction(src_account_id,dest_account_id,amount);
      }
  		else if (input=="approve_transaction")
  		{
  			int transaction_id,owner_id;
  			cin >> transaction_id >> owner_id;
  			// cout << "-id" <<transaction_id << endl << "owner_id:" << owner_id << endl;
  		  my_bank.approve_transaction(transaction_id,owner_id);
      }
  		else if (input=="decline_transaction")
  		{
  			int transaction_id,owner_id;
  			cin >> transaction_id >> owner_id;
  			// cout << "t-id" <<transaction_id << endl << "owner_id:" << owner_id << endl;
  		  my_bank.decline_transaction(transaction_id,owner_id);
      }
  		else if (input=="show_account")
  		{
  			int account_id;
  			cin >> account_id;
        my_bank.show_account(account_id);
  		}
      else {
        cout << "command not found" << endl;
      }
  }
  // cout<< endl << "finder:" << my_bank.customer_finder(0)->get_name()<< endl;
  // my_bank.show_all_accounts();
}