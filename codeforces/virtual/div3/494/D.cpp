#include <bits/stdc++.h>
using namespace std;

int bit_index(long long x)
{
    for(int i = 0; i < 32; ++i)
    {
        if((1ll << i) & x) return i;
    }
    return -1;
}

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    long long coins[32] = {};
    for(int i = 0; i < n; ++i)
    {
        long long x; cin >> x;
        coins[bit_index(x)]++;
    }

    for(int i = 0; i < q; ++i)
    {
        long long x; cin >> x;

        int num = 0;

        bool valid = true;
        long long b1 = 31;
        long long b2 = 31;

        long long c[32] = {};
        for(int i = 0; i < 32; ++i) c[i] = coins[i];

        while(x > 0)
        {
            while(b1 >= 0 && !((1ll << b1) & x)) --b1;
            while(b2 >= 0 && (c[b2] == 0 || b2 > b1)) { --b2; }

            if(b2 < 0)
            {
                valid = false;
                break;
            }

            long long use = min(c[b2], (1ll << b1) / (1ll << b2));
            num += use;
            c[b2] -= use;
            long long amount = (1ll << b2) * use;
            x -= amount;
        }

        if(valid)
        {
            cout << num << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
}
