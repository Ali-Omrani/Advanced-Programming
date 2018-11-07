#ifndef _PROF_
#define _PROF_
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include "timer.h"
#include "user.h"
struct reservation_item
{
	reservation_item(std::string day, std::string name);
	std::string day_in_week;
	std::string food_name;
	int refrence;
};
class prof : public user
{
public:
	prof(std::string _username, std::string _password);
	std::string get_username();
	std::string get_password();
	std::string what_are_you();
	int get_failed_attempt_num();
	bool is_blocked();
	void toggle_blocked_status();
	void start_timer();
	int time_passed();
	void set_failed_attempt_num(int val);
	void print_prof();
	void print_reservations();
	void show_menu();
	void reserve(reservation_item item);
	void show_reservations();
	void print_reservation_by_day(std::string day);
	bool has_reserved(std::string day, std::string name);
private:
	std::vector <reservation_item> reserved_items;
	int failed_attempt_num;
	time_t t;
	bool blocked;
};
#endif