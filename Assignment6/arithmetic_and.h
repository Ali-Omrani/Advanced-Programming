#ifndef _ARITHMETICAND_
#define _ARITHMETICAND_
#include "and.h"
class arithmetic_and : public and_gate
{
public:
	arithmetic_and(int _node_index, int _parent_index, std::vector <node*> _childs);
	// int evaluate_and();
	int evaluate_node();
};

#endif