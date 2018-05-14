#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[])
{
    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int ai = 0;
    long long offset = 0;
    for(int i = 0; i < m; ++i)
    {
        long long x;
        cin >> x;

        while(!(x >= offset && x <= offset + a[ai]))
        {
            offset += a[ai];
            ai++;
        }

        long long r = x - offset;

        cout << ai + 1 << ' ' << r << endl;
    }
}
