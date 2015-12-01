#include "Node.h"
#include <iostream>
#include "InputFileReader.h"
#include <map>

using namespace std;

Node::Node() : value(0)
{
}

Node::Node(int first) : value(first)
{
}

Node::Node(int first, int second) : value(0)
{
	value = first;
	//nodes[next_node_index++] = new Node(second);
	v_nodes.push_back(new Node(second));
}

Node::~Node(void)
{
	//delete[] nodes;
}

void Node::add_node(int first, int second) 
{
	Node * found_node = find_node(first);

	if (found_node != NULL) 
	{
		found_node->attach_node(new Node(second));
	}
}
void Node::attach_node(Node * node) 
{
	//nodes[next_node_index++] = node;
	v_nodes.push_back(node);
}

Node * Node::find_node(int value) 
{
	Node * find_node = NULL;
	std::vector<Node*>::iterator it;
	//cout << "T:" << value << endl;
	if (this->value == value) 
	{
		return this;
	} 
	else 
	{
		/*
		for (int cnt = 0 ; cnt < next_node_index; cnt++) 
		{
			if ((find_node = nodes[cnt]->find_node(value)) != NULL) 
			{
				break;
			}

		}
		*/
		for (it = v_nodes.begin(); it != v_nodes.end(); it++) 
		{
			//cout << "T2:" << (*it)->value << endl;
			if ((find_node = (*it)->find_node(value)) != NULL) 
			{
				break;
			}
		}
	}
	return find_node;
}


bool Node::find_path(int start, int end) 
{
	// 1. find start
	//cout << "s: "<< start << " e: " << end << endl;
	Node * node = find_node(start);
	if (node != NULL) 
	{
		if (node->find_node(end) != NULL)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	return false;
}

void Node::print_tree() 
{
	/*
	std::cout << value << std::endl;
	for (int cnt = 0; cnt < next_node_index; cnt++) 
	{
		nodes[cnt]->print_tree();
	}
	*/

	vector<Node*>::iterator it;
	for (it = v_nodes.begin(); it != v_nodes.end(); it++) 
	{
		(*it)->print_tree();
	}
}

bool find(int start, int end, std::multimap<int, int> &m) 
{
	std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator> find_pair;
	find_pair = m.equal_range(start);
	bool result = false;

	for(std::multimap<int, int>::iterator it = find_pair.first; it != find_pair.second; ++it) 
	{
		//cout << "f: " << (*it).second << ":";
		if ((*it).second == end) 
		{
			//cout << "1.found " << end << ": ";
			result = true;
			break;
		} else {
			result = find((*it).second, end, m);
			if (result)
			{
				//cout << "2.found " << end << ": ";
				break;
			}
		}
	}
	//cout << "==" << start << endl;

	return result;
}

void main (int argc, char *argv[] ) 
{	
	if ( argc < 2 )
	{
		fprintf( stderr, "ERROR, please input filename" );
		exit( 1 );
	}

	char * filename = argv[1];

	InputFileReader * in = new InputFileReader();
	in->loadFile(filename);
	//in->printValue();


	for (int case_idx = 0; case_idx < in->number_of_test_case; case_idx++) 
	{
		/*Node * nodes = NULL;

		for (int n_idx = 0; n_idx < in->header_info[case_idx].number_of_n - 1; n_idx++) 
		{
			if (n_idx == 0) 
				nodes = new Node(in->cross_info[case_idx][n_idx].first, in->cross_info[case_idx][n_idx].second);
			else 
				nodes->add_node(in->cross_info[case_idx][n_idx].first,  in->cross_info[case_idx][n_idx].second);
		}

		for (int m_idx = 0; m_idx < in->header_info[case_idx].number_of_m; m_idx++) 
		{
			cout << nodes->find_path(in->query_info[case_idx][m_idx].start, in->query_info[case_idx][m_idx].end) << endl;
		}
		cout << "start" << endl;
		nodes->print_tree();
		delete nodes;*/
		//cout << "case #start" << endl;
		std::multimap<int, int> m;
		//if (case_idx == 9) {
		for (int n_idx = 0; n_idx < in->header_info[case_idx].number_of_n - 1; n_idx++) 
		{
			m.insert(pair<int, int>(in->cross_info[case_idx][n_idx].first, in->cross_info[case_idx][n_idx].second));
		}

		for (int m_idx = 0; m_idx < in->header_info[case_idx].number_of_m; m_idx++) 
		{
			//cout << "S: " << in->query_info[case_idx][m_idx].start << " D: " << in->query_info[case_idx][m_idx].end<< " : " << endl;
			bool result = find(in->query_info[case_idx][m_idx].start, in->query_info[case_idx][m_idx].end, m);
			bool result_r = find(in->query_info[case_idx][m_idx].end, in->query_info[case_idx][m_idx].start, m);

			if (result || result_r) cout << 1 << endl;
			else cout << 0 << endl;
		}
		//}


		/*if (case_idx == 9) 
		{
			for (std::multimap<int, int>::iterator it = m.begin();it != m.end();++it)
			{
				cout << "  [" << (*it).first << ", " << (*it).second << "]" << endl;
			}
		}*/


	}


	/*Node * path = new Node(1, 2);
	path->add_node(2, 4);
	path->add_node(2, 5);
	path->add_node(1, 3);
	path->add_node(3, 6);
	path->add_node(3, 7);
	path->add_node(3, 8);


	std::cout << path->find_path(1, 5) << std::endl;
	std::cout << path->find_path(4, 7) << std::endl;


	Node * path2 = new Node(1, 2);
	path2->add_node(1, 3);
	path2->add_node(3, 4);
	path2->add_node(3, 5);

	std::cout << path2->find_path(2, 3) << std::endl;
	std::cout << path2->find_path(3, 5) << std::endl;*/


	//path->print_tree();


}
