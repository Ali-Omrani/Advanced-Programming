#include "binary.h"
using namespace std;

binary::binary (string _input,int _node_index, int _parent_index, vector <node*> _childs) : operand(_input,_node_index,_parent_index,_childs)
{
	this->set_input(_input);
}

int binary::string_to_decimal()
{
		int result=0;
		for (int i=0;i<input.length();i++)
		{
			result+=(input[i]-chardigit_to_int)*pow(2,input.length()-i-1);
		}
		return result;
}

void binary::input_is_valid(string in)
{	
		for (int i=0;i<in.length();i++)
		{
			if (in[i]==48 || in[i]==49)
				continue;
			else 
				throw invalid_input_exception();
		}	
}