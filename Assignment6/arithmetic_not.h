#ifndef _ARITHMETICNOT_
#define _ARITHMETICNOT_
#include "not.h"

class arithmetic_not : public not_gate
{
public:
	arithmetic_not(int _node_index, int _parent_index, std::vector <node*> _childs);
	int evaluate_node();	
};
#endif