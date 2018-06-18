#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> D1(2*n - 1, 0);
    vector<ll> D2(2*n - 1, 0);

    vector<ll> a(n*n, 0);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            cin >> a[i*n + j];

            int d1 = i + j;
            int d2 = i + (n - 1 - j);
            D1[d1] += a[i*n + j];
            D2[d2] += a[i*n + j];
        }


    ll w = -1;
    pair<int, int> wP{-1, -1};
    ll b = -1;
    pair<int, int> bP{-1, -1};
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
        {
            ll sum = D1[i + j] + D2[i + (n - 1 - j)] - a[i*n + j];

            ll& m = i % 2 == j % 2 ? w : b;
            auto& p = i % 2 == j % 2 ? wP : bP;
            
            if(m < sum)
            {
                m = sum;
                p = make_pair(i, j);
            }
        }

    cout << w + b << endl;
    cout << wP.first + 1 << " " << wP.second + 1 << " ";
    cout << bP.first + 1 << " " << bP.second + 1;
    cout << endl;
}
