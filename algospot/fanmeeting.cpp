#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void normalize(vector<int>& num) {
    num.push_back(0);
    for (int i = 0; i < num.size()-1; ++i) {
        if (num[i] < 0) {
            int borrow = (abs(num[i])+9)/10;
            num[i+1] -= borrow;
            num[i] += borrow*10;
        }
        else {
            num[i+1] += num[i]/10;
            num[i] %= 10;
        }
    }
    while(num.size() > 1 && num.back()==0) num.pop_back();
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
    vector<int> c(a.size() + b.size(), 0);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0; j < b.size(); ++j) {
            c[i+j] += a[i] * b[j];
        }
    }
    //normalize(c);
    return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) {
    for (int i = a.size(); i <= b.size() + k; ++i) {
        a.push_back(0);
    }
    for (int i = 0; i < b.size(); ++i) {
        a[i+k] += b[i];
    }
    //normalize(a);
}

void subFrom(vector<int>& a, const vector<int>& b) {
    for (int i = a.size(); i <= b.size(); ++i) {
        a.push_back(0);
    }
    for (int i = 0; i < b.size(); ++i) {
        a[i] -= b[i];
    }
    //normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {
    int an = a.size();
    int bn = b.size();
    if (an < bn)
        return karatsuba(b, a);
    if (an==0 || bn==0)
        return vector<int>();
    if (an <= 50)
        return multiply(a, b);
    int half = an / 2;
    vector<int> a0(a.begin(), a.begin()+half);
    vector<int> a1(a.begin()+half, a.end());
    vector<int> b0(b.begin(), b.begin()+min<int>(b.size(), half));
    vector<int> b1(b.begin()+min<int>(b.size(), half), b.end());

    vector<int> c0 = karatsuba(a0, b0);
    vector<int> c2 = karatsuba(a1, b1);
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    vector<int> c1 = karatsuba(a0, b0);
    subFrom(c1, c0);
    subFrom(c1, c2);
    vector<int> res;
    addTo(res, c0, 0);
    addTo(res, c1, half);
    addTo(res, c2, 2*half);
    return res;
}


int get_hug(vector<int> hyper, vector<int> fan) {
    int ret = 0;
    vector<int> res = karatsuba(hyper, fan);
    for (int i = hyper.size() - 1; i < fan.size(); ++i) {
        if (res.size() <= i || res[i] == 0)
            ret ++;
    }
    return ret;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> hyper, fan;
        string a;
        cin >> a;
        for (int i = a.size() - 1; i >= 0; --i)
            hyper.push_back(a[i] == 'M');
        cin >> a;
        for (int i = 0; i < a.size(); ++i)
            fan.push_back(a[i] == 'M');
        cout<<get_hug(hyper, fan)<<endl;
    }
    return 0;
}
