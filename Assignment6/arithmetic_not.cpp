#include "arithmetic_not.h"
using namespace std;

arithmetic_not::arithmetic_not(int _node_index, int _parent_index, vector <node*> _childs) : not_gate(_node_index,_parent_index,_childs) {};

int arithmetic_not::evaluate_node()
{
	return -childs[0]->evaluate_node();
}