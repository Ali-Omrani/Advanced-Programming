#ifndef _XORGATE_
#define _XORGATE_
#include "operand.h"
#include <vector>
#include "exception.h"
#include "operator.h"
class xor_gate : public operator_class
{
public:
	xor_gate(int _node_index, int _parent_index, std::vector <node*> _childs);
	// virtual int evaluate_xor() = 0;
// 	int evaluate();
	bool add_is_possible();
	// int evaluate_node();
	int get_type_of();
protected:
	
};


#endif