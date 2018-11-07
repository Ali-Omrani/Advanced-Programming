#include "operator.h"
using namespace std;

operator_class::operator_class(int _node_index, int _parent_index, vector <node*> _childs) : node(_node_index,_parent_index,_childs) {};

// int operator_class::evaluate_node()
// {
// 	cout << "operatoooooor!!!" << endl;
// 	cout << "index:" << node_index << "parent_index:" << parent_index <<" operator result=" << this->evaluate() << endl;
// 	// return this->evaluate();
// }

int operator_class::get_type()
{
	return this->get_type_of();
}