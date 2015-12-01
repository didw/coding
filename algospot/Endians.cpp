#include <iostream>
//#define __DEBUG

using namespace std;

int main()
{
    int C;
    cin>>C;
    while (C--)
    {
        unsigned int converted_number=0, origin_number;
        cin>>origin_number;
        for (int i = 0; i < 4; i++)
        {
            converted_number = converted_number<<8;
            converted_number += origin_number & 0x000000ff;
#ifdef __DEBUG
            cout<<converted_number<<" "<<origin_number<<endl;
#endif
            origin_number = origin_number>>8;
        }
        cout<<converted_number<<endl;
    }
}
