#include "server.h"
using namespace std;

server::server()
{
	user* loged_in_user = NULL;
	system_log.open("log.txt");
	system_log.close();
}

void server::initialize_users()
{
	ifstream in ("users.txt");
	string user;
	while (in >> user)
	{
		user = user.substr(0,user.size()-1);
		
		string pass;
		in >>  pass;
		
		profs.push_back(prof(user,pass));	
		
	}	
}
void server::write_log(string mylog)
{
	system_log.open("log.txt",ios::app);
	system_log << mylog << endl;
	system_log.close();
}

void server::parser(std::string command, bool& confirmed, bool& reservation_available, bool& server_is_free)
{
	system_log.open("log.txt",ios::app);
	system_log << "command: "<<command << "     " << endl;
	if(command == "login")
	{	
		if (!server_is_free)
			{
				throw busy_server_exception();
				
				system_log <<"failed to login --"<< " busy_server_exception" << endl;

			}
		try
		{

			string username,password;
			cin >> username >> password;
			system_log << "   username: " << username << "   password: " << password << endl ;
			this->login(username,password);	
			system_log << "successful login attemp" << endl;
			server_is_free = false;	
		}
		catch(wrong_password_exception ex)
		{
			cout << "Wrong password!" << endl;
			system_log << "wrong_password_exception was caught" << endl;
		}
		catch(user_not_found_exception ex)
		{
			cout << "username was not found!" << endl;
			system_log << "user_not_found_exception was caught" << endl;
		}
		catch(blocked_user_exception e)
		{
			cout << "user is blocked" << endl;
			system_log << "blocked_user_exception was caught" << endl;
		}
	}
	else if (command == "logout")
	{
		cout << "Goodbye " << loged_in_user->what_are_you() << endl;
		system_log << "successful logout " << endl;
		server_is_free = true;
		loged_in_user = NULL;

	}
	else if (command == "shipment")
	{
		if (loged_in_user == NULL)
			throw no_user_is_loged_in_exception();
		else if (loged_in_user->what_are_you() == "prof")
			throw access_denied_exception();
		else
		{
			string line;
			string item_string;
			getline (cin,line);
			stringstream mystream (line);
			bool is_first = true;
			vector <item> items;
			while(getline(mystream,item_string,']'))
			{			
						
				stringstream items_stream (item_string);
				string item_name;
				string item_amount;
				string item_unit_price;

				if (is_first)
				{
					items_stream >> item_name ;
					item_name = item_name.substr(1,item_name.size()-2);
					system_log << "item name : " << item_name << endl;

					is_first = false;
				}
				else
				{
					items_stream >> item_name >> item_name;
					item_name = item_name.substr(1,item_name.size()-2);
					system_log << "item name : " << item_name << endl;
				}
				items_stream >> item_amount;
				item_amount = item_amount.substr(0,item_amount.size()-1);
				system_log << "item amount : " << item_amount << endl;

				items_stream >> item_unit_price;
				// item_unit_price = item_unit_price.substr()
				system_log<<"unit price : " << item_unit_price << endl;

				items.push_back(item(item_name,stoi(item_amount),stoi(item_unit_price)));
			}
			this->add_shipment(items);
			system_log << "shipment was added successfuly" << endl;
		}	
	}
	else if (command == "menu")
	{
		bool is_repeated = false;
		if (loged_in_user == NULL)
			throw no_user_is_loged_in_exception();
		else if(loged_in_user->what_are_you() == "prof")
			throw access_denied_exception();
		else
		{	
			if (!confirmed)
			{
				string line;
				string item_string;
				getline (cin,line);
				vector <menu_item> menu_items;
				if (line == " -repeat")
				{
					menu_items = system_menu.get_items();
					is_repeated = true;
				}
				stringstream mystream (line);
				bool is_first = true;
				if (!is_repeated)
				{
					while(getline(mystream,item_string,']'))
					{			
						
						stringstream items_stream (item_string);
						string day;
						string name;
						string price;

						if (is_first)
						{
							items_stream >> day ;
							day = day.substr(1,day.size()-2);
							system_log << "day : " << day << endl;
							is_first = false;
						}
						else
						{
							items_stream >> day >> day ;
							day = day.substr(1,day.size()-2);
							system_log << "day : " << day << endl;
						}
						getline(items_stream,name,',');
						name = name.substr(1,name.size());
						system_log << "name : " << name << endl;

						items_stream >> price;
						// item_unit_price = item_unit_price.substr()
						system_log<<"price : " << price << endl;

						menu_items.push_back(menu_item(day,name,stoi(price)));
					}
				
				}
				this->create_menu(menu_items);
				system_log << "menu was created successfuly" << endl;
			}
			else
			{
				cout << "the menu is closed no change is possible!" << endl;
				system_log << "the menu is closed no change is possible!" << endl;
			}
		}
	}
	else if (command == "confirm")
	{
		if (loged_in_user == NULL)
			throw no_user_is_loged_in_exception();
		else if (loged_in_user->what_are_you() == "prof")
			throw access_denied_exception();
		else
		{
			if (confirmed)
			{
				cout << "already confirmed!" << endl;
				system_log << "already confirmed!" << endl;
			}
			confirmed = true;
			reservation_available = true;
		}
	}	
	else if (command == "finalize")
	{
		if (loged_in_user == NULL)
			throw no_user_is_loged_in_exception();
		else if (loged_in_user->what_are_you() == "prof")
			throw access_denied_exception();
		else
		{
			cin >> command;
			system_log << " " << command << endl;
			if(command == "reservations")
			{
				if (!reservation_available)
				{
					cout << "reservations was closed already!" << endl;
					system_log << "reservations was closed already!" << endl;
				}
				reservation_available = false;
				confirmed = false;
				this->finilize();
				system_log << "successfuly finilized reservations" << endl;
			}
		}
	}
	else if(command == "reserve")
	{
		if (loged_in_user == NULL)
			throw no_user_is_loged_in_exception();
		if (loged_in_user->what_are_you() ==  "admin")
			throw access_denied_exception();
		if (reservation_available)
		{

				string day;
				cin >> day;
				system_log << " day: " << day ;
				string food_name;
				getline (cin,food_name);
				food_name = food_name.substr(1,food_name.size());
				system_log << " food name: " << food_name << endl;
				reservation_item temp(day,food_name);
				this->reserve(temp);
				system_log <<"successfuly reserved!" << endl;
				
		}
		else if (!reservation_available)
		{
			throw reservation_available_exception();
		}
	}
	else if(command == "show")
	{
		if (loged_in_user == NULL)
			throw no_user_is_loged_in_exception();
		cin >> command;
		system_log << " " << command << endl;
		if (command == "ingredients")
		{
			if (loged_in_user->what_are_you() ==  "prof")
				throw access_denied_exception();
			else 
			{
				this->show_ingredients();
				system_log << "successfuly printed ingredients" << endl;
			}
		}
		else if(command == "recipes")
		{
			if (loged_in_user->what_are_you() ==  "prof")
				throw access_denied_exception();
			else 
			{
				this->show_recipes();
				system_log << "successfuly printed recipes" << endl;	
			}	
		}
		else if(command == "reservations")
		{
			if (loged_in_user->what_are_you() ==  "admin")
			{
				this->admin_show_reservations();
				system_log << "successfuly printed reservations -----admin------" << endl;
			}
			else if(loged_in_user->what_are_you() ==  "prof")
			{
				this->prof_show_reservations();
				system_log << "successfuly printed reservations -----prof------" << endl;	
			}
		}
		else if(command == "menu")
		{
			if (loged_in_user->what_are_you() ==  "admin")
				throw access_denied_exception();
			else if (loged_in_user->what_are_you() ==  "prof")
			{
				system_menu.print_menu();
				system_log << "successfuly printed menu" << endl;
			}
		}
	}
	else if (command == "estimate")
	{
		if (loged_in_user == NULL)
			throw no_user_is_loged_in_exception();
		else if (loged_in_user->what_are_you() == "prof")
			throw access_denied_exception();
		else
		{
			int num;
			cin >> num;
			string food_name;
			getline(cin,food_name);
			food_name = food_name.substr(1,food_name.size());
			system_log << "food name: " << food_name << "   number: " << num << endl;
			this->estimate(num,food_name);
			system_log << "successfuly estimated" << endl;
		}

	}
	system_log.close();
}

void server::login(string username, string password)
{
	bool username_exists = false;
	if (username == "admin")
	{
		username_exists = true;
		if ( password == "password")
		{	
			loged_in_user = &system_admin;
			cout << "welcome admin" << endl;
		}
		else 
			throw wrong_password_exception();
	}
	else
	{
		for (int i=0;i<profs.size();i++)
		{
			if (profs[i].get_username() == username)
			{
				username_exists = true;
				// cout <<"blocked duration :" <<profs[i].get_timer().elapsed_time() << endl;
				if (profs[i].is_blocked() && profs[i].time_passed()>=120)
				{
					profs[i].toggle_blocked_status();
				}
				cout << "time passed: "<<profs[i].time_passed()<< endl;
				if (!profs[i].is_blocked())
				{
					if(profs[i].get_password() == password)
						{
							
							loged_in_user = &profs[i];
							cout << "welcome " << username << endl;
						}
					else
					{
						profs[i].set_failed_attempt_num(profs[i].get_failed_attempt_num()+1);

						if(profs[i].get_failed_attempt_num() >=3)
						{
							cout << "your account will be blocked for 2 mins!";
							profs[i].set_failed_attempt_num(0);
							profs[i].start_timer();
							profs[i].toggle_blocked_status();
						}
						throw wrong_password_exception();
					}

				}
				else 
					throw blocked_user_exception();
			}

		
		}
		if (username_exists == false)
			throw user_not_found_exception();
	}
}

void server::estimate(int num, string recipe_name)
{
	int cost=0;
	for (int i=0;i<recipes.size();i++)
	{
		if (recipe_name == recipes[i].get_name())
		{	
			cout << setw(25) <<"ingredient" << setw(25) << "required"<< setw(25)  << "available" << setw(25) << "purchase price" << endl; 
			vector <ingredient> ingredients = recipes[i].get_ingredients();
			for (int j=0;j<ingredients.size();j++)
			{
				cout << setw(25) << ingredients[j].name << setw(25) << ingredients[j].amount * num ;
				cout << setw(25) << system_warehouse.available(ingredients[j].name);
				if (system_warehouse.available(ingredients[j].name) >= ingredients[j].amount*num)
				{
					cout << setw(25) << 0 << endl;
				}
				else
				{			
					try
					{
						cost += (ingredients[j].amount*num - system_warehouse.available(ingredients[j].name))* system_warehouse.last_price(ingredients[j].name);		
						cout << setw(25) << (ingredients[j].amount*num - system_warehouse.available(ingredients[j].name))* system_warehouse.last_price(ingredients[j].name) << endl;
					}
					catch (no_price_yet_exception ex)
					{
						cout << endl << "no price for" << ingredients[j].name << "!" << endl;
					}
				}
			}
			cout << setw(100) << cost << endl;
		}
	}
}
void server::add_shipment(vector <item> items)
{
	time_t t = time (0);
	struct tm *now = localtime(&t);
	int year = (now->tm_year + 1900); 
    int month = (now->tm_mon + 1) ;
    int day = now->tm_mday;
    date d(day,month,year);
    system_warehouse.add_shipment(shipment(d,items));
    cout << "present warehouse value: " << system_warehouse.get_value() << endl;

}
void server::create_menu(vector <menu_item> items)
{
	menu temp(items);
	system_menu = temp;
	system_menu.print_menu();
}
void server::reserve(reservation_item item)
{
	if (loged_in_user == NULL)
	{
		cout << "no one is using the system!" << endl;
	}
	else 
	{
		if (!system_menu.has_item(item.day_in_week,item.food_name))
				throw not_in_menu_exception();
			int index = -1;
			for (int i=0;i<recipes.size();i++)
			{
				if (recipes[i].get_name() == item.food_name)
					index = i;
			}
			if (index != -1)
			{
				system_warehouse.reserve(recipes[index]);			
				loged_in_user->reserve(item);
				// loged_in_user->print_reservations();
			}
	}
}
void server::initialize_warehouse()
{
	system_warehouse.clear();
	ifstream in ("warehouse.txt");
	string hashtag;
	string arrival_day;
	string arrival_month;
	string arrival_year;
	string items;
	string item_name;
	string unit_price;
	string amount;
	bool is_name=true;
	vector <shipment> shipments;
	while (getline(in,hashtag,' '))
	{
		if (hashtag == "#")
		{
			getline (in,arrival_day,'-');
			cout << "day:" << arrival_day << endl;

			getline (in,arrival_month,'-');
			cout << "month:" <<arrival_month << endl;

			getline (in,arrival_year);
			cout << "year:" << arrival_year << endl;
			
			int day,month,year;
			day = stoi (arrival_day);
			month = stoi (arrival_month);
			year = stoi (arrival_year);
			date arrival_date(day,month,year);
			getline (in,items);
			stringstream mystream(items);
			string temp;
			vector <item> shipment_items;
			while(!mystream.eof())
			{
				mystream >> temp;
				item_name = temp.substr(1,temp.size()-2);
				cout << "item name: " << item_name ;
				mystream >> temp;
				amount = temp.substr(0,temp.size()-1);
				cout << "   amount: " << amount ;
				
				mystream >> temp;
				if (mystream.eof())
					unit_price = temp.substr(0,temp.size()-1);
				else
					unit_price = temp.substr(0,temp.size()-2);
				cout << "      unit_price: " << unit_price << endl;

				item temp_item(item_name,stoi(amount),stoi(unit_price));
				shipment_items.push_back(temp_item);
			}		
			shipment temp_shipment(arrival_date,shipment_items);
			// shipments.push_back(temp_shipment);
			system_warehouse.add_shipment(temp_shipment);
		}
	}
	// warehouse my_warehouse(shipments);
	// return my_warehouse;
}



void server::initialize_recipes()
{
	recipes.clear();
	ifstream in ("recipes.txt");
	string hashtag;
	string name;
	string ingredients;
	string ingredient_name;
	string ingredient_amount;
	vector<ingredient> ingredients_vec;
	
	while (getline(in,hashtag,' '))
	{
		ingredients_vec.clear();
		if (hashtag == "#")
		{
			
			getline (in,name);
			cout << "name:" << name << endl;
			
			getline (in,ingredients);
			stringstream mystream(ingredients);
			string temp;
			while(!mystream.eof())
			{
				mystream >> temp;
				ingredient_name = temp.substr(1,temp.size()-2);
				cout << "ingredient name: " << ingredient_name ;
				
				mystream >> temp;
				if (mystream.eof())
					ingredient_amount = temp.substr(0,temp.size()-1);
				else
					ingredient_amount = temp.substr(0,temp.size()-2);
				cout << "      ingredient_amount: " << ingredient_amount << endl;
				ingredient temp_ingredient(ingredient_name,stoi(ingredient_amount));
				ingredients_vec.push_back(temp_ingredient);
				// item temp_item(item_name,stoi(amount),stoi(unit_price));				
				// shipment_items.push_back(temp_item);
			}		
			recipe temp_recipe(name,ingredients_vec);
			recipes.push_back(temp_recipe);
		}
	}
}
void server::show_ingredients()
{
	system_warehouse.show_ingredients();
}
bool recipes_comparator(recipe& l, recipe& r){return l.get_name() < r.get_name();}
void server::show_recipes()
{
	vector <ingredient> ingredients;
	sort(recipes.begin(),recipes.end(),recipes_comparator);
	for (int i=0;i<recipes.size();i++)
	{
		ingredients.clear();
		int value = 0;
		cout << i+1;
		recipes[i].print_recipe();
		ingredients=recipes[i].get_ingredients();
		for (int j=0;j<ingredients.size();j++)
		{
			value += system_warehouse.get_value_of(ingredients[j].name,ingredients[j].amount); 
		}
		cout << "\t"  << value << endl;
	}
}
void server::admin_show_reservations()
{
	string days[5] = {"SAT","SUN","MON","TUE","WED"};
	cout <<setw(20)<< "customer" << setw(30) << "meal"<< setw(30) << "day" << endl;
	for (int i=0;i<5;i++)
	{
		for(int j=0;j<profs.size();j++)
		{
			profs[j].print_reservation_by_day(days[i]);
		}
	}
}
void server::prof_show_reservations()
{
	((prof*)loged_in_user)->print_reservations();
}
void server::print_recipes()
{
	for(int i=0;i<recipes.size();i++)
		recipes[i].print_recipe();
}
void server::show_warehouse()
{
	system_warehouse.print_warehouse();
}
void server::show_profs()
{
	for(int i=0;i<profs.size();i++)
		profs[i].print_prof();
}
void server::show_admin()
{
	system_admin.print_admin();
}

void server::finilize()
{
	int cost=0;
	int income=0;
	vector <ingredient> ingredients;
	vector <menu_item> menu_items;
	menu_items = system_menu.get_items();
	sort(recipes.begin(),recipes.end(),recipes_comparator);
	int num=0;
	for (int x=0;x<recipes.size();x++)
	{
		num = 0;
		for (int i=0;i<menu_items.size();i++)
		{
			// cout << "oomadim too menuitems\n";
			// cout <<"menu_items:"<<menu_items[i].food_name << "-recipe_name:" <<recipes[x].get_name() << endl;
			if (menu_items[i].food_name == recipes[x].get_name())
			{
				// cout << "zire in ife!!\n\n";
				for(int j=0;j<profs.size();j++)
				{

					if (profs[j].has_reserved(menu_items[i].day_in_week,menu_items[i].food_name))
					{
							num++;
							income += menu_items[i].price;
					}
				}
			}
		}

			
			if (num != 0)
			{
				cout << recipes[x].get_name() << ": " << num << endl;

				ingredients.clear();
				int value = 0;
				// cout << i+1;
				// recipes[i].print_recipe();
				ingredients=recipes[x].get_ingredients();
				for (int j=0;j<ingredients.size();j++)
				{
					value += system_warehouse.get_value_of(ingredients[j].name,ingredients[j].amount); 
				}
				cost += value * num;
			}
	}

	cout << "cost: " << cost << endl << "sold: " << income << endl << "profit: " << income-cost <<"("<<(double)(income-cost)/cost *100 << "\%)" << endl;
}




