#ifndef _HEX_
#define _HEX_
#include "operand.h"

class hexa : public operand
{
public:
	hexa(std::string _input,int _node_index, int _parent_index, std::vector <node*> _childs);
	int string_to_decimal();
	void input_is_valid(std::string in);
};

#endif