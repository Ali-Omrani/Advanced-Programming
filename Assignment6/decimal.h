#ifndef _DECIMAL_
#define _DECIMAL_
#include "operand.h"
class decimal : public operand
{
public:
	decimal(std::string _input,int _node_index, int _parent_index, std::vector <node*> _childs);
	int string_to_decimal();
	void input_is_valid(std::string in);
};
#endif