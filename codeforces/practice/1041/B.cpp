#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[])
{
    ll a, b, x, y;
    cin >> a >> b >> x >> y;

    ll c = gcd(x, y);
    x /= c;
    y /= c;

    cout << min(a / x, b / y) << endl;
}
