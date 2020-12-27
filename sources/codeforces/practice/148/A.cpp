#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if(y == 0) return x;
    return gcd(x, x % y);
}

int main(int argc, char *argv[])
{
    int k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;

    int ans = 0;
    int arr[] = {k, l, m, n};
    for(int i = 0; i < 4; ++i)
    {
        ans += d / arr[i];
        int j = i - 1;

        if(j < 0) continue;
        if(max(arr[i], arr[j]) % min(arr[i], arr[j]) == 0) continue;

        int overlap = d / max(arr[i], arr[j]);
        cout << arr[i] << " and " << arr[j] << " overlap " << overlap << endl;
        ans -= overlap;
    }
    cout << ans << endl;
}
