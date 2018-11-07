#include "timer.h"
using namespace std;

void timer::start()
{
	beg_time = clock();
}
int timer::get_beg_time()
{
	return beg_time;
}
unsigned long timer::elapsed_time() 
{
	return ((unsigned long) clock() - beg_time) / CLOCKS_PER_SEC;
}

bool timer::is_timeout(unsigned long seconds) 
{
	return seconds >= elapsed_time();
}