#ifndef _BITWISEOR_
#define _BITWISEOR_
#include "or.h"
#include "node.h"
class bitwise_or : public or_gate
{
public:
	bitwise_or(int _node_index, int _parent_index, std::vector <node*> _childs);
	int evaluate_node();
};
#endif