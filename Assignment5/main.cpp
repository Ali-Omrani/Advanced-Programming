#include <iostream>
#include "pair.h"
#include "function.h"
using namespace std;
int main()
{
	Pair a(2,3); 
	Pair b(5,6.3);
	const Pair c(10,12);
	Pair d(2,5);
	Pair e(5,-2);
	Function f;		
	Function g;
	Function h;
	f+=a;
	f.add_pair(d);
	f=f+b;
	f+=c;
	g+=d;
	g+=e;
	// f(2)=10;
	cout << f;
}