#include "bitwise_xor.h"
using namespace std;

bitwise_xor::bitwise_xor(int _node_index, int _parent_index, vector <node*> _childs) : xor_gate(_node_index,_parent_index,_childs) {}

int bitwise_xor::evaluate_node()
{
	try
	{
		if (childs.size())
		{
			int result=childs[0]->evaluate_node();
			for (int i=1;i<childs.size();i++)
			{
				result^=childs[i]->evaluate_node();
			}
			return result;
		}
		else
			throw no_argument_exception();
	}
	catch(no_argument_exception ex)
	{
		cerr << "no argument!" << endl;
		return -1; 
	}
}