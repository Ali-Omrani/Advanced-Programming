#include "or.h"
using namespace std;

or_gate::or_gate(int _node_index, int _parent_index, std::vector <node*> _childs) : operator_class(_node_index,_parent_index,_childs) {};
int or_gate::get_type_of()
{
	return 3;
	
}
bool or_gate::add_is_possible()
{
	if(childs.size()<2)
		return true;
	else
		return false;
}
// int or_gate::evaluate_node()
// {
// 	this->evaluate();
// }
// int or_gate::evaluate()
// {
// 	return this->evaluate_or();
// }