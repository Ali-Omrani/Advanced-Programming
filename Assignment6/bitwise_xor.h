#ifndef _BINARYXOR_
#define _BINARYXOR_
#include "xor.h"

class bitwise_xor : public xor_gate
{
public:
	bitwise_xor(int _node_index, int _parent_index, std::vector <node*> _childs);
	int evaluate_node();	
};

#endif