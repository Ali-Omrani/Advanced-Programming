#include "arithmetic_xor.h"
using namespace std;

arithmetic_xor::arithmetic_xor(int _node_index, int _parent_index,std::vector <node*> _childs) : xor_gate(_node_index,_parent_index,_childs) {};

int arithmetic_xor::evaluate_node()
{	
	vector <int> temp;
	if(childs.size())
	{	

		for (int i=0;i<childs.size();i++)
		{
			temp.push_back(childs[i]->evaluate_node());
		}
	}
	sort(temp.begin(),temp.end());
	return (temp.size()%2) ? temp[temp.size()/2] : (temp[temp.size()/2]+temp[temp.size()/2-1])/2;	
}