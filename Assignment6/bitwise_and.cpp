#include "bitwise_and.h"
using namespace std;

bitwise_and::bitwise_and(int _node_index, int _parent_index, vector <node*> _childs) : and_gate(_node_index,_parent_index,_childs) {}

int bitwise_and::evaluate_node()
{
	return childs[1]->evaluate_node() & childs[0]->evaluate_node();
}