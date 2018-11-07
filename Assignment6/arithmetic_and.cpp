#include "arithmetic_and.h"
using namespace std;

arithmetic_and::arithmetic_and(int _node_index, int _parent_index, vector <node*> _childs) : and_gate(_node_index,_parent_index,_childs) {}

// int arithmetic_and::evaluate_and()
// {
// 	cout << "arithmetic_and" << endl;
// 	return childs[1]->evaluate_node() * childs[0]->evaluate_node();
//
// }

int arithmetic_and::evaluate_node()
{
	int result = childs[1]->evaluate_node() * childs[0]->evaluate_node();
	return result;
}