#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdio>
using namespace std;

vector<vector<int> > longest;
vector<int> backtracking;

vector<vector<int> > makeBoard(int N) {
    vector<int> num(N*N);
    vector<vector<int> > board(N, vector<int>(N));
    for (int i = 0; i < N*N; ++i)
        num[i] = i + 1;

    random_shuffle(num.begin(), num.end());

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            board[i][j] = num[N*i + j];

    return board;
}

void solve(vector<vector<int> > &board) {
    int N = board.size();
    for (int num = 1; num <= N*N; ++num) {
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                if (board[y][x] == num) {
                    int here = board[y][x];
                    if (y > 0 && board[y - 1][x] == here - 1) {
                        longest[y][x] = max(longest[y][x], longest[y - 1][x] + 1);
                        backtracking[y*N + x] = (y - 1)*N + x;
                    }
                    if (y < N - 1 && board[y + 1][x] == here - 1) {
                        longest[y][x] = max(longest[y][x], longest[y + 1][x] + 1);
                        backtracking[y*N + x] = (y + 1)*N + x;
                    }
                    if (x > 0 && board[y][x - 1] == here - 1) {
                        longest[y][x] = max(longest[y][x], longest[y][x - 1] + 1);
                        backtracking[y*N + x] = y*N + x - 1;
                    }
                    if (x < N - 1 && board[y][x + 1] == here - 1) {
                        longest[y][x] = max(longest[y][x], longest[y][x + 1] + 1);
                        backtracking[y*N + x] = y*N + x + 1;
                    }
                }
            }
        }
    }
}

void PrintTracing(int y, int x, vector<vector<int> > &board) {
    int N = board.size();
    int here = y*N + x;
    vector<int> tracking;
    tracking.push_back(board[here / N][here%N]);
    while (backtracking[here] != -1) {
        here = backtracking[here];
        tracking.push_back(board[here / N][here%N]);
    }
    for (int i = tracking.size() - 1; i >= 0; --i) {
        cout << tracking[i];
        if (i != 0) cout << " - ";
    }
    cout << endl;
}

void pathFromRandomMatrix(int N) {
    vector<vector<int> > board = makeBoard(N);
    longest = vector<vector<int> >(N, vector<int>(N, 1));
    backtracking = vector<int>(N*N, -1);

    cout << endl << "Matrix is generated in random" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (N*N > 100) {
                printf("%4d", board[i][j]);
            }
            else if (N*N > 10) {
                printf("%3d", board[i][j]);
            }
            else {
                printf("%2d", board[i][j]);
            }
        }
        cout << endl;
    }

    int res = 0;
    pair<int, int> cand;
    solve(board);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (res < longest[i][j]) {
                res = longest[i][j];
                cand.first = i;
                cand.second = j;
            }
        }
    }
    cout << endl << "Longest Length: " << res << endl << endl;
    int y = cand.first;
    int x = cand.second;
    cout << "Tracing:" << endl;
    PrintTracing(cand.first, cand.second, board);
}

void pathFromGivenMatrix(vector<vector<int> > &board) {
    int N = board.size();
    longest = vector<vector<int> >(N, vector<int>(N, 1));
    backtracking = vector<int>(N*N, -1);

    solve(board);
    int res = 0;
    pair<int, int> cand;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (res < longest[i][j]) {
                res = longest[i][j];
                cand.first = i;
                cand.second = j;
            }
        }
    }
    cout << endl << "Longest Length: " << res << endl;
    int y = cand.first;
    int x = cand.second;
    cout << "Tracing:" << endl;
    PrintTracing(cand.first, cand.second, board);
}

int input1() {
    int n;
    cin >> n;
    return n;
}

vector<vector<int> > input2() {
    cout << "choose dimension first: ";
    int N;
    cin >> N;

    cout << "Please insert matrix values" << endl;
    cout << "ex)" << endl;
    vector<vector<int> > board = makeBoard(N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (N*N > 100) {
                printf("%4d", board[i][j]);
            }
            else if (N*N > 10) {
                printf("%3d", board[i][j]);
            }
            else {
                printf("%2d", board[i][j]);
            }
        }
        cout << endl;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> board[i][j];
        }
    }

    return board;
}

int main() {
    srand(time(0));
    //srand(100); to make debug easy
    while (1) {
        cout << "Choose menu: (1: pathFromRandomMatrix, 2: pathFromGivenMatrix, 0: exit)";
        int menu;
        int N;
        vector<vector<int> > board;
        cin >> menu;
        switch (menu) {
        case 0:
            exit(1);
        case 1:
            cout << "insert dimension: ";
            N = input1();
            pathFromRandomMatrix(N);
            break;
        case 2:
            board = input2();
            pathFromGivenMatrix(board);
            break;
        default:
            cout << "Sorry, the menu is incorrect, Please choose again.." << endl;
        }
    }
    return 0;
}

