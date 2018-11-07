#include "arithmetic_or.h"
using namespace std;

arithmetic_or::arithmetic_or(int _node_index, int _parent_index, vector <node*> _childs) : or_gate(_node_index,_parent_index,_childs) {}

int arithmetic_or::evaluate_node()
{
	return childs[0]->evaluate_node() + childs[1]->evaluate_node();
}