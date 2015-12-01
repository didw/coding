#pragma once

#include <vector>

class Node
{
public:
	Node();
	Node(int first);
	Node(int first, int second) ;
	~Node(void);

	void print_tree();
	void add_node(int first, int second) ;
	void attach_node(Node * node) ;
	Node * find_node(int value) ;
	bool find_path(int start, int end);

private:
	//Node * nodes[200000];
	std::vector<Node*> v_nodes;
	int value;
	//int next_node_index;
};
