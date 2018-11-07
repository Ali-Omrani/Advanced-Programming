#include "node.h"
using namespace std;

node::node(int _node_index, int _parent_index, vector <node*> _childs) : node_index(_node_index) , parent_index(_parent_index) , childs(_childs) {}

void node::add_child(node* child)
{
	try
	{
		if (this->add_is_possible())
			childs.push_back(child);
		else 
			throw too_many_arguments_exception();
	}
	catch (too_many_arguments_exception ex)
	{
		cerr << "too many arguments!" << endl;
	}
}

int node::get_index()
{
	return node_index;
}

int node::get_parent_index()
{
	return parent_index; 
}

void node::delete_child(int index)
{
	for (int i=0;i<childs.size();i++)
	{
		if (childs[i]->get_index()==index)
		{
		
			childs.erase(childs.begin()+i);
		}
	}
}

string node::type_detector() {
	string list[] = {"AND","NOT","XOR","OR","not an operator"};
	return list[(this)->get_type()];
	
	/*if (dynamic_cast <and_gate*>(this) != NULL)
		return "AND";
	else if(dynamic_cast <not_gate*>(this) != NULL)
		return "NOT";
	else if(dynamic_cast <xor_gate*>(this) != NULL)
		return "XOR";
	else if (dynamic_cast <or_gate*>(this) != NULL)
		return "OR";
	else
		return "not an operator!";	//throw exception */
}

vector <node*> node::get_children()
{
	return childs;
}