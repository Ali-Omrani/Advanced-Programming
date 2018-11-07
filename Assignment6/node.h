#ifndef _NODEHEADER_
#define _NODEHEADER_
#include <vector>
#include "exception.h"
#include <iostream>

class node
{
public:
	node(int _node_index, int parent_index, std::vector <node*> _childs);
	void add_child(node* child);
	int get_index();
	int get_parent_index();
	std::string type_detector();
	std::vector <node*> get_children();
	void delete_child(int index);
	virtual int get_type() = 0;
	virtual int evaluate_node() = 0;
	virtual bool add_is_possible() = 0;
protected:
	int node_index;
	int parent_index;
	std::vector <node*> childs;
};
#endif