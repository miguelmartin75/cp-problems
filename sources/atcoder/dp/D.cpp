#include <iostream>
#include <vector>
#include <limits>
using namespace std;

using ll = long long;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, w;
    cin >> n >> w;

    vector<pair<ll, ll>> items(n);
    for(auto& item : items) cin >> item.first >> item.second;

    vector<vector<ll>> dp(n, vector<ll>(w + 1, numeric_limits<ll>::min()));

    ll maxValue = numeric_limits<ll>::min();
    for(int j = 0; j <= w; ++j) {
        dp[0][j] = j - items[0].first >= 0 ? items[0].second : 0;
        maxValue = max(maxValue, dp[0][j]);
    }

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j <= w; ++j) {
            dp[i][j] = dp[i - 1][j];

            int newW = j - items[i].first;
            if(newW >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][newW] + items[i].second);
            }

            maxValue = max(maxValue, dp[i][j]);
        }
    }

    cout << maxValue << '\n';
}
