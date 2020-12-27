#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int drinks = (k*l)/nl;
    int limes = c*d;
    int salt = p/np;

    int toasts = min(drinks, min(limes, salt)) / n;

    cout << toasts << endl;
}
