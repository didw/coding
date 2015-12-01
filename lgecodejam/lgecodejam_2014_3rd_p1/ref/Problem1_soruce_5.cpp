
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>

using namespace std;


typedef struct
{
	int pId;
	int cId;
}PC_PAIR_T;

int MakePair(ifstream &fpin, PC_PAIR_T *pcPair , int nrEdge);
void IterateProcess(ifstream &fpin, ofstream &fpout);
void FindResult(PC_PAIR_T *pcPair, pair <int,int> *question , int *result , int nrQuestion);
void swap(int &a , int &b);
int FpCmpChild(const void *a , const void *b);
inline bool CheckConn(PC_PAIR_T *pcPair, int q1 , int q2);

int main()
{
	ifstream fpin;
	ofstream fpout;
	int nrTc;

	fpin.open("input.txt");
	fpout.open("output.txt");

	if(!fpin.is_open())
	{
		cout << " Fail to open file." << endl;
		return -1;
	}
	fpin >> nrTc;

	for(int i = 0 ; i < nrTc ; i++)
	{
		if(i == nrTc -1)
		{
			cout << "a" ;
		}
		IterateProcess(fpin, fpout);
	}
	cout << "All Done.." << endl;
	return 0;
}

void IterateProcess(ifstream &fpin, ofstream &fpout)
{
	int nrEdge , nrQuestion;
	PC_PAIR_T *pcPair;
	pair <int,int> *question;
	int *result;

	fpin >> nrEdge >> nrQuestion ;

	cout << nrEdge << " , " << nrQuestion << endl;

	pcPair = new PC_PAIR_T [nrEdge -1];

	MakePair(fpin , pcPair , nrEdge-1);

	question = new pair <int , int> [nrQuestion];
	result = new int [nrQuestion];

	for(int i = 0 ; i < nrQuestion ; i++)
	{
		fpin >> question[i].first >> question[i].second ;
	}
	FindResult(pcPair , question , result , nrQuestion);

	for(int i = 0 ; i < nrQuestion ; i++)
	{
		fpout << result[i] << endl;
	}
	delete [] question;
	delete [] result;
	delete [] pcPair;
}

int MakePair(ifstream &fpin, PC_PAIR_T *pcPair , int nrEdge)
{
	for(int i = 0 ; i < nrEdge ; i++)
	{
		fpin >> pcPair[i].pId >> pcPair[i].cId;
	}
	qsort(pcPair , nrEdge , sizeof(PC_PAIR_T) , FpCmpChild);
	return 0;
}

int FpCmpChild(const void *a , const void *b)
{
	PC_PAIR_T *tmpA = (PC_PAIR_T *)a;
	PC_PAIR_T *tmpB = (PC_PAIR_T *)b;

	return (tmpA->cId - tmpB->cId);
}


void FindResult(PC_PAIR_T *pcPair , pair <int,int> *question , int *result , int nrQuestion)
{
	for(int i = 0 ; i < nrQuestion ; i++)
	{
		int q1 = question[i].first;
		int q2 = question[i].second;

		if(q1 < 2 || q2 < 2)
		{
			result[i] = 1;
			cout << "q1 , q2 is less then2 : " << q1 << " " << q2 << endl;
			continue;
		}
		if(CheckConn(pcPair , q1, q2))
		{
			result[i] = 1;
		}
		else
		{
			result[i] = 0;
		}
	}
}

bool CheckConn(PC_PAIR_T *pcPair, int q1 , int q2)
{
	int q1Bk = q1;
	int q2Bk = q2;

	while(q1 != 1 || q2 != 1)
	{
		if(q1 != 1)
			q1 = pcPair[q1-2].pId;
		if(q2 != 1)
			q2 = pcPair[q2-2].pId;

		if(q1 == q2Bk) return true;
		if(q2 == q1Bk) return true;
	}
	return false;
}