#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll M = 1e9 + 7;

ll add(ll x, ll y)
{
    return ((x % M) + (y % M)) % M;
}

ll mult(ll x, ll y)
{
    return ((x % M) * (y % M)) % M;
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    vector<int> dp(2, 1); // n = 1
    dp[1] = 0;

    vector<int> curr(4);
    for(int i = 2; i <= n; ++i)
    {
        for(int d = 0; d <= 1; ++d)
        {
            curr[d] = add(dp[!d], mult(2, dp[0]));
        }

        swap(curr, dp);
    }

    cout << dp[1] << endl;
}
