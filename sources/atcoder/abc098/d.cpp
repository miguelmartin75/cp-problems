#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main(int argc, char *argv[]) {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll n; cin >> n;
    vector<ll> a(n); for(ll& x : a) cin >> x;

    ll s = 0;
    ll x = 0;
    ll ans = 0;

    ll l = 0;
    for(ll r = 0; r < n; ++r) {
        s += a[r];
        x ^= a[r];
        while(l < r && s != x) {
            s -= a[l];
            x ^= a[l];
            ++l;
        }

        ans += r - l + 1;
    }
    cout << ans << endl;
}
