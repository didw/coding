// problem_1.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

ofstream	logfile;

typedef struct {
	int index;
	int parent;
	int seed;
} NODE;

// initially crossing=lower_node
// 1. upper_node가 교차로라면, 
//   1) parent[crossing] -> parent[crossing's parent] --> ... 가 upper_node와 언젠가는 만나야한다. => 성공
//	 2) parent[crossing] -> ... 하다가, depth[crossing] < depth[upper_node] => 실패
// 2. upper_node가 교차로가 아니라면,
//   1) parent[upper_node] == parent[crossing's parent] --> 가 언젠가는 이루어져야하고, 
//       ㄱ) AND ancestor[upper_node].seed == ancestor[crossing]].seed 여야 함. => 성공
//		 ㄴ) AND ancestor[upper_node].seed != ancestor[crossing]].seed 여야 함. => 실패
//   2) parent[crossing] -> ... 하다가, depth[crossing] < depth[parent[upper_node]] => 실패

int solve(int upper_node, int lower_node, int* tree, int* depth, map<int, vector<int>*> &children, NODE* ancestor)
{
	if( upper_node==0 ) {
		return 1;
	}

	int result = 0;

	int current = lower_node;

	bool is_upper_an_ancestor = false;
	int upper_parent = upper_node;
	int upper_depth = depth[upper_node];

	vector<int>* upper_child = children[upper_node];
	if( upper_child->size() > 1 ) {
		// upper_node가 2개 이상의 child를 갖는다면, 교차로(ancestor)이다.
		is_upper_an_ancestor = true;
	}
	else {
		// upper_node가 교차로가 아니라면, parent인 교차로(ancestor)가 찾기비교대상이다.
		upper_parent = ancestor[upper_node].parent;
		upper_depth = depth[upper_parent];
	}

	int loop_cc = 0;

	while(current != 0) {

		loop_cc++;

		int parent = ancestor[current].parent;

		if( parent == upper_parent) {

			if( is_upper_an_ancestor == true ) {
				// 1 - 1) 의 case
				return 1;
			}
			else {
				if( ancestor[current].seed == ancestor[upper_node].seed ) {
					// 2 - 1) - ㄱ) 의 case
					return 1;
				}
				else {
					// 2 - 1) - L) 의 case 
					return 0;
				}
			}
		}

		if( depth[parent] <= upper_depth ) {
			break;
		}

		current = parent;
	}

	//logfile << "loop_cc = " << loop_cc << endl;

	return result;
}

int make_tree(map<int, vector<int>*> &all_nodes, int* depth, NODE* ancestor) 
{
	int root = 0,  height = 0;

	int	numNodes = all_nodes.size();
	int node_cc = 0;

	vector<int> siblings;
	siblings.push_back(root);

	while(node_cc < numNodes) {

		vector<int> temp;

		vector<int>::iterator it = siblings.begin();
		for(; it != siblings.end(); it++ ) {
			int self = *it;
			depth[self] = height;

			// num_of_node++
			node_cc++;

			// child의 개수가 1이면, child->parent = self->parent. 
			//  seed값도, self->parent의 seed값과 동일
			int seed = ancestor[self].seed;
			int parent = ancestor[self].parent;

			vector<int>*& child_nodes = all_nodes[self];
			if( child_nodes->size() > 1 ) {
				// child의 개수가 2이상면, child->parent = self;
				// seed값도 초기화
				seed = 0;
				parent = self;
			}

			vector<int>::iterator iter2 = child_nodes->begin();
			for(; iter2 != child_nodes->end(); iter2++ ) {
				int child = *iter2;
				temp.push_back(child);

				ancestor[child].parent = parent;
				ancestor[child].seed = seed;

				seed++;
			}
		}

		// depth++
		height++;

		// sibling clear
		siblings.clear();
		
		// sibling's children(==temp) --> sibling array
		it = temp.begin();
		for(; it != temp.end(); it++ ) {
			siblings.push_back(*it);
		}
	}

	return height;
}

int main(int argc, char* argv[])
{
	int T = 0;

	logfile.open("debug.txt", ofstream::out);

	ofstream outfile("output.txt", ofstream::out);

	string infilename("input.txt");
	if( argc == 2 ) {
		infilename = argv[1];
	}
	ifstream infile(infilename.c_str(), ifstream::in);
	infile >> T;

	cout << "T = " << T << endl;

	for(int tc=0; tc < T; tc++ ) {

		int N, M;
		infile >> N;
		infile >> M;

		map<int, vector<int>*> children;
		int* tree = new int[N];
		int* depth = new int[N];
		NODE* ancestor = new NODE[N];

		for(int n=0; n < N; n++ ) {
			children[n] = new vector<int>;
			ancestor[n].index = n;
			ancestor[n].parent = 0; // initially the ROOT node is all nodes' parent.
			ancestor[n].seed = 0;
		}

		//cout << "children.size() = " << children.size() << endl;

		for(int n=0; n < (N-1); n++ ) {
			int up, down;

			infile >> up;
			infile >> down;

			// convert to numbers to 0-based
			up--;
			down--;

			tree[down] = up;

			children[up]->push_back(down);	
		}

		// tree 구성을 통해  depth 계산
		int max_depth = make_tree(children, depth, ancestor);

		cout << "T[" << tc << "] max_depth=" << max_depth << endl;

		int prev_M = 0;

		for(int m=0; m < M; m++ ) {

			int result = 0;
			
			int first, second;
			infile >> first;
			infile >> second;

			// convert to numbers to 0-based
			first--;
			second--;

			if( first == second ) {
				result = 1;
			}
			else {
				int upper_node = first;
				int lower_node = second;
		
				if( depth[first] > depth[second] ) {
					upper_node = second;
					lower_node = first;
				}

				//if( tc == 9 ) {
					logfile << (depth[lower_node] - depth[upper_node]) << " = depth[lower_node]=" << depth[lower_node] << ", depth[upper_node]=" << depth[upper_node] << endl;
				//}

				result = solve(upper_node, lower_node, tree, depth, children, ancestor);
			}		

			outfile << result << endl;

			//cout << result << endl;
			if( (prev_M+1000) <= m ) {
				cout << "T[" << tc << "]M[" << m << "] ended" << endl;

				prev_M = m;
			}
		}

		cout << "TC[" << tc << "] ended" << endl;

		delete[] tree;
		delete[] depth;
		delete[] ancestor;

		for(int n=0; n < N; n++ ) {
			delete children[n];
		}
		children.clear();
	}

	infile.close();
	outfile.close();
	
	logfile.close();

	return 0;
}

