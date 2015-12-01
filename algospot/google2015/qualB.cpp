#include <iostream>
#include <fstream>
#include <vector>

#define SMAX 1000

using namespace std;

int get_plate(int d, vector<short> p) {
        vector<short> pp;
            short max = 0;
                int d_next = 0;
                    int res = INT_MAX;
                        for (int i = 0; i < d; i++) {
                                    cout<<p[i]<<" ";
                                        }
                                            cout<<endl;
                                                for (int i = 0; i < d; i++) {
                                                            if (p[i] - 1 > 0) {
                                                                            pp.push_back(p[i]-1);
                                                                                        d_next++;
                                                                                                }
                                                                                                        if (max<p[i])
                                                                                                                        max = p[i];
                                                                                                                            }
                                                                                                                                if (d_next == 0)
                                                                                                                                            return 1;
                                                                                                                                                if (max == 1)
                                                                                                                                                            return 1;
                                                                                                                                                                for (int i = 0; i < d; i++) {
                                                                                                                                                                            if (max == p[i]) {
                                                                                                                                                                                            p.erase(p.begin()+i);
                                                                                                                                                                                                        break;
                                                                                                                                                                                                                }
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                        for (int i = 1; i < max; i++) {
                                                                                                                                                                                                                                    p.push_back(i);
                                                                                                                                                                                                                                            p.push_back(max-i);
                                                                                                                                                                                                                                                    res = min(res, min(get_plate(d_next, pp), get_plate(d+1, p)) + 1);
                                                                                                                                                                                                                                                            p.pop_back();
                                                                                                                                                                                                                                                                    p.pop_back();
                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                            return res;
}

int main()
{
        ifstream in;
            ofstream out;
                int C;
                    int D;
                        vector<short> P;

                            in.open("small.in");
                                out.open("small.out");
                                    in>>C;
                                        for (int i = 0; i < C; i++) {
                                                    in>>D;
                                                            out<<"Case #"<<i+1<<": ";
                                                                    for (int j = 0; j < D; j++) {
                                                                                    short input;
                                                                                                in>>input;
                                                                                                            P.push_back(input);
                                                                                                                    }
                                                                                                                            out<<get_plate(D, P)<<endl;
                                                                                                                                }
                                                                                                                                    in.close();
                                                                                                                                        out.close();
                                                                                                                                            return 1;
}

