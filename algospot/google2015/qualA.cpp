#include <iostream>
#include <fstream>

#define SMAX 1000

using namespace std;

int get_audience(int h, char *aud) {
        int stand = aud[0]-'0';
            int res = 0;
                for (int i = 1; i <= h; i++) {
                            if(stand+res < i) {
                                            res = i-stand;
                                                    }
                                                            stand += aud[i]-'0';
                                                                }
                                                                    return res;
}

int main()
{
        ifstream in;
            ofstream out;
                int C;
                    int high_level;
                        char num_people[SMAX];

                            in.open("small.in");
                                out.open("small.out");
                                    in>>C;
                                        for (int i = 0; i < C; i++) {
                                                    in>>high_level;
                                                            out<<"Case #"<<i+1<<": ";
                                                                    for (int j = 0; j <= high_level; j++) {
                                                                                    in>>num_people[j];
                                                                                                cout<<num_people[j]<<" ";
                                                                                                        }
                                                                                                                out<<get_audience(high_level, num_people)<<endl;
                                                                                                                    }
                                                                                                                        in.close();
                                                                                                                            out.close();
                                                                                                                                return 1;
}

