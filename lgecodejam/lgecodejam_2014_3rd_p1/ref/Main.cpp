#include "stdafx.h"
#include "../Logic/Logic.h"

using namespace std;

int main(int argc, char* argv[])
{
	streambuf* pCinBackup{ cin.rdbuf() };
	ifstream inputFile{ "A-large.in" };
	cin.rdbuf(inputFile.rdbuf());

	streambuf* pCoutBackup{ cout.rdbuf() };
	ofstream outputFile{ "A-large.out" };
	cout.rdbuf(outputFile.rdbuf());

	CLogic logic;
	int nTestCaseCount = 0;
	if (logic.ReadTestCaseCount(&nTestCaseCount))
	{
		for (int i = 0; i < nTestCaseCount; ++i)
		{
			logic.ReadTestCase();
			logic.Run();
			logic.PrintResult();
		}
	}

	cin.rdbuf(pCinBackup);
	cout.rdbuf(pCoutBackup);

	return 0;
}