#ifndef _OPERAND_
#define _OPERAND_
#include <iostream>
#include <cmath>
#include "exception.h"
#include "node.h"
const int chardigit_to_int = 48;
const int uppercase_to_int = 55;
const int lowercase_to_int = 87;
class operand : public node
{
public:
	operand(std::string in, int _node_index, int _parent_index, std::vector <node*> _childs);
	std::string get_input();
	void set_input(std::string in) ;
	virtual void input_is_valid(std::string in) = 0;
	virtual int string_to_decimal() = 0;
	bool add_is_possible();
	int get_type();
	int evaluate_node();
protected:
	std::string input;
};
	

#endif