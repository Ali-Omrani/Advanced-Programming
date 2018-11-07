#ifndef _OCTAL_
#define _OCTAL_
#include "operand.h"

class octal : public operand
{
public:
	octal(std::string _input,int _node_index, int _parent_index, std::vector <node*> _childs);
	int string_to_decimal();
	void input_is_valid(std::string in);
};

#endif