#include <iostream>
#include <vector>
#include "operand.h"
#include "binary.h"
#include "hex.h"
#include "decimal.h"
#include "octal.h"
#include "and.h"
#include "bitwise_and.h"
#include "arithmetic_and.h"
#include "or.h"
#include "bitwise_or.h"
#include "arithmetic_or.h"
#include "not.h"
#include "bitwise_not.h"
#include "arithmetic_not.h"
#include "xor.h"
#include "bitwise_xor.h"
#include "arithmetic_xor.h"
#include "node.h"
#include "tree.h"
const int digit_to_char = 48;
const int digit_to_lower = 87;
using namespace std;
string decimal_to_binary(int input)
{
	string result;
	while(input/2)
	{
		result+=input%2+digit_to_char;
		input/=2;
	}
	if (input>=0)
		result+=input+digit_to_char;
	else 
	{
		result+=input+digit_to_char+2;
		result+="-";
	}
	string final_result;
	for (int i=result.length()-1;i>=0;i--)
		final_result+=result[i];
	return final_result;	
}
string decimal_to_octal(int input)
{
	string result;
	while(input/8)
	{
		result+=input%8+digit_to_char;
		input/=8;
	}
	result+=input+digit_to_char;
	string final_result;
	for (int i=result.length()-1;i>=0;i--)
		final_result+=result[i];
	return final_result;	
		
}
string decimal_to_hex(int input)
{
	string result;
	while(input/16)
	{
		if (input%16<=9)
		 	result+=input%16+digit_to_char;
		else
			result+=input%16+digit_to_lower;
			
		input/=16;
	}
	
	if (input%16<=9)
	 	result+=input+digit_to_char;
	else
		result+=input+digit_to_lower;
	
	string final_result;
	for (int i=result.length()-1;i>=0;i--)
		final_result+=result[i];
	return final_result;	
		
}





void parser()
{
	tree expression_tree;
	string command;
	string flag;
	string input_value;
	int node_index;
	while(cin >> command)
	{
		//cout << command << endl;
		if(command=="evaluate")
		{
			cin >> flag;
			if (flag=="-b")
				cout << decimal_to_binary(expression_tree.evaluate_tree()) << endl;
			else if (flag=="-o")
				cout << decimal_to_octal(expression_tree.evaluate_tree()) << endl;				
			else if (flag=="-d")
				cout << expression_tree.evaluate_tree() << endl;
			else if (flag=="-h")
				cout << decimal_to_hex(expression_tree.evaluate_tree()) << endl;			
			else
				cerr << "invalid command!" << endl;
		}
		else if(command=="rebase")
		{
			cin >> flag >> node_index;
			if(flag=="-d" || flag=="-h" || flag=="-o" || flag=="-b")
				expression_tree.rebase_node(node_index,flag);
			else
				cerr << "invalid command!" << endl;
		}
		else if(command=="remode")
		{
			cin >> flag >> node_index;
			if(flag=="-b" || flag=="-a")
				expression_tree.remode_node(node_index,flag);
			else
				cerr << "invalid command!" << endl;
		}
		 	else if(command=="reset")
		 	{
	 			cin >> node_index >> input_value;
				expression_tree.reset_node(node_index,input_value);
		 	}
		 }
 }
int main()
{
	//cout << "f:"<<decimal_to_binary(10) << endl;
	//cout << "g:"<<decimal_to_octal(15) << endl;
	//cout << "h:"<< decimal_to_hex(255) << endl;
	//string test;
	//	test+=2+48;
	//cout <<"test:"<< test << endl;
	parser();
	// vector <node*> test;
// 	binary a("01",1,0,test);
// 	hexa b("11",1,0,test);
// 	decimal  c("2",1,0,test);
// 	octal d("70",1,0,test);
// 	decimal e("56",1,0,test);
// 	decimal f("80",1,0,test);
// 	test.push_back(&a);
// 	test.push_back(&c);
// 	bitwise_and b_and(1,0,test);
// 	arithmetic_and a_and(1,0,test);
// 	bitwise_or b_or(1,0,test);
// 	arithmetic_or a_or(1,0,test);
// 	bitwise_not b_not(1,0,test);
// 	arithmetic_not a_not(1,0,test);
// 	bitwise_xor b_xor(1,0,test);
//
// 	test.push_back(&e);
// 	test.push_back(&f);
// 	arithmetic_xor a_xor(1,0,test);
//
//
// 	vector <node*> nodes;
// 	nodes.push_back(&a);
// 	nodes.push_back(&b);
// 	nodes.push_back(&c);
// 	nodes.push_back(&d);
// 	nodes.push_back(&b_and);
// 	nodes.push_back(&a_and);
// 	nodes.push_back(&b_or);
// 	nodes.push_back(&a_or);
// 	nodes.push_back(&b_not);
// 	nodes.push_back(&a_not);
// 	nodes.push_back(&b_xor);
// 	nodes.push_back(&a_xor);
// 	// nodes.push_back(&a);
// 	cout << "a: " << nodes[0]->evaluate_node() << endl;
// 	cout << "b: " << nodes[1]->evaluate_node() << endl;
// 	cout << "c: " << nodes[2]->evaluate_node() << endl;
// 	cout << "d: " << nodes[3]->evaluate_node() << endl;
// //cout << "e: " << nodes[4]->evaluate_node() << endl;
// 	cout << "a&c=" << nodes[4]->evaluate_node() << endl;
// 	cout << "a*c=" << nodes[5]->evaluate_node() << endl;
//
// 	cout << "a|c=" << nodes[6]->evaluate_node() << endl;
// 	cout << "a+c=" << nodes[7]->evaluate_node() << endl;
//
// 	cout << "!a=" << nodes[8]->evaluate_node() << endl;
// 	cout << "-a=" << nodes[9]->evaluate_node() << endl;
//
// 	cout << "a^c=" << nodes[10]->evaluate_node() << endl;
// 	cout << "a@c@e=" << nodes[11]->evaluate_node() << endl;
}
// check the input exception
// exception in add_child
// find parent in tree recursive
// remode node in tree
// exception in reset_node tree