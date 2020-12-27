#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int res = INT_MIN;
    for(int i = 0; i < n; ++i)
    {
        int f, t;
        cin >> f >> t;

        int j = min(f - (t - k), f);
        res = max(res, j);
    }

    cout << res << endl;
}
