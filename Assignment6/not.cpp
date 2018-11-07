#include "not.h"
using namespace std;

not_gate::not_gate(int _node_index, int _parent_index, vector <node*> _childs) : operator_class(_node_index,_parent_index,_childs) {}

int not_gate::get_type_of()
{
	return 1;
}
bool not_gate::add_is_possible()
{
	if (childs.size()==0)
		return true;
	else 
		return false;
}
// int not_gate::evaluate_node()
// {
// 	return this->evaluate();
// }
// int not_gate::evaluate()
// {
// 	return this->evaluate_not();
// }