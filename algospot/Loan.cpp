#include <iostream>

double balance(double amount, int duration, double rate, double monthlyPayment)
{
    double balance = amount;
    for (int i = 0; i < duration; i++) {
        balance *= ( 1.0 + rate/12.0/100);
        balance -= monthlyPayment;
    }
    return balance;
}

double payment(double amount, int duration, double rate)
{
    double lo = 0, hi = amount;
    for ( int i = 0; i < 100; i++) {
        double mi = (lo + hi)/2;
        if (balance(amount, duration, rate, mi) < 0)
            hi = mi;
        else
            lo = mi;
    }
    return (hi+lo)/2;
}

int main()
{
    using namespace std;
    cout<<payment(70000000, 36, 2);
    return 0;
}
