#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll MOD = 1e9 + 7;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        vector<int> a(n);
        map<int, int> counts;
        for(int& x : a) { cin >> x; counts[x]++; }

        sort(a.rbegin(), a.rend());

        ll result = 1;
        
        int j = 1;
        while(j < n - 2) {
            if(a[j] == a[j - 1] && counts[a[j]] % 2 == 0) {
                counts[a[j]]--;
            }

            int c = counts[a[j]];

            result *= c;
            result %= MOD;

            counts[a[j - 1]]--;
            counts[a[j]]--;

            j += 2;
        }

        cout << result << '\n';
    }
}
