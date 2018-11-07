#include "pair.h"
using namespace std;
Pair::Pair (const double _x,const double _y)
{
	x=_x;
	y=_y;
}
double Pair::get_x() const
{
	return x;
}

double Pair::get_y() const
{
	return y;
}

void Pair::set_y (const double _y)
{
	y=_y;
}

double& Pair::get_y_refrence()
{
	return y;
}
void Pair::print_pair() const
{
	cout << "(" << x << "," << y << ") " ;
}