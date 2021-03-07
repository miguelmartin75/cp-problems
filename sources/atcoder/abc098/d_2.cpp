#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    cin.sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); for(int& x : a) cin >> x;

    vector<vector<int>> dp(n, vector<int>(21, 0));

    cout << "dp[0] = ";
    for(int b = 0; b <= 20; ++b) {
        if((a[0] & (1 << b)) == 0) dp[0][b] = 1;
        cout << dp[0][b] << ' ';
    }
    cout << endl;

    int sMax = 1;
    for(int i = 1; i < n; ++i) {
        int m = 0;
        cout << a[i] << endl;
        cout << "dp[" << i << "] = ";
        for(int b = 0; b <= 20; ++b) {
            if((a[i] & (1 << b)) == 1) { cout << 0 << ' '; dp[i][b] = 0; continue; }
            for(int x = 0; x <= 20; ++x) {
                if(x == b) continue;
                if((a[i] & (1 << x)) != 0) continue;

                dp[i][b] = max(dp[i][b], dp[i - 1][x] + 1);
            }

            cout << dp[i][b] << ' ';
            m = max(sMax, dp[i][b]);
        }

        cout << endl;
        sMax += m;
    }
    cout << sMax << endl;
}
