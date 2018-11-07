#include "decimal.h"
using namespace std;


decimal::decimal(string _input,int _node_index, int _parent_index, vector <node*> _childs) : operand(_input,_node_index,_parent_index,_childs)
{
	this->set_input(_input);
}


int decimal::string_to_decimal()
{
	int result=0;
	for(int i=0;i<input.length();i++)
	{
		if (input[i]>=48 && input[i]<=57)
			result+=(input[i]-chardigit_to_int)*pow(10,(input.length()-i-1));
		else 
			throw invalid_input_exception();
	}
	return result;
}


void decimal::input_is_valid(string in)
{
		for(int i=0;i<in.length();i++)
		{
			if (in[i]>=48 && in[i]<=57)
				continue;
			else 
				throw invalid_input_exception();
		}
		
}