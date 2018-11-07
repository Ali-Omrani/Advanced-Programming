#ifndef _TIMER_
#define _TIMER_
#include <iostream>
#include <ctime>
class timer {
public:
	void start(); 
	int get_beg_time();
	unsigned long elapsed_time();
	bool is_timeout(unsigned long seconds) ;
		
private:
	unsigned long beg_time;
		
};
#endif