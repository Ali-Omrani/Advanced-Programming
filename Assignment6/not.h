#ifndef _NOTGATE_
#define _NOTGATE_
#include "operand.h"
#include "operator.h"
class not_gate : public operator_class
{
public:
	not_gate(int _node_index, int _parent_index, std::vector <node*> _childs);
	// virtual int evaluate_not() = 0;
// 	int evaluate();
	bool add_is_possible();
	// int evaluate_node();
	int get_type_of();
protected:

};

#endif