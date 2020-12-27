#include <iostream>
#include <limits>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a, b, c;
    for(int i = 0; i < n; ++i) {
        int aa, bb, cc;
        cin >> aa >> bb >> cc;
        a.emplace_back(aa);
        b.emplace_back(bb);
        c.emplace_back(cc);
    }

    vector<vector<int>> dp(3, vector<int>(n, numeric_limits<int>::min()));
    dp[0].back() = a.back();
    dp[1].back() = b.back();
    dp[2].back() = c.back();

    vector<int>* abc[3] = {&a, &b, &c};
    for(int i = n - 1; i >= 0; --i) {
        for(int j = 0; j < 3; ++j) {
            for(int k = 0; k < 3; ++k) {
                if(k == j) continue;
                dp[j][i] = max(dp[j][i], (*abc[j])[i] + dp[k][i + 1]);
            }
        }
    }

    cout << max(dp[0][0], max(dp[1][0], dp[2][0])) << '\n';
}
