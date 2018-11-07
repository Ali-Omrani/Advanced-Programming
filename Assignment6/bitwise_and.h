#ifndef _BITWISEAND_
#define _BITWISEAND_
#include "and.h"

class bitwise_and : public and_gate
{
public:
	bitwise_and(int _node_index, int _parent_index, std::vector <node*> _childs);
	int evaluate_node();	
};

#endif