#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k; cin >> n >> k;

    vector<int> h(n);
    for(int& x : h) cin >> x;


    vector<int> dp(n, numeric_limits<int>::max());
    dp[n - 1] = 0;

    for(int i = n - 2; i >= 0; --i) {
        for(int j = 1; j <= k && i + j < n; ++j) {
            dp[i] = min(dp[i], dp[i + j] + abs(h[i] - h[i + j]));
        }
    }

    cout << dp[0] << '\n';
}
