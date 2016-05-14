https://www.codingame.com/ide/4205679a66e4cb0695741a31b3919ff95ab2cb4
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


const int N = 43;
string animals[] = {"Rabbits", "Chickens", "Cows", "Pegasi", "Demons"};
int aniOrder[5] = {-1,};
string partsName[] = {"Heads", "Horns", "Legs", "Wings", "Eyes"};
//int animalHas[5][5] = {{1, 0, 4, 0, 2}, {1, 0, 2, 2, 2}, {1, 2, 4, 0, 2}, {1, 0, 4, 2, 2}, {1, 4, 4, 2, 4}};
int animalHas[5][5] = {{1, 0, 2, 0, 1}, {1, 0, 1, 1, 1}, {1, 1, 2, 0, 1}, {1, 0, 2, 1, 1}, {1, 2, 2, 1, 2}};
bool animalKinds[5] = {false,};
bool partKinds[5] = {false,};
bool DEBUG_PRINT = false;
//vector<short> cache[N][N][N][N][N];
char cache[N][N][N][N][N][5];

bool isZero(vector<int> &parts) {
	for (int i = 0; i < parts.size(); ++i) {
		if (!partKinds[i]) continue;
		if (parts[i] != 0) return false;
	}
	return true;
}

char* solve(vector<int> &parts) {

	if (DEBUG_PRINT) {
		for (int i = 0; i < 5; ++i) {
			cout << partsName[i] << " " << parts[i] << endl;
		}
		cout << endl;
	}

	for (int i = 0; i < parts.size(); ++i) {
		if (!partKinds[i]) continue;
		if (parts[i] < 0) {
			char *ret = new char[5];
			for (int j = 0; j < 5; ++j)
				ret[j] = -10;
			return ret;
		}
	}
	if (isZero(parts)) {
		char *ret = new char[5];
		for (int j = 0; j < 5; ++j)
			ret[j] = 0;
		return ret;
	}

	char *res = new char[5];
	if (parts[0] < N && parts[1] < N && parts[2] < N && parts[3] < N && parts[4] < N) {
		for (int i = 0; i < 5; ++i)
			res[i] = cache[parts[0]][parts[1]][parts[2]][parts[3]][parts[4]][i];
		if (res[0] != -1) return res;
	}
	for (int i = 0; i < 5; ++i)
		res[i] = -10;

	for (int i = 0; i < 5; ++i) {
		if (!animalKinds[i]) continue;
		for (int j = 0; j < 5; ++j) {
			if (!partKinds[j]) continue;
			parts[j] -= animalHas[i][j];
		}
		char* aniCount = solve(parts);

		if (DEBUG_PRINT) {
			for (int j = 0; j < 5; ++j) {
				cout << animals[j] << " " << aniCount[j] << endl;
			}
			cout << endl;
		}

		if (aniCount[0] >= 0) {
			delete(res);
			aniCount[i]++;
			for (int i = 0; i < 5; ++i)
				cache[parts[0]][parts[1]][parts[2]][parts[3]][parts[4]][i] = aniCount[i];
			return aniCount;
		}
		else {
			delete(aniCount);
		}

		for (int j = 0; j < 5; ++j) {
			if (!partKinds[j]) continue;
			parts[j] += animalHas[i][j];
		}
	}

	if (parts[0] < N && parts[1] < N && parts[2] < N && parts[3] < N && parts[4] < N) {
		for (int i = 0; i < 5; ++i)
			cache[parts[0]][parts[1]][parts[2]][parts[3]][parts[4]][i] = res[i];
	}
	return res;
}

void initializeCache() {
	memset(cache, -1, sizeof(cache));
	return;
}

int main()
{
    int N;
    vector<int> parts(5, 0);

    initializeCache();
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string species;
        cin >> species; cin.ignore();
        int j = 0;
        while(animals[j] != species) j++;
        animalKinds[j] = true;
        aniOrder[i] = j;
    }
    for (int i = 0; i < N; i++) {
        string thing;
        int number;
        cin >> thing >> number; cin.ignore();
        int j = 0;
        while(partsName[j] != thing) j++;
        partKinds[j] = true;
        if (j == 0)
        	parts[j] = number;
        else
        	parts[j] = number/2;
    }

    char *aniCount = solve(parts);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    int idx = 0;
    for (int i = 0; i < 5; ++i) {
    	if (!animalKinds[i]) continue;
    	int order = aniOrder[idx++];
    	cout << animals[order] << " " << int(aniCount[order]) << endl;
    }
}

