#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// solve first equation
vector<double> solveNaive(const vector<double>& poly) {
    vector<double> res;
    res.push_back(-poly[1] / poly[0]);
    return res;
}

vector<double> differentiate(const vector<double>& poly) {
    vector<double> res;
    for (int i = 0; i+1 < poly.size(); ++i) {
        res.push_back(poly[i] * (poly.size() - 1 - i));
    }
    return res;
}

double evaluate(const vector<double>& poly, double x0) {
    double res = 0;
    for (int i = 0; i < poly.size(); ++i) {
        res += (poly[i]*pow(x0, poly.size() - 1 - i));
    }
    return res;
}

const double L = 11;

vector<double> solve(const vector<double>& poly) {
    int n = poly.size();
    if (n <= 2) return solveNaive(poly);
    vector<double> differentiative = differentiate(poly);
    vector<double> sols = solve(differentiative);

    sols.insert(sols.begin(), -L);
    sols.insert(sols.end(), L);
    vector<double> rets;
    for (int i = 0; i+1 < sols.size(); ++i) {
        double x1 = sols[i];
        double x2 = sols[i+1];
        double y1 = evaluate(poly, x1);
        double y2 = evaluate(poly, x2);
        if (y1 * y2 > 0) continue;
        if (y1 > y2) {
            swap(x1, x2);
            swap(y1, y2);
        }
        for (int it = 0; it < 100; ++it) {
            double xm = (x1 + x2) / 2;
            double ym = evaluate(poly, xm);
            if (ym > 0)
                x2 = xm;
            else
                x1 = xm;
        }
        rets.push_back(x1);
    }
    sort(rets.begin(), rets.end());
    return rets;
}

int main() {
    int c;
    cin >> c;
    while (c--) {
        int n;
        cin >> n;
        vector<double> poly;
        for (int i = 0; i <= n; ++i) {
            double a;
            cin >> a;
            poly.push_back(a);
        }
        vector<double> sol = solve(poly);
        for (int i = 0; i < sol.size(); ++i) {
            printf("%.10f ", sol[i]);
        }
        cout << endl;
    }
}
