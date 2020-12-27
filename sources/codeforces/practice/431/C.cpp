#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int add(int x, int y)
{
    return ((x % MOD) + (y % MOD)) % MOD;
}

int count(int n, int k, int d)
{
    vector<int> G(n + 1, 0);
    vector<int> F(n + 1, 0);
    F[0] = 1;
    G[0] = 0;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= k; ++j)
        {
            if(i - j >= 0)
                F[i] = add(F[i], F[i - j]);
        }

        for(int j = 1; j <= d - 1; ++j)
        {
            if(i - j >= 0)
                G[i] = add(G[i], G[i - j]);
        }

        for(int j = d; j <= k; ++j)
        {
            if(i - j >= 0)
                G[i] = add(G[i], F[i - j]);
        }
    }

    return G[n];
}

int main(int argc, char *argv[])
{
    int n, k, d;
    cin >> n >> k >> d;

    auto c = count(n, k, d);

    cout << c << endl;
}
