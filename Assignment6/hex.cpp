#include "hex.h"
using namespace std;

hexa::hexa(string _input,int _node_index, int _parent_index, vector <node*> _childs) : operand(_input,_node_index,_parent_index,_childs)
{
	this->set_input(_input);
}


int hexa::string_to_decimal()
{
	int result=0;
	int index_diff=0;
	for (int i=0;i<input.length();i++)
	{
		if (input[i]>=65 && input[i]<=70)
			index_diff=uppercase_to_int;
		else if (input[i]>=48 && input[i]<=57)
			index_diff=chardigit_to_int;
		else if (input[i]>=97 && input[i]<=102)
			index_diff=lowercase_to_int;
		
		result+=(input[i]-index_diff)*pow(2,4*(input.length()-i-1));
	}
	return result;
}

void hexa::input_is_valid(string in)
{
		for(int i=0;i<input.length();i++)
		{
			if (input[i]>=65 && input[i]<=70)
				continue;
			else if (input[i]>=48 && input[i]<=57)
				continue;
			else if (input[i]>=97 && input[i]<=102)
				continue;
			else 
				throw invalid_input_exception();
			
		}		
}