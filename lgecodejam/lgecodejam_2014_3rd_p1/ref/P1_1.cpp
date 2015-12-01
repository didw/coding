//============================================================================
// Name        : HelloWorld.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
int reverseScan(vector<int> v, int from, int to){

	if(to == 1 || from ==1)
		return 1;

	while(from != 0){
		if(from == to){
			return 1;
		}
		from = v[from];
	}

	return 0;
}
*/
int main(int argc,  char* argv[]) {
	string filename="A-large.in";

	if(argc > 1){
		filename = argv[1];
	}
	ifstream file(filename.c_str());
	string str;
	int total;
	file >> total;
	int N, M;
//	int totalM =0;
	for(int i=0; i < total; i++)
	{

		file >> N >> M;

		int parentId, childId;

		vector<int> v(N+1);

		for(int j=0; j < N-1; j++ ){
			file >> parentId >> childId;
			v[childId] = parentId;

		}

		for(int j=0; j < M; j++){
			int one, two;
			file >> one >> two;

			int result = 0;

			if(one == 1 || two ==1){
				result = 1;
			}
			else{
				int from = one;
				int to = two;

				while(1){
					if(from ==0 && to ==0)
						break;
					if(from !=0){
						if(from == two){
							result =1;
							break;
						}
						from = v[from];
					}
					if(to != 0){
						if(to == one){
							result =1;
							break;
						}
						to = v[to];
					}

				}
			}

			cout << result << endl;
/*
			int result = reverseScan(v,two,one);
			if(!result)
				result = reverseScan(v,one,two);
*/
//			cout << ++totalM  << endl;

		}



	}
	return 0;
}
