#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;

    vector<pair<ll, ll>> items(n);
    for(auto& item : items) cin >> item.first >> item.second;

    const int MAX_VALUE = 100000;

    vector<vector<ll>> dp(n, vector<ll>(MAX_VALUE + 1, numeric_limits<ll>::max()));
    dp[0][items[0].second] = items[0].first;
    dp[0][0] = 0;

    int maxValue = dp[0][items[0].second] <= w ? items[0].second : 0;

    for(int i = 1; i < n; ++i) {
        for(int v = 0; v <= MAX_VALUE; ++v) {
            dp[i][v] = dp[i - 1][v];

            if(v - items[i].second < 0) {
                continue;
            }

            ll prev = dp[i - 1][v - items[i].second];
            if(prev == numeric_limits<ll>::max()) {
                continue;
            }

            dp[i][v] = min(dp[i][v], items[i].first + prev);

            if(dp[i][v] <= w) {
                maxValue = max(maxValue, v);
            }
        }
    }

    cout << maxValue << '\n';
}
