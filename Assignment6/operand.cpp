#include "operand.h"
using namespace std;

operand::operand(string in, int _node_index, int _parent_index, vector <node*> _childs) : node(_node_index, _parent_index, _childs) , input(in) {}

bool operand::add_is_possible()
{
	return false;
}

int operand::evaluate_node()
{
	return this->string_to_decimal();
}

string operand::get_input()
{
	return input;
}

void operand::set_input(string in)
{	
	try
	{
		this->input_is_valid(in);	
		input = in;
	}
	catch (invalid_input_exception ex)
	{
		cerr << "invalid input!" << endl;
	}
}

int operand::get_type()
{
	return 4;
}
