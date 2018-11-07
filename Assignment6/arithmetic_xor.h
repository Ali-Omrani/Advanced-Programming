#ifndef _ARITHMETICXOR_
#define _ARITHMETICXOR_
#include "xor.h"
#include <algorithm> 
class arithmetic_xor : public xor_gate
{
public:
	arithmetic_xor(int _node_index, int _parent_index,std::vector <node*> _childs);
	int evaluate_node();
};

#endif 