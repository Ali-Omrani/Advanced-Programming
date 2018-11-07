#include "tree.h"
using namespace std;

node* node_creator(string type, string input_value, int node_index, int parent_index, string mode, vector <node*> children)
{
	if(type=="operator")
	{
		if (mode=="-b")
		{
			if (input_value=="OR")
				return new bitwise_or(node_index,parent_index,children);
			else if (input_value=="AND")
				return new bitwise_and(node_index,parent_index,children);
			else if (input_value=="XOR")
				return new bitwise_xor(node_index,parent_index,children);
			else if (input_value=="NOT")
				return new bitwise_not(node_index,parent_index,children);
		}
		else
		{
			if (input_value=="OR")
				return new arithmetic_or(node_index,parent_index,children);
			else if (input_value=="AND")
				return new arithmetic_and(node_index,parent_index,children);
			else if (input_value=="XOR")
				return new arithmetic_xor(node_index,parent_index,children);
			else if (input_value=="NOT")
				return new arithmetic_not(node_index,parent_index,children);
		}
	}
	else if (type=="input")
	{
		return new decimal(input_value,node_index,parent_index,children);
	}
}

int tree::evaluate_tree()
{
	return root->evaluate_node();
}
tree::tree()
{
	int num_of_nodes;
	int node_index,parent_index;
	string type;
	string input_value;
	cin >> num_of_nodes;
	for (int i=1;i<=num_of_nodes;i++)
	{
		vector <node*> children;
		cin >> node_index >> parent_index ;
		cin >> type ;
		cin >> input_value;
		if (type=="operator")
		{
			if (parent_index==-1)
			{
				root = node_creator(type,input_value,node_index,parent_index,"a",children);
				nodes.push_back(root);
			}
			else
			{
				node* temp = node_creator(type,input_value,node_index,parent_index,"a",children);
				node* parent = this->node_finder(parent_index);
				parent->add_child(temp);
				nodes.push_back(temp);
			}
		}
		else if (type=="input")
		{
			node* temp = node_creator(type,input_value,node_index,parent_index,"a",children);
			node* parent = this->node_finder(parent_index);
			parent->add_child(temp);
			nodes.push_back(temp);
		}
	}
}

node* tree::node_finder(int index)
{
	for(int i=0;i<nodes.size();i++)
	{
		if (nodes[i]->get_index()==index)
			return nodes[i]; 
	}
}

void tree::rebase_node(int index,string base)
{
	node* temp = this->node_finder(index);
	node* temp_parent = this->node_finder(temp->get_parent_index());
	vector <node*> _children;
	node* new_node;
	if (base=="-b")
		 new_node = new binary(((operand*)temp)->get_input(),index,temp->get_parent_index(),_children); 	
	else if(base=="-o")
		new_node = new octal(((operand*)temp)->get_input(),index,temp->get_parent_index(),_children); 	
	else if(base=="-d")
		new_node = new decimal(((operand*)temp)->get_input(),index,temp->get_parent_index(),_children); 	
	else if(base=="-h")
		new_node = new hexa(((operand*)temp)->get_input(),index,temp->get_parent_index(),_children); 	
	temp_parent->delete_child(index);
	temp_parent->add_child(new_node);
	for (int i=0;i<nodes.size();i++)
	{
		if (nodes[i]->get_index()==index)
		{
			nodes.erase(nodes.begin()+i);
		}
	}
	
	nodes.push_back(new_node);
	delete temp;
	
	
}

void tree::remode_node(int index,string mode)
{
	node* temp = this->node_finder(index);
	node* temp_parent = this->node_finder(temp->get_parent_index());
	temp_parent->delete_child(index);
	//delete from nodes
	node* new_node=node_creator("operator",temp->type_detector(),index,temp->get_parent_index(),mode,temp->get_children());
	temp_parent->add_child(new_node);
	

	for (int i=0;i<nodes.size();i++)
	{
		if (nodes[i]->get_index()==index)
		{
			nodes.erase(nodes.begin()+i);
		}
	}
	
	nodes.push_back(new_node);
	delete temp;
}
	

void tree::reset_node(int index,string value)
{
	node* temp= this->node_finder(index);
	((operand*)temp)->set_input(value);
}

void tree::print_nodes()
{
	for (int i=0;i<nodes.size();i++)
	{
		cout << i << "-" << "   index:" << nodes[i]->get_index() << "   parent:" << nodes[i]->get_parent_index() << endl;
	}
}