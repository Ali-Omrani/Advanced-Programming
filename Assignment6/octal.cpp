#include "octal.h"
using namespace std;

octal::octal(string _input,int _node_index, int _parent_index, vector <node*> _childs) : operand(_input,_node_index,_parent_index,_childs)
{
	this->set_input(_input);
}


int octal::string_to_decimal()
{
	int result=0;
		for(int i=0;i<input.length();i++)
		{
				result+=(input[i]-chardigit_to_int)*pow(8,(input.length()-i-1));
		}
		return result;
}

void octal::input_is_valid(string in)
{
		for(int i=0;i<input.length();i++)
		{
			if (input[i]>=48 && input[i]<=55)
				continue;
			else 
				throw invalid_input_exception();
		}
		
}