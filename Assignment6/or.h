#ifndef _ORGATE_
#define _ORGATE_
#include "operator.h"
class or_gate : public operator_class
{
public:
	or_gate(int _node_index, int _parent_index, std::vector <node*> _childs);
	// virtual int evaluate_or() = 0 ;
	// int evaluate() ;	
	bool add_is_possible();
	// int evaluate_node();
	int get_type_of();
protected:

};
#endif