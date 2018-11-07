#ifndef _AND_
#define _AND_
#include "operator.h"
class and_gate : public operator_class
{
public:
	and_gate(int _node_index, int _parent_index, std::vector <node*> _childs);
	// virtual int evaluate_and() = 0;
// 	int evaluate();
	bool add_is_possible();
	// int evaluate_node();
	int get_type_of();
protected:
};

#endif