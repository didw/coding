#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

typedef unsigned int UINT;
typedef vector<UINT> VecUINT;

struct Node
{
	VecUINT subs;
};

void CreateAntTree(ifstream & inStr, Node * const homeNode, const UINT N)
{
	int i = N;
	UINT a, b;

	while (i != 0)
	{
		inStr >> a >> b;
		homeNode[a].subs.push_back(b);
		//cout << "  add [" << a << "] <- [" << b << "]" << endl;
		--i;
	}
}

void IsExist(bool & ret, const Node * const homeNode, const UINT a, const UINT b)
{
	for (VecUINT::const_iterator iter = (*(homeNode + a)).subs.begin();
		iter != (*(homeNode + a)).subs.end();
		++iter)
	{
		if (*iter == b)
		{
			ret = true;
		}
		else
		{
			IsExist(ret, homeNode, *iter, b);
			if (ret) break;
		}
	}
}

bool solve(const Node * const homeNode, const UINT a, const UINT b)
{
	//cout << "  - Q [" << a << "," << b << "]" << endl;
	bool ret1 = false, ret2 = false;

	IsExist(ret1, homeNode, a, b);
	//cout << "  - ret1 " << ret1 << endl;
	IsExist(ret2, homeNode, b, a);
	//cout << "  - ret2 " << ret2 << endl;

	if (ret1 || ret2)
		return true;
	else
		return false;
}

int main(int argc, char ** argv)
{
	ifstream inStream(argv[1]);
	ofstream outStream("output.txt");
	if (inStream.is_open() && outStream.is_open())
	{
		UINT cntTestcase;

		inStream >> cntTestcase;

		while (cntTestcase != 0)
		{
			cout << "Testcase [" << cntTestcase << "]" << endl;

			UINT N, M;
			Node * nodeHome = new Node[200000];

			inStream >> N >> M;
			//cout << "  - " << N << ", " << M << endl;

			CreateAntTree(inStream, nodeHome, N - 1);
			//cout << "  - build done" << endl;

			while (M != 0)
			{
				UINT a, b;

				inStream >> a >> b;

				const bool ret = solve(nodeHome, a, b);

				//cout << ret << endl;
				outStream << (ret ? "1" : "0") << endl;

				--M;
			}

			delete[] nodeHome;
			--cntTestcase;
		}
	}

	outStream.close();
	inStream.close();	

	return EXIT_SUCCESS;
}
