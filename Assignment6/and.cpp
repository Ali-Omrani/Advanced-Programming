#include "and.h"
using namespace std;

and_gate::and_gate(int _node_index, int _parent_index, vector <node*> _childs) : operator_class(_node_index,_parent_index,_childs) {};

int and_gate::get_type_of()
{
	return 0;
}

bool and_gate::add_is_possible()
{
	if(childs.size()<2)
		return true;
	else 
		return false;
}

// int and_gate::evaluate_node()
// {
// 	return this->evaluate();
// }
//
// int and_gate::evaluate()
// {
// 	return this->evaluate_and();
// }
	
