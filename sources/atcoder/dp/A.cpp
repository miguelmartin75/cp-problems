#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; cin >> n;

    vector<int> h(n);
    for(int& x : h) cin >> x;


    vector<int> dp(n);
    dp[n - 1] = 0;

    for(int i = n - 2; i >= 0; --i) {
        dp[i] = dp[i + 1] + abs(h[i] - h[i+1]);
        if(i + 2 < n) {
            dp[i] = min(dp[i], dp[i + 2] + abs(h[i] - h[i + 2]));
        }
    }

    cout << dp[0] << '\n';
}
