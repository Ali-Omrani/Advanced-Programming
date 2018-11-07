#ifndef _PAIR_
#define _PAIR_

#include <iostream>

class Pair
{
public:
	Pair(const double _x,const double _y);
	double get_x() const;
	double get_y() const;
	void set_y (const double _y);	
	double& get_y_refrence();
	void print_pair() const;
private:
	double x;
	double y;

};

#endif