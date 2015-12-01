#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

class Node {
private:
	int _parent;

public:
	Node();
	int getParent();
	void setParent(int parent);
};

Node::Node()
	: _parent(-1)
{
}

int Node::getParent()
{
	return _parent;
}

void Node::setParent(int parent)
{
	_parent = parent;
}

int checkPath(vector<Node> *nodes, int srcNode, int destNode)
{
	int findPath = 0;
	int temp = 0;

	do {
		temp = (*nodes)[srcNode].getParent();

		if (temp == destNode) {
			findPath = 1;
		}
		else {
			srcNode = temp;
		}
	} while (temp > 0 && findPath == 0);

	return findPath;
}

void checkNodes(ifstream *fin, ofstream *fout)
{
	int parentNode = 0;
	int childNode = 0;
	
	int nNum = 10;
	int mNum = 0;

	int findPath = 0;
	int srcNode = 0;
	int destNode = 0;

	int i;

	vector<Node> nodes;

	*fin >> nNum >> mNum;

	for (i = 0; i < nNum; i++) {
		nodes.push_back(Node());
	}
	
	for (i = 0; i < nNum-1; i++) {  // nNum - 1
		*fin >> parentNode >> childNode;
		parentNode--;
		childNode--;

		if (nodes[childNode].getParent() > 0) {
			cout << "already set parent!!" << endl;
		}
		nodes[childNode].setParent(parentNode);
	}

	for (i = 0; i < mNum; i++) {
		findPath = 0;

		*fin >> destNode >> srcNode;
		destNode--;
		srcNode--;

		findPath = checkPath(&nodes, destNode, srcNode);
		if (findPath == 0) {
			findPath = checkPath(&nodes, srcNode, destNode);
		}

	//	cout << findPath << endl;
		*fout << findPath << endl;
	}
}

int main(int argc, char *argv[])
{
	const int MAX_N = 10000;
	const int MAX_M = 10000;

	ifstream fin;
	ofstream fout;

	int caseNum = 0;
	
//	fin.open("C:\\Users\\hyogi\\Documents\\Visual Studio 2012\\Projects\\codejam01\\Debug\\test.txt");
	fin.open(argv[1]);
	fout.open(argv[2]);

	fin >> caseNum;
	
	for (int i = 0; i < caseNum; i++) {
		checkNodes(&fin, &fout);
	}

	fin.close();
	fout.close();

	return 0;
}
