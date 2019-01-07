#include <bits/stdc++.h>
using namespace std;

int areas[10000+1] = {};

int cakes(int n)
{
    for(int i = 1; i <= n; ++i)
    {
        if(areas[i] != 0) continue;

        areas[i] = INT_MAX;
        // loop through coins
        for(int j = 1; j * j <= i; ++j)
        {
            int coin = j * j;
            areas[i] = min(areas[i], areas[i - coin] + 1);
        }
    }
    return areas[n];
}

int main(int argc, char *argv[])
{
    int t;
    cin >> t;

    for(int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        cout << "Case #" << i + 1 << ": " << cakes(n) << '\n';
    }
    cout << flush;
}
