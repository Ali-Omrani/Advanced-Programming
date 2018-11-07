#ifndef _BITWISENOT_
#define _BITWISENOT_
#include "not.h"

class bitwise_not : public not_gate
{
public:
	bitwise_not(int _node_index, int _parent_index, std::vector <node*> _childs);
	int evaluate_node();	
};

#endif