#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i = 0; i < m; ++i) dp[0][i] = 1;
    for(int i = 0; i < n; ++i) dp[i][0] = 1;

    for(int i = 1; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            // last a rows
            if(!(i - 1 >= n - a && j < b)) {
                dp[i][j] = dp[i - 1][j];
            }

            if(j - 1 >= 0 && !(i >= n - a && j - 1 < b)) {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }

    cout << dp.back().back() << endl;
}
