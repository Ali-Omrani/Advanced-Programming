#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include "server.h"
#include "item.h"
#include "user.h"
#include "admin.h"
#include "prof.h"
#include "recipe.h"
#include "menu.h"
using namespace std;

int main()
{
	server s;
	s.initialize_warehouse();
	cout << "---------------show_warehouse-----------------" << endl;
	s.show_warehouse();
	cout << "---------------initialize_recipes-------------------" << endl;
	s.initialize_recipes();
	cout << "-----------------show_profs-------------------" << endl;
	s.initialize_users();
	s.show_profs();
	cout << "------------------show_admin------------------"<< endl;
	s.show_admin();
	cout << "----------------show_ingredients----------------"<< endl;
	s.show_ingredients();
	cout << "---------------------show_recipes---------------------" << endl;
	s.show_recipes();
	cout << "---------------------estimate--------------------------" << endl;
	s.estimate(100,"chicken kebab");
	cout << "-----------------------------------------------" << endl;
	
	string command;
	bool confirmed = false;
	bool reservation_available = false;
	bool server_is_free = true;
	while (cin >> command)
	{
		try
		{
			s.parser(command,confirmed,reservation_available,server_is_free);
		}
		catch (no_user_is_loged_in_exception ex)
		{
			cout << "No one is usig the system!\n" <<"Please login first!" ;
			s.write_log("no_user_is_loged_in_exception was caught");
		}
		catch(access_denied_exception e)
		{
			cout << "you cannot use command: " << command << "\n Access Denied! \n";
			s.write_log("access_denied_exception was caught");	
		}
		catch(busy_server_exception exe)
		{
			cout << "Server is busy at the moment!" << endl;
			s.write_log("access_denied_exception was caught");
		}
		catch(insufficient_ingredient_exception exep)
		{
			cout << "sorry we are out of necessary ingredients!\n";
			s.write_log("insufficient_ingredient_exception was caught");

		}
		catch(not_in_menu_exception excep)
		{
			cout << "your choice was not in the menu!\n";
			s.write_log("not_in_menu_exception was caught");
		}
		catch(class reservation_available_exception except)
		{
			cout << "reservation is closed!" << endl;
			s.write_log("reservation is closed!\n");
		}
	}
	
}
// reserve ride --- to menu nabashe / hishki login nakarde bashe
// 3 bar passe ghalat accounto block kon ----------------------------->moshkel with timer -- the code is almost complete
// output format of menu
// randome tekrari refrence;
// sort shipments
// age mojood nabood
// shipment nabayad get_value_of kone :|
// sort ti show_ingredients server
// har khari natoone get_password seda kone bara prof
