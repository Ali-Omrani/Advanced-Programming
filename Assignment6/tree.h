#ifndef _TREE_
#define _TREE_
#include <vector>
#include <iostream>
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
#include "operator.h"
class tree
{
public:
	//constructor
	tree();
	//add base to evaluate_tree
	int evaluate_tree();
	node* node_finder(int index);
	void rebase_node(int index, std::string base);
	void remode_node(int index, std::string mode);
	void reset_node(int index, std::string value);
	void print_nodes();
private:
	node* root;
	std::vector <node*> nodes;
};

node* node_creator(std::string type,std::string input_value, int node_index, int parent_index, std::string mode, std::vector <node*> children);	

#endif