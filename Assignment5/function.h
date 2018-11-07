#ifndef _FUNCTION_
#define _FUNCTION_

#include <vector>
#include <iostream>
#include "pair.h"
#include "exception.h"
class Function
{
public:
	Function();
	Function(const Function& g);
	Function operator+(const Pair& new_pair) const;
	Function operator-(const Pair& new_pair) const;
	
	Function operator+(const Function& f) const;
	Function operator-(const Function& f) const;
	Function operator|(const Function& f) const;

	Function operator+(const double _y) const;
	Function operator-(const double _y) const;
	Function operator*(const double _y) const;
	Function operator/(const double _y) const;
	
	Function operator++();
	Function operator++(int);

	double& operator()(const double x);
	Function operator()(const Function& f);
	
	Function& operator+=(const Pair& new_pair);
	Function& operator-=(const Pair& new_pair);

	Function& operator+=(const Function& f);
	Function& operator-=(const Function& f);
	Function& operator|=(const Function& f) ;


	Function& operator=(const Function& f);
	
	bool operator==(const Function& f);
	
	friend std::ostream& operator<<(std::ostream& out,const Function& f);

	void print_function() const;
	void add_pair(const Pair& new_pair);
	
	void erase_pair_by_index(const int index);
	void check_mutual_domain(const double x) const;
	int find_pair_by_x(const double x) const;
	
	int find_pair(const Pair& new_pair) const;
	
	// int get_size() const ;
	std::vector <Pair> get_pairs();
private:
	std::vector <Pair> pairs;

};

Function operator+(const Pair& new_pair,const Function& f);
Function operator-(const Pair& new_pair,const Function& f);

Function operator+(const double _y,const Function& f);
Function operator-(const double _y,const Function& f);
Function operator*(const double _y,const Function& f);



#endif