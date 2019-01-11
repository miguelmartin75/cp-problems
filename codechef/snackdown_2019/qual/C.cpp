#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        ll n; 
        cin >> n;

        vector<ll> a(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(i - 1 >= 0) {
                a[i] += a[i - 1];
            }
        }

        int c = 0;
        ll j = 1;
        while(j < n) {
            c++;
            j += a[j - 1];
        }

        cout << c << '\n';
    }
}
