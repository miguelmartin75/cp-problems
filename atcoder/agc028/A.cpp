#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a % b);
}

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    ll lcm = (n*m) / gcd(max(n, m), min(n, m));

    int i = 0;
    while(i < n || i < m) {
        ll idx1 = i*(lcm/n);
        ll idx2 = i*(lcm/m);

        bool valid = true;

        if(idx1 % (lcm/m) == 0) {
            int j = idx1 / (lcm/m);
            if(i < n && j < m && s[i] != t[j]) valid = false;
        }

        if(idx2 % (lcm/n) == 0) {
            int j = idx2 / (lcm/n);
            if(i < m && j < n && t[i] != s[j]) valid = false;
        }

        if(!valid) {
            cout << -1 << '\n';
            return 0;
        }

        ++i;
    }

    cout << lcm << '\n';
}
