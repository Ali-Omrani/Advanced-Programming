#ifndef _BINARY_
#define _BINARY_
#include <iostream>
#include "operand.h"
class binary : public operand
{
public:
	binary (std::string _input,int _node_index, int _parent_index, std::vector <node*> _childs);
	int string_to_decimal();
	void input_is_valid(std::string in);
};

#endif