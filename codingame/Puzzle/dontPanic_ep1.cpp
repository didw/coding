#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

vector<vector<int>> board;
vector<vector<int>> dist;

int width; // width of the area

int findShortestPath(int flr, int pos) {
    if (pos >= width || pos < 0) {
        return 100000;
    }
    int& res = dist[flr][pos];
    if (res != -1) return res;
    res = 100000;
    if (board[flr][pos] == 2) {
        res = 0;
        return res;
    }
    if (board[flr][pos] == 1) {
        res = min(res, findShortestPath(flr+1, pos));
    }
    res = min(res, findShortestPath(flr, pos-1)+1);
    res = min(res, findShortestPath(flr, pos+1)+1);
    return res;
}

int main()
{
    int nbFloors; // number of floors
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    board = vector<vector<int>>(nbFloors, vector<int>(width, 0));
    dist = vector<vector<int>>(nbFloors, vector<int>(width, -1));
    board[exitFloor][exitPos] = 2;
    
    for (int i = 0; i < nbElevators; i++) {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        board[elevatorFloor][elevatorPos] = 1;
    }

    // game loop
    while (1) {
        int cloneFloor; // floor of the leading clone
        int clonePos; // position of the leading clone on its floor
        string direction; // direction of the leading clone: LEFT or RIGHT
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        
        fprintf(stderr, "clone position: %d, %d\n", cloneFloor, clonePos);
        
        if (cloneFloor == -1) {
            cout << "WAIT" << endl;
            continue;
        }
        string rightDirection;
        if (findShortestPath(cloneFloor, clonePos-1) < findShortestPath(cloneFloor, clonePos+1)) {
            rightDirection = "LEFT";
        } else {
            rightDirection = "RIGHT";
        }
        fprintf(stderr, "DIST[%d][%d] = %d\n", cloneFloor, clonePos-1, findShortestPath(cloneFloor, clonePos-1));
        fprintf(stderr, "DIST[%d][%d] = %d\n", cloneFloor, clonePos+1, findShortestPath(cloneFloor, clonePos+1));
        cerr << "rightDirection: " << rightDirection << endl;
        
        if (direction == rightDirection || board[cloneFloor][clonePos] == 1) {
            cout << "WAIT" << endl;
        } else {
            cout << "BLOCK" << endl;
        }
    }
}