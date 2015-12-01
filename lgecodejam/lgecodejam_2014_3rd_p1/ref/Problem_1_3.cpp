#include <iostream>
#include <string.h> // memset()
#include <stdlib.h> // exit(), abs()
#include <string>
#include <algorithm> // min(), max(), sort(), is_sorted(), reverse()
#include <vector> // vector
#include <utility>
#include <fstream>

using namespace std;

static fstream gFS;

struct testCase
{
	int mCrossCnt;
	int mQueryCnt;
	vector< pair<int, int> > mRoad;
	vector< pair<int, int> > mQuery;
	vector< vector<int> > mAdj; // 그래프의 인접 리스트
	vector<bool> visited;
	void readData();
	void printData();
	void makeGraph();
	void searchNode(int node);
	bool checkLinkedNode(int from, int to);
	void printResult();
};

void testCase::readData()
{
	gFS >> mCrossCnt >> mQueryCnt;

	if(mCrossCnt < 2 || mCrossCnt > 200000 
			|| mQueryCnt < 1 || mQueryCnt > 200000) {
		cout << "Wrong Cross Count or Query Count" << endl;
		exit(-1);
	}

	int c1, c2;
	for(int i = 0; i < mCrossCnt-1; i++) {
		gFS >> c1 >> c2;
		mRoad.push_back(make_pair(c1, c2));
	}

	int q1, q2;
	for(int i = 0; i < mQueryCnt; i++) {
		gFS >> q1 >> q2;
		mQuery.push_back(make_pair(q1, q2));
	}
}

void testCase::printData()
{
	cout << mCrossCnt << " " << mQueryCnt << endl;
	for(int i = 0; i < mCrossCnt-1; i++)
		cout << mRoad[i].first << " " << mRoad[i].second << endl;;

	for(int i = 0; i < mQueryCnt; i++)
		cout << mQuery[i].first << " " << mQuery[i].second << endl;
}

void testCase::makeGraph()
{
	mAdj = vector< vector<int> >(mCrossCnt+1, vector<int>()); // 1부터 시작
	for(int i = 0; i < mCrossCnt-1; i++) {
		mAdj[mRoad[i].first].push_back(mRoad[i].second);
	}
}

void testCase::searchNode(int here)
{
	visited[here] = true;
	for(int i = 0; i < (int)mAdj[here].size(); ++i) {
		int there = mAdj[here][i];
		if(!visited[there])
			searchNode(there);
	}
}

bool testCase::checkLinkedNode(int from, int to)
{
	bool connected = false;

	visited = vector<bool>(mAdj.size(), false); // visited 초기화

	// step 1
	searchNode(from);

	if(visited.size() > 0) {		
		if(visited[to] == true) {
			connected = true;		
		}					
	}

	if(!connected) {
		visited = vector<bool>(mAdj.size(), false); // visited 초기화
		// step 2
		searchNode(to);
		if(visited.size() > 0) {		   
			if(visited[from] == true) {
				connected = true;	
			}					   
		}
	}

	return connected;
}

void testCase::printResult()
{
	bool result;
	for(int i = 0; i < (int)mQuery.size(); i++) {
		result = checkLinkedNode(mQuery[i].first, mQuery[i].second);
		if(result)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	int caseNum;
	gFS.open("A-small.in", fstream::in);
	// gFS.open("input.in", fstream::in);
	gFS >> caseNum;
	if(caseNum < 1) {
		cout << "Wrong Case Number" << endl;
		exit(-1);
	}

	testCase* myTest = new testCase[caseNum];
	for(int i = 0; i < caseNum; i++) {
		myTest[i].readData();
	}

	for(int i = 0; i < caseNum; i++) {		
		myTest[i].makeGraph();
		myTest[i].printResult();
	}	

	gFS.close();
	delete[] myTest;
	return 0;
}

