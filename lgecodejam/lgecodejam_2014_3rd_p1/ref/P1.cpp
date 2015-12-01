/*
* author: Alex Matyzhonok (alex.matyzhonok@lge.com)
 * Compile: g++ P1.cpp -o p1
 */


#include <vector>
#include <fstream>
#include <iostream>

const static long rootNode = 1;
const static long nullNode = 0;

bool checkpath(std::vector<unsigned long>& g, long n1, long n2)
{
    while (n1 != rootNode && n1 != n2 && n1 != nullNode)
        n1 = g[n1 - 1];
    return n1 == n2;
}

int main(int argc, char** argv)
{
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cout << "can not open input.txt" << std::endl;
        return 1;
    }
    std::ofstream out("output.txt");
    if (!out.is_open()) {
        std::cout << "can not open output.txt" << std::endl;
        return 1;
    }
    unsigned long T;
    input >> T;

    for (unsigned long long j = 0; j < T; ++j) {
        std::cout << "new data" << std::endl;
        unsigned long N;
        unsigned long M;
        input >> N;
        input >> M;

        std::vector<unsigned long> g;
        g.resize(N, 0);

        for (unsigned long i = 0; i < N - 1; ++i) {
            unsigned long parent, child;
            input >> parent;
            if (input.eof()) return 2;
            input >> child;
            if (input.eof()) return 2;
            g[child - 1] = parent;
        }
        for (unsigned long i = 0; i < M; ++i) {
            unsigned long n1, n2;
            input >> n1;
            if (input.eof()) return 2;
            input >> n2;
            if (input.eof()) return 2;
            if (checkpath(g, n1, n2) || checkpath(g, n2, n1))
                out << 1 << std::endl;
            else out << 0 << std::endl;
        }
    }



    return 0;
}
