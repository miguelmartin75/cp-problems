#include <bits/stdc++.h>
using namespace std;

int myceil(int x, int y)
{
    return x % y == 0 ? x / y : x / y + 1;
}

int main(int argc, char *argv[])
{
    int n, m;
    cin >> n >> m;

    int left = 1;
    int right = 101;

    for(int i = 0; i < m; ++i)
    {
        int k, f;
        cin >> k >> f;

        if(f == 1)
            left = max(k, left);
        else
        {
            left = max(left, myceil(k, f));
            right = min(right, (k - 1) / (f - 1));
        }
    }

    int ans = -1;
    for(int i = left; i <= right; ++i)
    {
        int x = myceil(n, i);
        if(ans == -1) ans = x;
        if(ans != x)
        {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << ans << endl;
}
