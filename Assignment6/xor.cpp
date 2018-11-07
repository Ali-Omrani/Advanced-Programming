#include "xor.h"
using namespace std;

xor_gate::xor_gate(int _node_index, int _parent_index, vector <node*> _childs) : operator_class(_node_index,_parent_index,_childs) {}

int xor_gate::get_type_of()
{
	return 2;
}
bool xor_gate::add_is_possible()
{
	return true;
}
// int xor_gate::evaluate_node()
// {
// 	return this->evaluate();
// }
// int xor_gate::evaluate()
// {
// 	return this->evaluate_xor();
// }