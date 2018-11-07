#ifndef _OPERATOR_
#define _OPERATOR_
#include "node.h"
#include <iostream>
class operator_class : public node
{
public:
	//constructor:
	operator_class(int _node_index, int _parent_index, std::vector <node*> _childs);
	// virtual int evaluate () = 0;
// 	int evaluate_node();
	virtual int get_type_of() = 0;
	int get_type();


protected:
	// std::string input;
};
#endif