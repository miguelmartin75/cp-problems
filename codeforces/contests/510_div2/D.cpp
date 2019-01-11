#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll t;
    cin >> n >> t;

    vector<ll> a(n);
    vector<ll> cum(n);
    for(int i = 0; i < n; ++i) { 
        cin >> a[i];
        cum[i] = a[i];
        if(i != 0) cum[i] += cum[i - 1];
    }


    int start = -1;
    stack<int> starts;

    vector<int> increasing;
    ll total = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] >= t) {
            starts.push(i);
            start = i;
            continue;
        }

        if(a[i] < 0) {
            int val = a[i];
            while(!starts.empty() && val < 0 && val + a[start] >= 0) {
                val += a[start];
                starts.pop();
                start = starts.empty() ? 0 : starts.top();
            }
        }

        if(increasing.empty()) {
        }

        ll removeStart = start >= 0 ? cum[start] : 0;

        if(cum[i] - removeStart < t) {
            total += i - start;
        } else {
            ll remove = cum[i] - t;
            auto it = upper_bound(cum.begin(), cum.end(), remove);
            int index = distance(cum.begin(), it);
            if(index >= i) continue;

            total += i + 1;
            total -= index + 1;
        }
    }

    cout << total << '\n';
}
