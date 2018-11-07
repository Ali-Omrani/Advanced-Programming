#ifndef _ARITHMETICOR_
#define _ARITHMETICOR_
#include "or.h"

class arithmetic_or : public or_gate
{
public:
	arithmetic_or(int _node_index, int _parent_index, std::vector <node*> _childs);
	int evaluate_node();
};
#endif